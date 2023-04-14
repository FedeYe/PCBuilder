#ifndef VIEW_BUILD_WIDGET_H
#define VIEW_BUILD_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
//#include <>

#include "../Engine/Query.h"
#include "../Engine/ShoppingCart.h"
#include "ResultRenderer::IResultRenderer.h"
#include "WidgetLookup.h"


namespace View {

    class BuildWidget: public QWidget {
            Q_OBJECT
        private:
            Engine::ShoppingCart& cart;
            QVector<WidgetLookup> lookup;
            QGridLayout* grid;
            ResultRender::IResultRenderer* renderer;


        public:
            BuildWiget(QWidget* parent = 0);
            Engine::ShoppingCart& getCart() const;
        
        signals:    
            void comp_selected_event(Engine::Query query);                              // è stata scelta la tipologia di componente che si vuole visualizzare 
            void addedToCartEvent(const Engine::ShoppingCart& cart);                    // è stato aggiunto un prodotto per una determinata componente con successo -> refresh total_cost sulla View        
            void removedFromCartEvent(const Engine::ShoppingCart& cart);                // è stato rimosso un prodotto per una determinata componente con successo -> refresh total_cost sulla View

        public slots:
            void selectSearchedComp();

            void addToCart(Component::AbstractComponent* component);
            void removeFromCart(Component::AbstractComponent* component);

            void showProduct(Engine::Query query, Engine::ShoppingCart cart);
    };
}

#endif