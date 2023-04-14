#ifndef VIEW_SHOPPING_CART_WIDGET_H
#define VIEW_SHOPPING_CART_WIDGET_H

#include <QWidget>
#include <QLabel>
//#include <>

#include "../Engine/Query.h"
#include "../Engine/ShoppingCart.h"             // per il metodo get totale costo degli items in carrello
#include "BuildWidget.h"

namespace View {
    class ShoppingCartWidget: public QWidget {
            Q_OBJECT
        private:
            QLabel* total_cost;                     // mostra il prezzo totale di tutte le componenti
            BuildWidget* build_widget;          // contiene un grid layout dove poter selezionare/visualizzare le varie componenti
            Engine::Query& currentQuery;            // salvo l'ultima query usata dal search( quindi quella usata per i prodotti attualmente presenti in ResultSet)
        public:
            explicit ShoppingCartWidget(Engine::Query& cQuery, QWidget* parent = 0);
            Engine::Query& getCurrentQuery() const;

        signals:
            void search_event(Engine::Query query);
            void tryAddComponentToCartEvent(const Component::AbstractComponent *component)
            
        public slots:

            void prevComponent();             // modifico la query (-1 al type) ed emetto nuovamente il signal search_event(query) 
            void nextComponent();             // modifico la query (+1 al type) ecc...
            
            void search(Engine::Query query);         
            void refreshTotalCost(const Engine::ShoppingCart& carrello);
            void orderMessageBox(); 
    }
}


#endif