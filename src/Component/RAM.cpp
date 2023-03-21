#include "RAM.h"

namespace Component{ 

    RAM::RAM(
        const unsigned int identifier,
        const std::string name,
        const double price,
        const std::string brand,
        const std::string image_path,
        const unsigned int capacity,
        const unsigned int stockSpeed,
        const unsigned int maxSpeed,
        const std::string generation
    ) : AbstractComponent(identifier, name, price, brand, image_path), 
        capacity(capacity), stockSpeed(stockSpeed), maxSpeed(maxSpeed), generation(generation) {}

    unsigned int RAM::getCapacity() const {
        return capacity;
    }
    RAM& RAM::setCapacity(const unsigned int capacity) {
        this->capacity = capacity;
        return *this;
    }

    unsigned int RAM::getStockSpeed() const {
        return stockSpeed;
    }
    RAM& RAM::setStockSpeed(const unsigned int stockSpeed) {
        this->stockSpeed = stockSpeed;
        return *this;
    }

    unsigned int RAM::getMaxSpeed() const {
        return maxSpeed;
    }
    RAM& RAM::setMaxSpeed(const unsigned int maxSpeed) {
        this->maxSpeed = maxSpeed;
        return *this;
    }

    const std::string& RAM::getGeneration() const {
        return generation;
    }
    RAM& RAM::setGeneration(const std::string generation) {
        this->generation = generation;
        return *this;
    }



}