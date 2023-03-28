#ifndef COMPONENT_REPOSITORY_I_REPOSITORY_H
#define COMPONENT_REPOSITORY_I_REPOSITORY_H

#include <vector>
#include "../AbstractComponent.h"

namespace Component {
namespace Repository {

    class IRepository {
        public: 
            virtual ~IRepository() = default;
            virtual IRepository& create(AbstractComponent* component) = 0;
            virtual AbstractComponent* read(const unsigned int identifier) const = 0;
            virtual IRepository& update(AbstractComponent* item) = 0;
            virtual IRepository& remove(const unsigned int identifier) = 0;
            virtual std::vector<AbstractComponent*> readAll() const = 0;    
    };
}
}

#endif