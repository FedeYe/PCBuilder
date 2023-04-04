#include "ShoppingCart.h"

namespace Engine {

    ShoppingCart::ShoppingCart() {
    }

    ShoppingCart& ShoppingCart::add(const Component::AbstractComponent* new_component) {

        const Component::AbstractComponent* old_component = nullptr;
        old_component = cart.checkAdded(new_component);
        if(old_component != nullptr) {
            cart.remove(old_component);
        }
        cart.add(new_component);
        calculateTotalCost();
        return *this;
    }

    ShoppingCart& ShoppingCart::remove(const Component::AbstractComponent* component) {
        cart.remove(component);
        calculateTotalCost();
        return *this;
    }
        
    ShoppingCart& ShoppingCart::clear() {
        cart.clear();
        total_cost = 0;
        return *this;
    }

    double ShoppingCart::getTotalCost() const {
        return total_cost;
    }
    
    void ShoppingCart::calculateTotalCost() {
        double tc = 0;
        for(    Service::Container<const Component::AbstractComponent*>::Node* node = cart.getHead();
                node != nullptr;
                node = node->getNext()
        )   {
            tc += node->getData()->getPrice();
        }
        total_cost = tc;
    }

}