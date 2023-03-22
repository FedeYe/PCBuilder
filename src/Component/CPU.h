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
        unsigned double coreclock;
        unsigned double boostclock;
        unsigned int cache;

    public:
        CPU(
            const unsigned int identifier,
            const std::string name,
            const double price,
            const std::string brand,
            const std::string image_path,
            const std::string chipset,
            const unsigned int numCores,
            const unsigned int threads,
            const unsigned double coreclock,
            const unsigned double boostclock,
            const unsigned int cache);

        const std::string &getChipset() const;
        CPU &setChipset(const std::string chipset);

        unsigned int getNumCores() const;
        CPU &setNumCores(const unsigned int numCores);

        unsigned int getThreads() const;
        CPU &setThreads(const unsigned int threads);

        unsigned double getCoreclock() const;
        CPU &setCoreclock(const unsigned double coreclock);

        unsigned double getBoostclock() const;
        CPU &setBoostclock(const unsigned double boostclock);

        unsigned int getCache() const;
        CPU &setCache(const unsigned int cache);

        virtual void accept(IConstVisitor &visitor) const;
        virtual void accept(IVisitor &visitor);
    };

}
#endif