#ifndef ENGINE_MEMORY_H
#define ENGINE_MEMORY_H

#include "IEngine.h" 

#include "../Service/Container.h"
#include "../Component/AbstractComponent.h"
#include "Query.h"
#include "ResultSet.h"

namespace Engine {

    class Memory: public IEngine {
        private:
            Service::Container<const Component::AbstractComponent*> catalog;

        public:
            Memory();
            virtual ~Memory();
            virtual Memory& add(const Component::AbstractComponent* component);
            virtual Memory& remove(const Component::AbstractComponent* component);
            virtual Memory& clear();
            virtual ResultSet search(const Query& query) const;
    };
}

#endif 