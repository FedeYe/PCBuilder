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
        const unsigned int numCores,
        const unsigned int numVentole,
        const bool availability
        ) : AbstractComponent(identifier, name, price, brand, image_path),
            numPorte(numPorte), numCores(numCores), numVentole(numVentole), availability(availability) {}

    unsigned int GPU::getNumPorte() const
    {
        return numPorte;
    }

    GPU& GPU::setNumPorte(const unsigned int numPorte)
    {
        this->numPorte = numPorte;
        return *this;
    }

    unsigned int GPU::getNumCores() const
    {
        return numCores;
    }

    GPU& GPU::setNumCores(const unsigned int numCores)
    {
        this->numCores = numCores;
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