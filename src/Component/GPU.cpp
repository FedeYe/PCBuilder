#include "GPU.h"

namespace Component
{
    GPU::GPU(
        const unsigned int identifier,
        const std::string name,
        const double price,
        const std::string brand,
        const std::string image_path,
        const unsigned int numPorte,
        const unsigned int numVRam,
        const unsigned int numVentole,
        const bool availability
        ) : AbstractComponent(identifier, name, price, brand, image_path),
            numPorte(numPorte), numVRam(numVRam), numVentole(numVentole), availability(availability) {}

    unsigned int GPU::getNumPorte() const
    {
        return numPorte;
    }

    GPU& GPU::setNumPorte(const unsigned int numPorte)
    {
        this->numPorte = numPorte;
        return *this;
    }

    unsigned int GPU::getNumVRam() const
    {
        return numVRam;
    }

    GPU& GPU::setNumVRam(const unsigned int numVRam)
    {
        this->numVRam = numVRam;
        return *this;
    }

    unsigned int GPU::getNumVentole() const
    {
        return numVentole;
    }

    GPU& GPU::setNumVentole(const unsigned int numVentole)
    {
        this->numVentole = numVentole;
        return *this;
    }

    bool GPU::isAvailable() const{
        return availability;
    }
    GPU& GPU::setAvailability(const bool availability){
        this->availability = availability;
        return *this;
    }

    void GPU::accept(IConstVisitor& visitor) const {
        visitor.visit(*this);
    }
    void GPU::accept(IVisitor& visitor) {
        visitor.visit(*this);
    }
}