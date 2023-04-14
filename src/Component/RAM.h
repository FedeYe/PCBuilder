#ifndef COMPONENT_RAM_H
#define COMPONENT_RAM_H

#include "AbstractComponent.h"

namespace Component{

class RAM : public AbstractComponent {
    private: 
        std::string capacity;
        unsigned int stockSpeed;
        unsigned int maxSpeed;
        std::string generation;
    public:
        RAM(
            const unsigned int identifier,
            const std::string name,
            const double price,
            const std::string brand,
            const std::string image_path,
            const std::string capacity,
            const unsigned int stockSpeed,
            const unsigned int maxSpeed,
            const std::string generation
        );

        std::string getCapacity() const;
        RAM& setCapacity(const std::string capacity);

        unsigned int getStockSpeed() const;
        RAM& setStockSpeed(const unsigned int stockSpeed);

        unsigned int getMaxSpeed() const;
        RAM& setMaxSpeed(const unsigned int maxSpeed);

        const std::string& getGeneration() const;
        RAM& setGeneration(const std::string generation);

        virtual void accept(IConstVisitor& visitor) const;
        virtual void accept(IVisitor& visitor);

};

}


#endif