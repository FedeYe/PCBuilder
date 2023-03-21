#include "MotherBoard.h"

namespace Component {

    MotherBoard::MotherBoard(
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
    ) : AbstractComponent(identifier, name, price, brand, image_path), 
        socket(socket), chipset(chipset), generation(generation), numRAM(numRAM), numSSD(numSSD) {}

    const std::string& MotherBoard::getSocket() const {
        return socket;
    }
    MotherBoard& MotherBoard::setSocekt(const std::string socket) {
        this->socket = socket;
        return *this;
    }

    const std::string& MotherBoard::getChipset() const{
        return chipset;
    }
    MotherBoard& MotherBoard::setChipset(const std::string chipset){
        this->chipset = chipset;
        return *this;
    }

    const std::string& MotherBoard::getGeneration() const{
        return generation;
    }
    MotherBoard& MotherBoard::setGeneration(const std::string generation){
        this->generation = generation;
        return *this;
    }

    unsigned int MotherBoard::getNumRAM() const{
        return numRAM;
    }
    MotherBoard& MotherBoard::setNumRAM(const unsigned int numRAM){
        this->numRAM = numRAM;
        return *this;
    }

    unsigned int MotherBoard::getNumSSD() const{
        return numSSD;
    }
    MotherBoard& MotherBoard::setNumSSD(const unsigned int numSSD){
        this->numSSD = numSSD;
        return *this;
    }   

}
