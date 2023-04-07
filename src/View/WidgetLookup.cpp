#include "WidgetLookup.h"

namespace View
{

    WidgetLookup::WidgetLookup(
        const Component::AbstractComponent* component,
        QWidget* widget,
        QPushButton* info_button,
        QPushButton* edit_button,
        QPushButton* delete_button)
        : component(component), widget(widget), info_button(info_button), edit_button(edit_button), delete_button(delete_button)
    {
    }

    const Component::AbstractComponent* WidgetLookup::getComponent() const
    {
        return component;
    }

    QWidget* WidgetLookup::getWidget() const
    {
        return widget;
    }

    QPushButton* WidgetLookup::getInfoButton() const
    {
        return info_button;
    }

    QPushButton* WidgetLookup::getEditButton() const
    {
        return edit_button;
    }

    QPushButton* WidgetLookup::getDeleteButton() const
    {
        return delete_button;
    }

}
