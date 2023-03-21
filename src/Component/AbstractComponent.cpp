#include "AbstractComponent.h"

namespace Component {

AbstractComponent::AbstractComponent(
    const unsigned int identifier,
    const std::string name,
    const double price,
    const std::string brand,
    const std::string image_path ) : identifier(identifier), name(name) , price(price) , brand(brand), image_path(image_path) {}

AbstractComponent::~AbstractComponent() {
}

unsigned int AbstractComponent::getIdentifier() const {
    return identifier;
}
        
const std::string& AbstractComponent::getName() const{
    return name;
}

AbstractComponent& AbstractComponent::setName(const std::string name) {
    this->name = name;
    return *this;
}

const double AbstractComponent::getPrice() const {
    return price;
}

AbstractComponent& AbstractComponent::setPrice(const double price) {
    this->price;
    return *this;
}

const std::string& AbstractComponent::getBrand() const {
    return brand;
}

AbstractComponent& AbstractComponent::setBrand(const std::string brand) {
    this->brand=brand;
    return *this;
}

const std::string& AbstractComponent::getImagePath() const {
    return image_path;
}

AbstractComponent& AbstractComponent::setImagePath(const std::string image_path) {
    this->image_path = image_path;
    return *this;
}

}