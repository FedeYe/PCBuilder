#ifndef ENGINE_RESULT_SET_H
#define ENGINE_RESULT_SET_H

#include <vector>

#include "ComponentShown.h" 

namespace Engine {

    class ResultSet {
        private:
            const unsigned int size;
            std::vector<ComponentShown> shownItems;
        public:
            ResultSet(const unsigned int s);
            unsigned int getSize() const;
            const std::vector<ComponentShown>& getShownItems() const;
            ResultSet& add(const ComponentShown component);

            ResultSet& priceASort();
            ResultSet& priceDSort();
    };
}

#endif
