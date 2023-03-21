#ifndef ITEM_ABSTRACT_ITEM_H
#define ITEM_ABSTRACT_ITEM_H

#include <string>

#include "IConstVisitor.h"
#include "IVisitor.h"

namespace Component {

class AbstractComponent {
    private:
        const unsigned int identifier;
        std::string name;
        double price;
        std::string brand;
        std::string image_path;
    	
    protected:
        AbstractComponent(
            const unsigned int identifier,
            const std::string name,
            const double price,
            const std::string brand,
            const std::string image_path
        );

    public:
        virtual ~AbstractComponent();
        unsigned int getIdentifier() const;
        const std::string& getName() const;
        AbstractComponent& setName(const std::string name);
        const double getPrice() const;
        AbstractComponent& setPrice(const double price);
        const std::string& getBrand() const;
        AbstractComponent& setBrand(const std::string brand);
        const std::string& getImagePath() const;
        AbstractComponent& setImagePath(const std::string image_path);

        virtual void accept(IConstVisitor& visitor) const = 0;
        virtual void accept(IVisitor& visitor) = 0;
};

}

#endif