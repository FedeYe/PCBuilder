#include "ShoppingCart.h"

#include <typeinfo>

#include "../Component/MotherBoard.h"
#include "../Component/CPU.h"
#include "../Component/GPU.h"
#include "../Component/PSU.h"
#include "../Component/RAM.h"


namespace Engine {

    ShoppingCart::ShoppingCart() {

        const Component::AbstractComponent* p_mb = new const Component::MotherBoard();
        const Component::AbstractComponent* p_cpu = new const Component::CPU();
        const Component::AbstractComponent* p_gpu = new const Component::GPU();
        const Component::AbstractComponent* p_psu = new const Component::PSU();
        const Component::AbstractComponent* p_ram = new const Component::RAM();

        cart.add(p_mb);
        cart.add(p_cpu);
        cart.add(p_gpu);
        cart.add(p_psu);
        cart.add(p_ram);
    }

    Service::Container<const Component::AbstractComponent*>::Node* ShoppingCart::getCartHead() const {
        return cart.getHead();
    }

    ShoppingCart& ShoppingCart::add(const Component::AbstractComponent* new_component) {

        const Component::AbstractComponent* old_component = nullptr;
        old_component = &*cart.findAdded(new_component);
        if(old_component != nullptr) {
            cart.remove(old_component);
            cart.add(new_component);
            calculateTotalCost();
            return *this;
        } else {
            return *this;
        }
        
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

    const Component::AbstractComponent* ShoppingCart::getAdded(const Component::AbstractComponent* old_component) const {
        return cart.findAdded(old_component);
    }

    bool ShoppingCart::areCompatible(const Component::AbstractComponent* comp1, const Component::AbstractComponent* comp2) const {
        if( typeid(*comp1) == typeid(Component::MotherBoard) && 
            typeid(*comp2) == typeid(Component::CPU)) {
            
                const Component::MotherBoard* mb = dynamic_cast<const Component::MotherBoard*>(comp1);
                const Component::CPU* cpu = dynamic_cast<const Component::CPU*>(comp2);
                if(mb->getChipset() == "<default>" || cpu->getChipset() == "<default>") 
                    return true;
                return (mb->getChipset() == cpu->getChipset());

        } else if(  typeid(*comp1) == typeid(Component::MotherBoard) && 
                    typeid(*comp2) == typeid(Component::RAM)) {

                        const Component::MotherBoard* mb = dynamic_cast<const Component::MotherBoard*>(comp1);
                        const Component::RAM* ram = dynamic_cast<const Component::RAM*>(comp2);
                        if(mb->getGeneration() == "<default>" || ram->getGeneration() == "<default>") 
                            return true;
                        return (mb->getGeneration() == ram->getGeneration());          
        } else {
            return true;            // se il check è tra 2 componenti che non siano MB-CPU o MB-RAM, true perchè non ci sono problemi di compatibilità
        }       
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
