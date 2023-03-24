#include "ComponentShown.h"

namespace Engine
{
    ComponentShown::ComponentShown(const Component::AbstractComponent* comp) : component(comp) {}

    const Component::AbstractComponent* ComponentShown::getComponent() const {
        return component;
    }
} 
