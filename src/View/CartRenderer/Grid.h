#ifndef VIEW_CART_RENDERER__GRID_H
#define VIEW_CART_RENDERER__GRID_H

#include "ICartRenderer.h"

#include "../ShoppingCartWidget.h"
#include "../ComponentRenderer/CartComponent.h"

namespace View {
namespace CartRenderer {

    class Grid : public ICartRenderer {
        private:
            const unsigned int row_size;
            ComponentRenderer::CartComponent cart_comp;

        public:
            Grid(const unsigned int row_s = 2);
            virtual void render(QGridLayout *grid, Engine::ShoppingCart &shop_cart, QVector<WidgetLookup> *lookup);
    };
}
}

#endif