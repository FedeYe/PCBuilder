#include "PSU.h" 

namespace Component {

    PSU::PSU(
        const unsigned int identifier,
        const std::string name,
        const double price,
        const std::string brand,
        const std::string image_path,
        const unsigned int suppliedWatt,
        const unsigned int efficiency,
        const bool modular
    ) : AbstractComponent(identifier, name, price, brand, image_path), 
        suppliedWatt(suppliedWatt), efficiency(efficiency), modular(modular) {}
    
    unsigned int PSU::getSuppWatt() const {
        return suppliedWatt;
    }
    PSU& PSU::setSuppWatt(const unsigned int suppliedWatt) {
        this->suppliedWatt = suppliedWatt;
        return *this;
    }

    unsigned int PSU::getEfficiency() const {
        return efficiency;
    }
    PSU& PSU::setEfficiency(const unsigned int efficiency) {
        this->efficiency = efficiency;
        return *this;
    }

    bool PSU::isModular() const {
        return modular;
    }
    PSU& PSU::setModular(const bool modular) {
        this->modular = modular;
        return *this;
    }



}