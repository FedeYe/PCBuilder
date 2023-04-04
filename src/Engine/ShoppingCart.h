// Classe che rappresenta il carrello, simile a Memory e ResultSet
// in particolare metodo per calcolo del costo totale delle componenti attualmente scelte
#ifndef ENGINE_SHOPPING_CART_H
#define ENGINE_SHOPPING_CART_H

#include "../Service/Container.h"
#include "../Component/AbstractComponent.h"

namespace Engine {
    
    class ShoppingCart {
        private:
            Service::Container<const Component::AbstractComponent*> cart;
            double total_cost;
        public:
            ShoppingCart();
            ~ShoppingCart() = default;

            ShoppingCart& add(const Component::AbstractComponent* component);
            ShoppingCart& remove(const Component::AbstractComponent* component);
            ShoppingCart& clear();

            double getTotalCost() const;
            void calculateTotalCost();

    };
}

#endif