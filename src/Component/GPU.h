#ifndef COMPONENT_GPU_H
#define COMPONENT_GPU_H

#include "AbstractComponent.h"

namespace Component
{

    class GPU : public AbstractComponent
    {
    private:
        unsigned int numPorte;
        unsigned int numVRam;
        unsigned int numVentole;
        bool availability;

    public:
        GPU(
            const unsigned int identifier = 0,
            const std::string name = "GPU",
            const double price = 0,
            const std::string brand = "",
            const std::string image_path = ":/Assets/icons/defaultGPU.svg",
            const unsigned int numPorte = 0,
            const unsigned int numVRam = 0,
            const unsigned int numVentole = 0,
            const bool availability = true);

        unsigned int getNumPorte() const;
        GPU &setNumPorte(const unsigned int numPorte);

        unsigned int getNumVRam() const;
        GPU &setNumVRam(const unsigned int numVRam);

        unsigned int getNumVentole() const;
        GPU &setNumVentole(const unsigned int numVentole);

        bool isAvailable() const;
        GPU& setAvailability(const bool availability);

        virtual void accept(IConstVisitor &visitor) const;
        virtual void accept(IVisitor &visitor);
    };

}
#endif