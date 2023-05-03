#include "ShoppingCart.h"

#include <typeinfo>
#include <string>

#include "../Component/MotherBoard.h"
#include "../Component/CPU.h"
#include "../Component/GPU.h"
#include "../Component/PSU.h"
#include "../Component/RAM.h"
#include "TypeDefiner.h"


namespace Engine {

    ShoppingCart::ShoppingCart() : total_cost(0) {

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
        old_component = cart.findAdded(new_component);
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
        TypeDefiner typeId;
        component->accept(typeId);
        const Component::AbstractComponent* p_cmp = nullptr;
        switch(typeId.getCompType()) {
            case 1:
            p_cmp = new const Component::MotherBoard();
            case 2:
            p_cmp = new const Component::CPU();
            case 3:
            p_cmp = new const Component::GPU();
            case 4:
            p_cmp = new const Component::PSU();
            case 5:
            p_cmp = new const Component::RAM();
        }
        cart.remove(component);
        cart.add(p_cmp);
        return *this;
    }
        
    ShoppingCart& ShoppingCart::clear() {
        cart.clear();
        total_cost = 0;
        return *this;
    }

    bool ShoppingCart::tryAddComponentToCart(const Component::AbstractComponent* new_component, std::string& error_msg) {
            
            TypeDefiner typeId;
            new_component->accept(typeId);
            
            if(typeId.getCompType() != 3 && typeId.getCompType() != 4) {
                // new_component è MB-CPU-RAM
                if(typeId.getCompType() == 1) {
                    // new_component è MB
                    const Component::CPU* p_cpu = new const Component::CPU();
                    const Component::AbstractComponent* old_cpu = cart.findAdded(p_cpu);

                    const Component::RAM* p_ram = new const Component::RAM();
                    const Component::AbstractComponent* old_ram = cart.findAdded(p_ram);
                    
                    if(!areCompatible(new_component, old_cpu)) {
                        error_msg = "Errore di compatibilità tra motherboard e CPU scelte";
                        return false;
                    }
                    if(!areCompatible(new_component, old_ram)) {
                        error_msg = "Errore di compatibilità tra motherboard e RAM scelte";
                        return false;
                    }  
                } else {
                    // new_component è CPU o RAM
                    const Component::MotherBoard* p_mb = new const Component::MotherBoard();
                    const Component::AbstractComponent* old_mb = cart.findAdded(p_mb);
                    if(!areCompatible(old_mb, new_component)) {
                        if(typeId.getCompType() == 2) {
                            // new_component è CPU
                            error_msg = "Errore di compatibilità tra motherboard e CPU scelte";
                        } else {
                            // new_component è RAM
                            error_msg = "Errore di compatibilità tra motherboard e RAM scelte";
                        }
                        return false;
                    }
                }
            } // new_component è GPU-PSU oppure non ci sono problemi di compatibilità tra MB-CPU-RAM
            return true;
        }   

    bool ShoppingCart::areCompatible(const Component::AbstractComponent* comp1, const Component::AbstractComponent* comp2) const {

        TypeDefiner typeId1;
        TypeDefiner typeId2;
        comp1->accept(typeId1);
        comp2->accept(typeId2);

        if( typeId1.getCompType() == 1 && typeId2.getCompType() == 2 ) {
            
                const Component::MotherBoard* mb = dynamic_cast<const Component::MotherBoard*>(comp1);
                const Component::CPU* cpu = dynamic_cast<const Component::CPU*>(comp2);
                if(mb->getChipset() == "<default>" || cpu->getChipset() == "<default>") 
                    return true;
                return (mb->getChipset() == cpu->getChipset());

        } else if( typeId1.getCompType() == 1 && typeId2.getCompType() == 5 ) {

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
