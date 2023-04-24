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
            const unsigned int identifier = 0,
            const std::string name = "RAM",
            const double price = 0,
            const std::string brand = "",
            const std::string image_path = ":/Assets/icons/defaultRAM.svg",
            const std::string capacity = "",
            const unsigned int stockSpeed = 0,
            const unsigned int maxSpeed = 0,
            const std::string generation = "<default>"
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