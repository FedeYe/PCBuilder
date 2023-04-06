#include "MainWindow.h"
// #include "ui_mainwindow.h"

namespace View
{

    MainWindow::MainWindow(Engine::IEngine& ricerca, QWidget *parent)
        :   QMainWindow(parent),
            has_unsaved_changes(false),
            ricerca(ricerca),
            repo(nullptr)
    {
        // Actions
        QAction* create = new QAction(
            QIcon(QPixmap((":/Assets/icons/new.svg"))),
            "New");
        create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
        QAction* open = new QAction(
            QIcon(QPixmap((":/Assets/icons/open.svg"))),
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
            "Close");
        close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
        QAction* togge_toolbar = new QAction("Toolbar");
        create_item = new QAction(
            QIcon(QPixmap((":/assets/icons/new_product.svg"))),
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
        view->addAction(togge_toolbar);   // serve a rendere visibile/non visibile la toolbar

        // toolbar
        toolbar = addToolBar("File Toolbar");
        toolbar->addAction(create);
        toolbar->addAction(open);
        toolbar->addAction(save);
        toolbar->addAction(save_as);
        toolbar->addSeparator();
        toolbar->addAction(create_item);

        // Main Panel
        QSplitter* splitter = new QSplitter(this);
        setCentralWidget(splitter);
       
        //stacked_widget = new QStackedWidget(this);
        //splitter->addWidget(stacked_widget);

        //result_widget = new ResultWidget();
        //stacked_widget->addWidget(result_widget);

        splitter->addStretch();  //sostituisce ShoppingWidget per ora
        splitter->addStretch();
        /*
        shopping_cart_widget = new ShoppingCartWidget();
        splitter->addWidget(shopping_cart_widget);
        */

        splitter->setSizes(QList<int>() << 2000 << 2000);

        // Connettere segnali
        connect(create, &QAction::triggered, this, &MainWindow::newDataset);
        connect(open, &QAction::triggered, this, &MainWindow::openDataset);
        connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
        connect(save_as, &QAction::triggered, this, &MainWindow::saveAsDataset);
        connect(close, &QAction::triggered, this, &MainWindow::close);
        connect(togge_toolbar, &QAction::triggered, this, &MainWindow::toggleToolbar);
        //  connect(shopping_cart_widget, &ShoppingCartWidget::search_MB_event, this, &MainWindow::search); // il MainWindow::search sarà collegato a 5 bottoni diversi in ShoppingCartWidget
        //  connect(shopping_cart_widget, &ShoppingCartWidget::search_CPU_event, this, &MainWindow::search);
        //  connect(shopping_cart_widget, &ShoppingCartWidget::search_GPU_event, this, &MainWindow::search);
        //  connect(shopping_cart_widget, &ShoppingCartWidget::search_PSU_event, this, &MainWindow::search);
        //  connect(shopping_cart_widget, &ShoppingCartWidget::search_RAM_event, this, &MainWindow::search);

        //connect(result_widget, &ResultWidget::previousPage, search_widget, &SearchWidget::previousComponent);         //obsoleti
        //connect(result_widget, &ResultWidget::nextPage, search_widget, &SearchWidget::nextComponent);                 //obsoleti
        //connect(result_widget, &ResultWidget::showItem, this, &MainWindow::showComponent);
        //connect(create_item, &QAction::triggered, this, &MainWindow::createComponent);
        //connect(result_widget, &ResultWidget::editItem, this, &MainWindow::editComponent);
        //connect(result_widget, &ResultWidget::deleteItem, this, &MainWindow::deleteComponent);
        //  forse qualcosa per bottone ordinamento?
        //  forse qualcosa per visualizzazione in tasti shopping cart

        //.....................TO BE CONTINUED
    }

    Item::Repository::JsonRepository* MainWindow::getRepository()
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

    //ShoppingCartWidget* MainWindow::getShoppingCartWidget()
    //{
    //    return shopping_cart_widget;
    //}

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
        repo = new Item::Repository::JsonRepository(data_mapper);
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

    void MainWindow::toggleToolbar() {
    toolbar->setVisible(!toolbar->isVisible());
    showStatus("Toolbar toggled.");
    }

    void MainWindow::showStatus(QString message)
    {
        statusBar()->showMessage(message);
    }

    /*
    void MainWindow::search(Engine::Query query)
    {
        showStatus("Running query for component \"" + QVariant(query.getType()).toString + "\".");
        results_widget->showResults(query, ricerca.search(query)); //..............W
        stacked_widget->setCurrentIndex(0);
        clearStack();
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
    */

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
