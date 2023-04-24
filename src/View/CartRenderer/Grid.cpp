#include "Grid.h"


namespace View {
namespace CartRenderer {

    Grid::Grid(const unsigned int row_s) : row_size(row_s) {

    }

    void Grid::render(QGridLayout *grid, Engine::ShoppingCart &shop_cart, QVector<WidgetLookup> *lookup) {
        unsigned int index = 0;

        for (   Service::Container<const Component::AbstractComponent*>::Node* node = shop_cart.getCartHead();
                node != nullptr;
                node = node->getNext())
        {
            node->getData()->accept(cart_comp);
            QWidget* widget = cart_comp.getWidget();
            index = cart_comp.getTypeComp();                               // mb=0, cpu=1, gpu=2, psu=3, ram=4, +1 for future components.......
            grid->addWidget(widget, index / row_size, index % row_size);
            lookup->push_back(WidgetLookup(
                node->getData(),
                widget,
                cart_comp.getViewButton(), 
                cart_comp.getEditButton(),
                cart_comp.getDeleteButton(),
                cart_comp.getAddButton(),
                cart_comp.getRemoveButton(),
                cart_comp.getSearchButton()
            ));
        }
    }

}
}
