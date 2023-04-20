// Classe che rappresenta il carrello, simile a Memory e ResultSet
// in particolare metodo per calcolo del costo totale delle componenti attualmente scelte 
// e per gestire il carrello/selettore di componenti
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
            // metodo search?
            bool areCompatible(const Component::AbstractComponent* comp1, const Component::AbstractComponent* comp2) const;    // metodo che controlla la compatibilità

            double getTotalCost() const;            
            void calculateTotalCost();              //viene richiamato già quando uso metodi add, remove, clear

    };
}

#endif