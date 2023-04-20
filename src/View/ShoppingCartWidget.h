#ifndef VIEW_SHOPPING_CART_WIDGET_H
#define VIEW_SHOPPING_CART_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
//#include <>

#include "../Engine/Query.h"
#include "../Engine/ShoppingCart.h"             // per il metodo get totale costo degli items in carrello
#include "BuildWidget.h"
#include "ResultRenderer/IResultRenderer.h"
#include "WidgetLookup.h"

namespace View {
    class ShoppingCartWidget: public QWidget {
            Q_OBJECT
        private:
            QLabel* total_cost;                     // mostra il prezzo totale di tutte le componenti
            Engine::Query currentQuery;             // salvo l'ultima query usata dal search( quindi quella usata per i prodotti attualmente presenti in ResultSet)
            Engine::ShoppingCart& shop_cart;
            QVector<WidgetLookup> lookup;
            QGridLayout* grid;
            ResultRenderer::IResultRenderer* renderer;
        public:
            explicit ShoppingCartWidget(Engine::Query cQuery, QWidget* parent = 0);
            Engine::Query getCurrentQuery() const;
            Engine::ShoppingCart& getCart() const;

        signals:
            void search_event(Engine::Query query);
            void compatibility_error_event(Qstring error_msg);                              // sbuca messaggio di errore compatibilità
            void addedToCart_event(Component::AbstractComponent* new_component);            // causa il refresh della griglia-carrello e della label costo totale
            
            
        public slots:

            void prevComponent();             // modifico la query (-1 al type) ed emetto nuovamente il signal search_event(query) 
            void nextComponent();             // modifico la query (+1 al type) ecc...

            void tryAddComponentToCart(const Component::AbstractComponent* new_component);
            void addToCart();                                               // aggiunge oggetto e emette segnale addedToCart_event
            
            // void componentSelected(Component::AbstractComponent* component);         // search viene schiacciato -> crea/aggiorna la currentQuery 
            void search();                                                              // cerca gli oggetti che soddisfano la query
            // void removeFromCart(Component::AbstractComponent* component);            // toglie e chiama la funzione che resetta lo slot della griglia-carrello a default
            

            // void showCart(Engine::Query query);      forse non serve
            // void refreshGrid(Component::AbstractComponent* component)
            
                    
            void refreshTotalCost();
            void ErrorMessage(Qstring error_msg);
            void orderMessageBox();
            
    };
}


#endif
