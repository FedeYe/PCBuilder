#ifndef COMPONENT_CPU_H
#define COMPONENT_CPU_H

#include "AbstractComponent.h"

namespace Component
{

    class CPU : public AbstractComponent
    {
    private:
        std::string chipset;
        unsigned int numCores;
        unsigned int threads;
        double coreclock;
        double boostclock;
        unsigned int cache;

    public:
        CPU(
            const unsigned int identifier = 0,
            const std::string name = "CPU",
            const double price = 0,
            const std::string brand = "",
            const std::string image_path = ":/Assets/icons/defaultCPU.svg",
            const std::string chipset = "<default>", 
            const unsigned int numCores = 0,
            const unsigned int threads = 0,
            const double coreclock = 0,
            const double boostclock = 0,
            const unsigned int cache = 0);

        const std::string &getChipset() const;
        CPU &setChipset(const std::string chipset);

        unsigned int getNumCores() const;
        CPU &setNumCores(const unsigned int numCores);

        unsigned int getThreads() const;
        CPU &setThreads(const unsigned int threads);

        double getCoreclock() const;
        CPU &setCoreclock(const double coreclock);

        double getBoostclock() const;
        CPU &setBoostclock(const double boostclock);

        unsigned int getCache() const;
        CPU &setCache(const unsigned int cache);

        virtual void accept(IConstVisitor &visitor) const;
        virtual void accept(IVisitor &visitor);
    };

}
#endif