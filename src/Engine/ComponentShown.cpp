#include "ComponentShown.h"

namespace Engine
{
    ComponentShown::ComponentShown(const Component::AbstractComponent* comp) 
    : component(comp), price_shown(comp->getPrice()) {}

    const Component::AbstractComponent* ComponentShown::getComponent() const {
        return component;
    }

    double ComponentShown::getPriceShown() const {
        return price_shown;
    }

    bool ComponentShown::operator<(const ComponentShown& component_shown) const {
        return price_shown < component_shown.price_shown;
    }

    bool ComponentShown::operator>(const ComponentShown& component_shown) const {
        return price_shown > component_shown.price_shown;
    }

} 
