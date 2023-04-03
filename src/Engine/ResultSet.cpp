#include <algorithm>

#include "ResultSet.h"
#include "../Component/AbstractComponent.h"

namespace Engine{

    ResultSet::ResultSet(const unsigned int s) : size(s) { }
    unsigned int ResultSet::getSize() const {
        return size;
    }
    
    const std::vector<ComponentShown>& ResultSet::getShownItems() const {
        return shownItems;
    }
    ResultSet& ResultSet::add(const ComponentShown component) {
        shownItems.push_back(component);
        return *this;
    }

    ResultSet& ResultSet::priceASort() {
        std::sort(shownItems.begin(), shownItems.end());
        return *this;
    }
    ResultSet& ResultSet::priceDSort() {
        std::sort(shownItems.begin(), shownItems.end(), std::greater<ComponentShown>());
        return *this;
    }
    
}
