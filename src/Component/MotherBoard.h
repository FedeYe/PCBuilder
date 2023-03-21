#ifndef COMPONENT_MOTHERBOARD_H
#define COMPONENT_MOTHERBOARD_H


#include "AbstractComponent.h"

namespace Component {

class MotherBoard : public AbstractComponent {
    private:
        std::string socket;
        std::string chipset;
        std::string generation;
        unsigned int numRAM;
        unsigned int numSSD;

    public:
        MotherBoard(
            const unsigned int identifier,
            const std::string name,
            const double price,
            const std::string brand,
            const std::string image_path, 
            const std::string socket,
            const std::string chipset,
            const std::string generation,
            const unsigned int numRAM,
            const unsigned int numSSD
        );
        
        const std::string& getSocket() const;
        MotherBoard& setSocekt(const std::string socket); 

        const std::string& getChipset() const;
        MotherBoard& setChipset(const std::string chipset);

        const std::string& getGeneration() const;
        MotherBoard& setGeneration(const std::string generation);

        unsigned int getNumRAM() const;
        MotherBoard& setNumRAM(const unsigned int numRAM);

        unsigned int getNumSSD() const;
        MotherBoard& setNumSSD(const unsigned int numSSD);

        virtual void accept(IConstVisitor& visitor) const;
        virtual void accept(IVisitor& visitor);
        

}; 

}
#endif