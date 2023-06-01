#include "Memory.h" 
#include "ComponentShown.h" 
#include "FilterVisitor.h" 

namespace Engine {

    Memory::Memory() {
    }

    Memory::~Memory() {
    }

    Memory& Memory::add(const Component::AbstractComponent* component) {
        catalog.add(component);
        return *this;
    }

    Memory& Memory::remove(const Component::AbstractComponent* component) {
        catalog.remove(component);
        return *this;
    }

    Memory& Memory::clear() {
        catalog.clear();
        return *this;
    }
    
    ResultSet Memory::search(const Query& query) const { 

        FilterVisitor filterV(query);
        std::vector<ComponentShown> matchedComponents;

        for (   
                Service::Container<const Component::AbstractComponent*>::Node* node = catalog.getHead();
                node != nullptr;
                node = node->getNext()) 
        {
            node->getData()->accept(filterV);
            if( filterV.hasMatch() ) 
                matchedComponents.push_back(ComponentShown(node->getData()));
        }

        ResultSet shownComponents(matchedComponents.size());
        for (auto it = matchedComponents.begin(); it != matchedComponents.end(); it++) {
            
            shownComponents.add(*it);
        }
        shownComponents.priceASort(); //ordino i prodotti in base al prezzo in modo crescente (di deafult)

        return shownComponents;
    }

}