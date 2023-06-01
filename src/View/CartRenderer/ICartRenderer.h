#ifndef VIEW_CART_RENDERER_I_CART_RENDERER_H
#define VIEW_CART_RENDERER_I_CART_RENDERER_H

#include <QGridLayout>

#include "../../Engine/ShoppingCart.h"
#include "../WidgetLookup.h"

namespace View
{
    namespace CartRenderer
    {

        class ICartRenderer
        {
        public:
            virtual ~ICartRenderer() = default;
            virtual void render(QGridLayout *grid, Engine::ShoppingCart& shop_cart, QVector<WidgetLookup> *lookup) = 0;
        };

    }
}

#endif
