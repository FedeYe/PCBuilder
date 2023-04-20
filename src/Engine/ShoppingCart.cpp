#include "ShoppingCart.h"

#include <typeinfo>

#include "../Component/MotherBoard.h"
#include "../Component/CPU.h"
#include "../Component/GPU.h"
#include "../Component/PSU.h"
#include "../Component/RAM.h"


namespace Engine {

    ShoppingCart::ShoppingCart() {
        cart = cart.add(new Component::RAM);
        cart = cart.add(new Component::PSU);
        cart = cart.add(new Component::GPU);
        cart = cart.add(new Component::CPU);
        cart = cart.add(new Component::MotherBoard);
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

    bool ShoppingCart::areCompatible(const Component::AbstractComponent* comp1, const Component::AbstractComponent* comp2) const {
        if( typeid(*comp1) == typeid(Component::MotherBoard) && 
            typeid(*comp2) == typeid(Component::CPU)) {
            
                const Component::MotherBoard* mb = dynamic_cast<const Component::MotherBoard*>(comp1);
                const Component::CPU* cpu = dynamic_cast<const Component::CPU*>(comp2);

                return (mb->getChipset() == cpu->getChipset());

        } else if(  typeid(*comp1) == typeid(Component::MotherBoard) && 
                    typeid(*comp2) == typeid(Component::RAM)) {

                        const Component::MotherBoard* mb = dynamic_cast<const Component::MotherBoard*>(comp1);
                        const Component::RAM* ram = dynamic_cast<const Component::RAM*>(comp2);

                        return (mb->getGeneration() == ram->getGeneration());          
        } 
        return true;            // se il check è tra 2 componenti che non siano MB-CPU o MB-RAM, true perchè non ci sono problemi di compatibilità
        
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
