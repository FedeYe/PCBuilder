#include "ShoppingCartWidget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
//#include <>

namespace View {

    ShoppingCartWidget::ShoppingCartWidget(Engine::Query& cQuery, QWidget* parent) 
        : currentQuery(cQuery), QWidget(parent) 
    {
        QVBoxLayout* vbox = new QVBoxLayout(this);
        vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

        vbox->addStretch();

        builder_widget = new BuilderWidget();
        vbox->addWidget(builder_widget);

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
        vbox->addWidget(summary);

        //connect
        connect(builder_widget, &BuilderWidget::comp_selected_event, this, &ShoppingCartWidget::search);        // selezionando una tipologia di componente da ricercare   
        
        connect(builder_widget, /* event = aggiunto un item in carrello */, this, &ShoppingCartWidget::refreshTotalCost);
        connect(builder_widget, /* event = rimosso un item da carrello */, this, &ShoppingCartWidget::refreshTotalCost);

        connect(order_input, &QPushButton::clicked, this, &ShoppingCartWidget::orderMessageBox);                // click su tasto ORDER -> messagge box "ordine effettuato"
    }

    Engine::Query& ShoppingCartWidget::getCurrentQuery() const {
        return currentQuery;
    }

    void ShoppingCartWidget::prevComponent() {
        unsigned int currentType = currentQuery.getType()
        if(currentType == 1) 
            currentQuery.setType(5); 
        currentQuery.setType(currentType - 1);
        emit search_event(currentQuery);
    }           

    void ShoppingCartWidget::nextComponent() {
        unsigned int currentType = currentQuery.getType()
        if(currentType == 5) 
            currentQuery.setType(1);
        currentQuery.setType(currentType + 1);
        emit search_event(currentQuery);
    }     

    void ShoppingCartWidget::search(Engine::Query query) {
        currentQuery = query;
        emit search_event(query);
    }    

    void ShoppingCartWidget::refreshTotalCost(Engine::ShoppingCart carrello) {
        total_cost->setText("Costo Totale : \"" + QString::number(carrello.getTotalCost()));
    }

    void ShoppingCartWidget::orderMessageBox() {

        QMessageBox::StandardButton confirmation;
            confirmation = QMessageBox::question(
                this,
                "Concludere ordine",
                "Confermare l'ordine? .\n?",
                QMessageBox::Yes | QMessageBox::No );
            if (confirmation == QMessageBox::Yes) 
            {
                QApplication::quit();
            }
    } 
}