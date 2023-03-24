#ifndef ENGINE_COMPONENT_SHOWN_H
#define ENGINE_COMPONENT_SHOWN_H

#include "../Component/AbstractComponent.h"

namespace Engine {

    class ComponentShown {
        private:
            const Component::AbstractComponent* component;
        public:
            ComponentShown(const Component::AbstractComponent* comp);
            const Component::AbstractComponent* getComponent() const;
    };
}
#endif