#include "ShoppingCartWidget.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <typeinfo>
//#include <>

#include "../Component/MotherBoard.h"
#include "../Component/CPU.h"
#include "../Component/GPU.h"
#include "../Component/PSU.h"
#include "../Component/RAM.h"
#include "CartRenderer/Grid.h"
#include "TypeIdentifier.h"


namespace View {

    ShoppingCartWidget::ShoppingCartWidget(Engine::Query cQuery, QWidget* parent) 
        : currentQuery(cQuery), QWidget(parent) 
    {
        QVBoxLayout* vbox = new QVBoxLayout(this);
        vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

        QLabel* AppName = new QLabel("PCBuilder");
        AppName->setObjectName("AppName");
        vbox->addWidget(AppName);

        vbox->addStretch();

        // griglia che rappresenta il carrello
        grid = new QGridLayout();
        grid->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QWidget* container = new QWidget();
        container->setLayout(grid);
        vbox->addWidget(container);

        renderer = new CartRenderer::Grid();  

        vbox->addStretch();

        QHBoxLayout* summary = new QHBoxLayout();

        total_cost = new QLabel("Costo Totale :    ");
        total_cost->setObjectName("Total");
        total_cost->setAlignment(Qt::AlignCenter);
        summary->addWidget(total_cost);

        QPushButton* order_input = new QPushButton(QIcon(QPixmap((":/Assets/icons/order.png"))),"Order");
        order_input->setObjectName("order-button");
        summary->addWidget(order_input);

        summary->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        vbox->addLayout(summary);

        //connect
        connect(this, &ShoppingCartWidget::componentSelected_event, this, &ShoppingCartWidget::componentSelected);
        connect(order_input, &QPushButton::clicked, this, &ShoppingCartWidget::orderMessageBox);                // click su tasto ORDER -> messagge box "ordine effettuato"
    }

    void ShoppingCartWidget::showCart(Engine::ShoppingCart& shop_cart) {

        while (!lookup.isEmpty()) {
            WidgetLookup info = lookup.takeLast();
            delete info.getWidget();
        }

        // Shows new data
        renderer->render(grid, shop_cart, &lookup);
        
        // Refreshes Total Cost Label
        refreshTotalCost(shop_cart);
        // Connects signals
        for (
                QVector<WidgetLookup>::const_iterator it = lookup.begin();
                it != lookup.end();
                it++
        ) {
            if (it->getRemoveButton()) {
                connect(it->getRemoveButton(), &QPushButton::clicked, std::bind(&ShoppingCartWidget::removeFromCart_event, this, it->getComponent()));
            }
            if (it->getSearchButton()) {
                connect(it->getSearchButton(), &QPushButton::clicked, std::bind(&ShoppingCartWidget::componentSelected_event, this, it->getComponent()));
            }
        }
    }

    void ShoppingCartWidget::errorMessage(QString error_msg) {
        QMessageBox msgBox;
        msgBox.setText("Warning");
        msgBox.setInformativeText(error_msg);
        msgBox.exec();
    }

    void ShoppingCartWidget::refreshTotalCost(Engine::ShoppingCart& shop_cart) {
        total_cost->setText("Costo Totale Pc: " + QString::number(shop_cart.getTotalCost()));
    }


    Engine::Query ShoppingCartWidget::getCurrentQuery() const {
        return currentQuery;
    }

    void ShoppingCartWidget::prevComponent() {
        unsigned int currentType = currentQuery.getType();
        if(currentType == 1) 
            currentQuery.setType(5); 
        else
            currentQuery.setType(currentType - 1);
        emit search_event(currentQuery);
    }           

    void ShoppingCartWidget::nextComponent() {
        unsigned int currentType = currentQuery.getType();
        if(currentType == 5) 
            currentQuery.setType(1);
        else 
            currentQuery.setType(currentType + 1);
        emit search_event(currentQuery);
    }     

    void ShoppingCartWidget::componentSelected(const Component::AbstractComponent* component) {
        TypeIdentifier typeId;
        component->accept(typeId);
        Engine::Query query(typeId.getCompType());
        currentQuery = query;
        emit search_event(currentQuery);
    }

    void ShoppingCartWidget::search() {
        emit search_event(currentQuery);
    }    

    

    void ShoppingCartWidget::orderMessageBox() {

        QMessageBox::StandardButton confirmation;
            confirmation = QMessageBox::question(
                this,
                "Concludere ordine",
                "Confermare l'ordine?",
                QMessageBox::Yes | QMessageBox::No );
            if (confirmation == QMessageBox::Yes) 
            {
                QApplication::quit();
            }
    } 

    
}
