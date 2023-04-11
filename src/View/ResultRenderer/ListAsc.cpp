#include "ListAsc.h"

namespace View
{
    namespace ResultRenderer
    {

        void ListAsc::render(QGridLayout *grid, Engine::ResultSet &result, QVector<WidgetLookup> *lookup)
        {
            unsigned int index = 0;
            result.priceASort(); // per ordinamento crescente
            for (
                std::vector<Engine::ComponentShown>::const_iterator it = result.getShownItems().begin();
                it != result.getShownItems().end();
                it++)
            {
                it->getComponent()->accept(list_component);
                QWidget *widget = list_component.getWidget();
                grid->addWidget(widget, index, 0);
                lookup->push_back(WidgetLookup(
                    it->getComponent(),
                    widget,
                    list_component.getViewButton(), // che roba è list item? --> da itemRenderes
                    list_component.getEditButton(),
                    list_component.getDeleteButton()));
                index++;
            }
        }

    }
}