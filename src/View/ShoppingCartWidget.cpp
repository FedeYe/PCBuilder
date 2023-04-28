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

    ShoppingCartWidget::ShoppingCartWidget(Engine::Query cQuery, Engine::ShoppingCart& default_cart, QWidget* parent) 
        : currentQuery(cQuery), shop_cart(default_cart), QWidget(parent) 
    {
        QVBoxLayout* vbox = new QVBoxLayout(this);
        vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

        vbox->addStretch();

        // griglia che rappresenta il carrello
        grid = new QGridLayout();
        grid->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QWidget* container = new QWidget();
        container->setLayout(grid);
        vbox->addWidget(container);

        renderer = new CartRenderer::Grid();  
        showCart();

        vbox->addStretch();

        QHBoxLayout* summary = new QHBoxLayout();

        total_cost = new QLabel("Costo Totale :    ");
        total_cost->setObjectName("costo totale");
        total_cost->setAlignment(Qt::AlignCenter);
        summary->addWidget(total_cost);

        QPushButton* order_input = new QPushButton(QIcon(QPixmap((":/Assets/icons/order.png"))),"Ordina");
        summary->addWidget(order_input);

        summary->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        vbox->addLayout(summary);

        //connect        
        connect(this, &ShoppingCartWidget::removedFromCart_event, this, &ShoppingCartWidget::removeFromCart);
        connect(this, &ShoppingCartWidget::componentSelected_event, this, &ShoppingCartWidget::componentSelected);
        connect(order_input, &QPushButton::clicked, this, &ShoppingCartWidget::orderMessageBox);                // click su tasto ORDER -> messagge box "ordine effettuato"
    }

    void ShoppingCartWidget::addToCart(const Component::AbstractComponent* new_component) {
        shop_cart = shop_cart.add(new_component);
        showCart();
        refreshTotalCost();
    }

    void ShoppingCartWidget::showCart() {

        while (!lookup.isEmpty()) {
            WidgetLookup info = lookup.takeLast();
            delete info.getWidget();
        }

        // Shows new data
        renderer->render(grid, shop_cart, &lookup);

        // Connects signals
        for (
                QVector<WidgetLookup>::const_iterator it = lookup.begin();
                it != lookup.end();
                it++
        ) {
            if (it->getRemoveButton()) {
                connect(it->getRemoveButton(), &QPushButton::clicked, std::bind(&ShoppingCartWidget::removedFromCart_event, this, it->getComponent()));
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

    void ShoppingCartWidget::refreshTotalCost() {
        total_cost->setText("Costo Totale : " + QString::number(shop_cart.getTotalCost()));
    }


    Engine::Query ShoppingCartWidget::getCurrentQuery() const {
        return currentQuery;
    }

    Engine::ShoppingCart& ShoppingCartWidget::getCart() const {
        return shop_cart;
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

    void ShoppingCartWidget::tryAddComponentToCart(const Component::AbstractComponent* new_component) {
        
        QString error_msg = "No Errors corrently";
        TypeIdentifier typeId;
        new_component->accept(typeId);
        /*
        if(typeId.getCompType() != 3 && typeId.getCompType() != 4) {
            // new_component è MB-CPU-RAM
            if(typeId.getCompType() == 1) {
                // new_component è MB
                const Component::CPU* p_cpu = new const Component::CPU();
                const Component::AbstractComponent* old_cpu = &*shop_cart.getAdded(p_cpu);

                const Component::RAM* p_ram = new const Component::RAM();
                const Component::AbstractComponent* old_ram = &*shop_cart.getAdded(p_ram);
                
                if(!shop_cart.areCompatible(new_component, old_cpu)) {
                    QString error_msg = "Errore di compatibilità tra motherboard e CPU scelte";
                    errorMessage(error_msg);
                    return;
                }
                if(!shop_cart.areCompatible(new_component, old_ram)) {
                    QString error_msg = "Errore di compatibilità tra motherboard e RAM scelte";
                    errorMessage(error_msg);
                    return;
                }  
            } else {
                // new_component è CPU o RAM
                const Component::MotherBoard* p_mb = new const Component::MotherBoard();
                const Component::AbstractComponent* old_mb = &*shop_cart.getAdded(p_mb);
                if(!shop_cart.areCompatible(old_mb, new_component)) {
                    if(typeId.getCompType() == 2) {
                        // new_component è CPU
                        QString error_msg = "Errore di compatibilità tra motherboard e CPU scelte";
                    } else {
                        // new_component è RAM
                        QString error_msg = "Errore di compatibilità tra motherboard e RAM scelte";
                    }
                    errorMessage(error_msg);
                    return;
                }
            }
        } // new_component è GPU-PSU oppure non ci sono problemi di compatibilità tra MB-CPU-RAM
        */
        addToCart(new_component);
        
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

    void ShoppingCartWidget::removeFromCart(const Component::AbstractComponent* component) {
        shop_cart.remove(component);
        showCart();
        refreshTotalCost();
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
