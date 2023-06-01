#ifndef VIEW_SHOPPING_CART_WIDGET_H
#define VIEW_SHOPPING_CART_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
#include <QString>
//#include <>

#include "../Engine/Query.h"
#include "../Engine/ShoppingCart.h"             // per il metodo get totale costo degli items in carrello
#include "CartRenderer/ICartRenderer.h"
#include "WidgetLookup.h"

namespace View {
    class ShoppingCartWidget: public QWidget {
            Q_OBJECT
        private:
            QLabel* total_cost;                     // mostra il prezzo totale di tutte le componenti
            Engine::Query currentQuery;             // salvo l'ultima query usata dal search( quindi quella usata per i prodotti attualmente presenti in ResultSet)
            QVector<WidgetLookup> lookup;
            QGridLayout* grid;
            CartRenderer::ICartRenderer* renderer;
        public:
            explicit ShoppingCartWidget(Engine::Query cQuery, QWidget* parent = 0);
            void addToCart(const Component::AbstractComponent* new_component, Engine::ShoppingCart& shop_cart); 
            void showCart(Engine::ShoppingCart& shop_cart);
            void errorMessage(QString error_msg);
            void refreshTotalCost(Engine::ShoppingCart& shop_cart);

            Engine::Query getCurrentQuery() const;

        signals:
            void search_event(Engine::Query query);
            void removeFromCart_event(const Component::AbstractComponent *component);
            void componentSelected_event(const Component::AbstractComponent *component);
               
        public slots:
            void prevComponent();             // modifico la query (-1 al type) ed emetto nuovamente il signal search_event(query) 
            void nextComponent();             // modifico la query (+1 al type) ecc...
            void componentSelected(const Component::AbstractComponent* component);         // search viene schiacciato -> crea/aggiorna la currentQuery 
            void search();                                                              // cerca gli oggetti che soddisfano la query
                     
            void orderMessageBox();
            
    };
}


#endif
