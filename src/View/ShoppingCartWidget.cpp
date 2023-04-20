#include "ShoppingCartWidget.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <typeinfo>
//#include <>

#include "../Component/MotherBoard.h"
#include "../Component/CPU.h"
#include "../Component/GPU.h"
#include "../Component/PSU.h"
#include "../Component/RAM.h"

namespace View {

    ShoppingCartWidget::ShoppingCartWidget(Engine::Query cQuery, QWidget* parent) 
        : currentQuery(cQuery), QWidget(parent) 
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

        vbox->addStretch();

        QHBoxLayout* summary = new QHBoxLayout();

        total_cost = new QLabel("Costo Totale :    ");
        total_cost->setObjectName("costo totale");
        total_cost->setAlignment(Qt::AlignCenter);
        summary->addWidget(total_cost);

        QPushButton* order_input = new QPushButton(
            QIcon(QPixmap((":/assets/icons/order.png"))),
            "Ordina"
        );
        summary->addWidget(order_input);

        summary->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        vbox->addLayout(summary);

        //connect
        // connect();

        // connect(build_widget, &BuildWidget::compSelectedEvent, this, &ShoppingCartWidget::search);        selezionando una tipologia di componente da ricercare   
        
        //connect(this, &ShoppingCartWidget::addedToCart_event, this, &ShoppingCartWidget::refreshGrid);
        connect(this, &ShoppingCartWidget::addedToCart_event, this, &ShoppingCartWidget::refreshTotalCost);
        //connect(this, &ShoppingCartWidget::removedFromCart_event, this, &ShoppingCartWidget::refreshTotalCost);

        connect(this, &ShoppingCartWidget::compatibility_error_event, this, &ShoppingCartWidget::ErrorMessage)
        connect(order_input, &QPushButton::clicked, this, &ShoppingCartWidget::orderMessageBox);                // click su tasto ORDER -> messagge box "ordine effettuato"
    }

    Engine::Query ShoppingCartWidget::getCurrentQuery() const {
        return currentQuery;
    }

    void ShoppingCartWidget::prevComponent() {
        unsigned int currentType = currentQuery.getType();
        if(currentType == 1) 
            currentQuery.setType(5); 
        currentQuery.setType(currentType - 1);
        emit search_event(currentQuery);
    }           

    void ShoppingCartWidget::nextComponent() {
        unsigned int currentType = currentQuery.getType();
        if(currentType == 5) 
            currentQuery.setType(1);
        currentQuery.setType(currentType + 1);
        emit search_event(currentQuery);
    }     

    void ShoppingCartWidget::tryAddComponentToCart(const Component::AbstractComponent* new_component) {
        
        if(!typeid(*new_component) == typeid(Component::GPU) && !typeid(*new_component) == typeid(Component::PSU)) {
            // new_component è MB-CPU-RAM
            if(typeid(*new_component) == typeid(Component::MotherBoard)) {
                // new_component è MB
                const Component::AbstractComponent* old_cpu = shop_cart.cart.checkAdded(const Component::CPU*);
                const Component::AbstractComponent* old_ram = shop_cart.cart.checkAdded(const Component::RAM*);
                
                if(old_cpu && !shop_cart.areCompatible(new_component, old_cpu)) {
                    QString error_msg = "Errore di compatibilità tra motherboard e CPU scelte"
                    emit compatibility_error_event(error_msg);
                    return;
                }
                if(old_ram && !shop_cart.areCompatible(new_component, old_ram)) {
                    QString error_msg = "Errore di compatibilità tra motherboard e RAM scelte"
                    emit compatibility_error_event(error_msg);
                    return;
                }  
            } else {
                // new_component è CPU o RAM
                const Component::AbstractComponent* old_mb = shop_cart.cart.checkAdded(const Component::MotherBoard*);
                if(old_mb && !shop_cart.areCompatible(old_mb, new_component)) {
                    if(typeid(*new_component) == typeid(Component::CPU)) {
                        // new_component è CPU
                        QString error_msg = "Errore di compatibilità tra motherboard e CPU scelte"
                    } else {
                        // new_component è RAM
                        QString error_msg = "Errore di compatibilità tra motherboard e RAM scelte"
                    }
                    emit compatibility_error_event(error_msg);
                    return;
                }
            }
        } // new_component è GPU-PSU oppure non ci sono problemi di compatibilità tra MB-CPU-RAM
        shop_cart.addToCart(new_component);
    }   

    void ShoppingCartWidget::addToCart(const Component::AbstractComponent* new_component) {
        shop_cart.cart.add(new_component);
        emit addedToCart_event();
    }


    void ShoppingCartWidget::search() {
        emit search_event(currentQuery);
    }    

    void ShoppingCartWidget::refreshTotalCost() {
        total_cost->setText("Costo Totale : \"" + QString::number(shop_cart.getTotalCost()));
    }

    void ShoppingCartWidget::ErrorMessage(QString error_msg) {
        QMessageBox msgBox;
        msgBox.setText("Warning");
        msgBox.setInformativeText(error_msg);
        msgBox.exec();
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
