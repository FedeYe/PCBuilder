#ifndef VIEW_RESULT_RENDERER_LIST_DESC_H
#define VIEW_RESULT_RENDERER_LIST_DESC_H

#include "IResultRenderer.h"

#include "../ResultsWidget.h"
#include "../ComponentRenderer/ListComponent.h"  
namespace View
{
    namespace ResultRenderer
    {

        class ListDesc : public IResultRenderer
        {
        private:
            ComponentRenderer::ListComponent list_component;

        public:
            virtual void render(QGridLayout *grid, Engine::ResultSet &result, QVector<WidgetLookup> *lookup);
        }; 

    }
}

#endif
