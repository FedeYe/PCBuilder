#ifndef COMPONENT_PSU_H
#define COMPONENT_PSU_H

#include "AbstractComponent.h"

namespace Component{

//PSU = Power Supply Unit
class PSU : public AbstractComponent {
    private: 
        unsigned int suppliedWatt;
        unsigned int efficiency;
        bool modular;
    public:
        PSU(
            const unsigned int identifier,
            const std::string name,
            const double price,
            const std::string brand,
            const std::string image_path,
            const unsigned int suppliedWatt,
            const unsigned int efficiency,
            const bool modular
        );

        unsigned int getSuppWatt() const;
        PSU& setSuppWatt(const unsigned int suppliedWatt);

        unsigned int getEfficiency() const;
        PSU& setEfficiency(const unsigned int efficiency);

        bool isModular() const;
        PSU& setModular(const bool modular);

        virtual void accept(IConstVisitor& visitor) const;
        virtual void accept(IVisitor& visitor);

};

}


#endif