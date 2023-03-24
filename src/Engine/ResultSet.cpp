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

    bool ResultSet::functionPriceA(ComponentShown i, ComponentShown j) { return i.getComponent()->getPrice() < j.getComponent()->getPrice(); }
    bool ResultSet::functionPriceD(ComponentShown i, ComponentShown j) { return i.getComponent()->getPrice() > j.getComponent()->getPrice(); }
    bool ResultSet::functionBrand(ComponentShown i, ComponentShown j) { return i.getComponent()->getBrand() < j.getComponent()->getBrand(); }
    
    ResultSet& ResultSet::priceASort() {
        std::sort(shownItems.begin(), shownItems.end(), functionPriceA);
        return *this;
    }
    ResultSet& ResultSet::priceDSort() {
        std::sort(shownItems.begin(), shownItems.end(), functionPriceD);
        return *this;
    }
    ResultSet& ResultSet::brandSort() {
        std::sort(shownItems.begin(), shownItems.end(), functionBrand);
        return *this;
    }
    
}