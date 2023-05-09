#include "MainWindow.h"
// #include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QSplitter>
#include <QFileDialog>
#include <QStackedWidget>
#include <QScrollArea>

#include "EditWidget.h"
#include "../Engine/ShoppingCart.h"
#include "../Component/DataMapper/JsonFile.h"
#include "../Component/Converter/Json/Reader.h"
#include "../Component/Converter/Json/Json.h"

namespace View
{

    MainWindow::MainWindow(Engine::IEngine& ricerca, Engine::ShoppingCart& default_cart, QWidget *parent)
        : QMainWindow(parent),
          has_unsaved_changes(false),
          ricerca(ricerca),
          shop_cart(default_cart),
          repo(nullptr)
    {
        // Actions
        QAction* create = new QAction(
            QIcon(QPixmap((":/Assets/icons/new.png"))),
            "New");
        create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
        QAction* open = new QAction(
            QIcon(QPixmap((":/Assets/icons/open.png"))),
            "Open");
        open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
        QAction* save = new QAction(
            QIcon(QPixmap((":/Assets/icons/save.svg"))),
            "Save");
        save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
        QAction* save_as = new QAction(
            QIcon(QPixmap((":/Assets/icons/save_as.svg"))),
            "Save As");
        save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
        QAction* close = new QAction(
            QIcon(QPixmap((":/Assets/icons/close.svg"))),
            "Close Application");
        close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
        QAction* toggle_toolbar = new QAction("Toolbar");
        create_item = new QAction(
            QIcon(QPixmap((":/Assets/icons/new_product.svg"))),
            "Add to catalog");
        create_item->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
        create_item->setEnabled(false);

        // barra menù  (Sono le tre cose in alto a sx da prof )
        QMenu* file = menuBar()->addMenu("&File");
        file->addAction(create);
        file->addAction(open);
        file->addAction(save);
        file->addAction(save_as);
        file->addSeparator();
        file->addAction(close);

        QMenu* item_menu = menuBar()->addMenu("&Item");
        item_menu->addAction(create_item);

        QMenu* view = menuBar()->addMenu("&View");
        view->addAction(toggle_toolbar);   // serve a rendere visibile/non visibile la toolbar

        // toolbar
        toolbar = addToolBar("File Toolbar");
        toolbar->setObjectName("Toolbar");
        toolbar->addAction(create);
        toolbar->addAction(open);
        toolbar->addAction(save);
        toolbar->addAction(save_as);
        toolbar->addSeparator();
        toolbar->addAction(create_item);

        // Main Panel
        QSplitter* splitter = new QSplitter(this);
        setCentralWidget(splitter);

        Engine::Query defaultQuery;
        shopping_cart_widget = new ShoppingCartWidget(defaultQuery);
        shopping_cart_widget->setObjectName("shoppingCartWidget");
        shopping_cart_widget->showCart(shop_cart);
        splitter->addWidget(shopping_cart_widget);
        
        stacked_widget = new QStackedWidget(this);
        splitter->addWidget(stacked_widget);

        result_widget = new ResultsWidget();
        result_widget->setObjectName("resultsWidget");
        stacked_widget->addWidget(result_widget);

        splitter->setSizes(QList<int>() << 2000 << 2000);

        // Connettere segnali
        connect(create, &QAction::triggered, this, &MainWindow::newDataset);
        connect(open, &QAction::triggered, this, &MainWindow::openDataset);
        connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
        connect(save_as, &QAction::triggered, this, &MainWindow::saveAsDataset);
        connect(close, &QAction::triggered, this, &MainWindow::close);
        connect(toggle_toolbar, &QAction::triggered, this, &MainWindow::toggleToolbar);

        connect(shopping_cart_widget, &ShoppingCartWidget::search_event, this, &MainWindow::search); 

        connect(result_widget, &ResultsWidget::refreshResults, shopping_cart_widget, &ShoppingCartWidget::search);
        connect(result_widget, &ResultsWidget::refreshResults, this, &MainWindow::changeOfOrder);

        connect(result_widget, &ResultsWidget::prevComponentType, shopping_cart_widget, &ShoppingCartWidget::prevComponent);
        connect(result_widget, &ResultsWidget::nextComponentType, shopping_cart_widget, &ShoppingCartWidget::nextComponent);

        //connect(result_widget, &ResultsWidget::addComponentToCart, shopping_cart_widget, &ShoppingCartWidget::tryAddComponentToCart);
        connect(result_widget, &ResultsWidget::addComponentToCart, this, &MainWindow::addToCart);
        connect(shopping_cart_widget, &ShoppingCartWidget::removeFromCart_event, this, &MainWindow::removeFromCart);

        connect(result_widget, &ResultsWidget::showComponent, this, &MainWindow::showComponent);
        connect(create_item, &QAction::triggered, this, &MainWindow::createComponent);
        connect(result_widget, &ResultsWidget::editComponent, this, &MainWindow::editComponent);
        connect(result_widget, &ResultsWidget::deleteComponent, this, &MainWindow::deleteComponent);
    }

    Component::Repository::JsonRepository* MainWindow::getRepository()
    {
        return repo;
    }

    Engine::IEngine& MainWindow::getEngine()
    {
        return ricerca;
    }

    MainWindow& MainWindow::reloadData()
    {
        ricerca.clear();
        std::vector<Component::AbstractComponent *> catalog(repo->readAll());
        for (
            std::vector<Component::AbstractComponent *>::const_iterator it = catalog.begin();
            it != catalog.end();
            it++)
        {
            ricerca.add(*it);
        }
        return *this;
    }

    ShoppingCartWidget* MainWindow::getShoppingCartWidget()
    {
        return shopping_cart_widget;
    }

    void MainWindow::clearStack()
    {
        QWidget* widget = stacked_widget->widget(1);
        while (widget)
        {
            stacked_widget->removeWidget(widget);
            delete widget;
            widget = stacked_widget->widget(1);
        }
    }

    void MainWindow::newDataset()
    {
        QString path = QFileDialog::getSaveFileName(
            this,
            "Creates new Dataset",
            "./",
            "JSON files *.json");
        if (path.isEmpty())
        {
            return;
        }
        if (repo != nullptr)
        {
            delete repo;
        }
        Component::Converter::Json::Reader reader;
        Component::Converter::Json::Json converter(reader);
        Component::DataMapper::JsonFile data_mapper(path.toStdString(), converter);
        repo = new Component::Repository::JsonRepository(data_mapper);
        ricerca.clear();
        create_item->setEnabled(true);
        showStatus("New dataset created.");
    }

    void MainWindow::openDataset()
    {
        QString path = QFileDialog::getOpenFileName(
            this,
            "Open an already existing Dataset",
            "./",
            "JSON files *.json");
        if (path.isEmpty())
        {
            return;
        }
        if (repo != nullptr)
        {
            delete repo;
        }
        Component::Converter::Json::Reader reader;
        Component::Converter::Json::Json converter(reader);
        Component::DataMapper::JsonFile data_mapper(path.toStdString(), converter);
        repo = new Component::Repository::JsonRepository(data_mapper);
        reloadData();
        create_item->setEnabled(true);
        showStatus("Data successfully loaded from " + path + ".");
    }

    void MainWindow::saveDataset()
    {
        if (repo == nullptr)
        {
            return;
        }
        repo->store();
        has_unsaved_changes = false;
        showStatus("Dataset saved.");
    }

    void MainWindow::saveAsDataset()
    {
        QString path = QFileDialog::getSaveFileName(
            this,
            "Creates new Dataset",
            "./",
            "JSON files *.json");
        if (path.isEmpty() || repo == nullptr)
        {
            return;
        }
        repo->setPath(path.toStdString()).store();
        has_unsaved_changes = false;
        showStatus("Dataset saved as \"" + path + "\".");
    }

    void MainWindow::toggleToolbar() 
    {
        toolbar->setVisible(!toolbar->isVisible());
        showStatus("Toolbar toggled.");
    }

    void MainWindow::showStatus(QString message)
    {
        statusBar()->showMessage(message);
    }

    void MainWindow::search(Engine::Query query)
    {
        QString text = "<blank>";
        switch(query.getType()) {
            case 1:
            text = "MOTHERBOARD"; break;
            case 2:
            text = "CPU"; break;
            case 3:
            text = "GPU"; break;
            case 4:
            text = "PSU"; break;
            case 5:
            text = "RAM"; break;
            default:
            text = "<blank>"; break;
        }
        showStatus("Running query for component " + text + ".");
        result_widget->showResults(query, ricerca.search(query));
        stacked_widget->setCurrentIndex(0);
        clearStack();
    }

    void MainWindow::changeOfOrder() {
        showStatus("Changed the Order of display of currently selected components");
    }

    void MainWindow::addToCart(const Component::AbstractComponent* new_component) {
        std::string error_msg = "There are no problems";

        if(!shop_cart.tryAddComponentToCart(new_component,error_msg)) {
            QMessageBox errorMessage;
            errorMessage.setText(QString::fromStdString(error_msg));
            errorMessage.exec();
            showStatus("Failed to add chosen component to Cart");
        } else {
            shop_cart.add(new_component);
            shopping_cart_widget->showCart(shop_cart);
            showStatus("Added chosen component " + QString::fromStdString(new_component->getName()) + " to Cart");
        }
        
    }

    void MainWindow::removeFromCart(const Component::AbstractComponent* rm_this_component) {
        shop_cart.remove(rm_this_component);
        shopping_cart_widget->showCart(shop_cart);
        showStatus("Removed chosen component " + QString::fromStdString(rm_this_component->getName()) + " from Cart");
    }

    void MainWindow::createComponent()
    {
        clearStack();
        QScrollArea* scroll_area = new QScrollArea();
        scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setWidgetResizable(true);
        EditWidget* edit_widget = new EditWidget(this, repo, nullptr);
        scroll_area->setWidget(edit_widget);
        stacked_widget->addWidget(scroll_area);
        stacked_widget->setCurrentIndex(1);
        has_unsaved_changes = true;
        showStatus("Creating a new component.");
    }

    void MainWindow::showComponent(const Component::AbstractComponent *component) 
    {
        clearStack();
        component->accept(full_renderer); 
        QScrollArea* scroll_area = new QScrollArea();
        scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setWidgetResizable(true);
        scroll_area->setWidget(full_renderer.getWidget());
        stacked_widget->addWidget(scroll_area);
        stacked_widget->setCurrentIndex(1);
        showStatus("Showing component " + QString::fromStdString(component->getName()) + "."); 
    }

    void MainWindow::editComponent(const Component::AbstractComponent *component)
    {
        clearStack();
        QScrollArea* scroll_area = new QScrollArea();
        scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setWidgetResizable(true);
        EditWidget* edit_widget = new EditWidget(this, repo, component);
        scroll_area->setWidget(edit_widget);
        stacked_widget->addWidget(scroll_area);
        stacked_widget->setCurrentIndex(1);
        has_unsaved_changes = true;
        showStatus("Editing component " + QString::fromStdString(component->getName()) + ".");
    }

    void MainWindow::deleteComponent(const Component::AbstractComponent *component)
    {
        showStatus("Component " + QString::fromStdString(component->getName()) + " removed.");
        repo->remove(component->getIdentifier());
        ricerca.remove(component);
        shopping_cart_widget->search();
        has_unsaved_changes = true;
    }

    void MainWindow::close()
    {
        if (has_unsaved_changes)
        {
            QMessageBox::StandardButton confirmation;
            confirmation = QMessageBox::question(
                this,
                "Quit?",
                "There are unsaved changes.\nDo you really want to quit?",
                QMessageBox::Yes | QMessageBox::No);
            if (confirmation == QMessageBox::Yes)
            {
                QApplication::quit();
            }
        }
        else
        {
            QApplication::quit();
        }
    }
}
