#ifndef VIEW_COMPONENT_RENDERER_FULL_H
#define VIEW_COMPONENT_RENDERER_FULL_H

#include "IComponentRenderer.h"
#include "ListComponent.h"

namespace View {
namespace ComponentRenderer {

    class Full: public IComponentRenderer {
    private:
        ListComponent list_component;
        QWidget* widget;
        QPushButton* view_button;
        QPushButton* edit_button;
        QPushButton* delete_button;
        QPushButton* add_button;
        QPushButton* remove_button;
        QPushButton* search_button;

    public:
        virtual void visit(const Item::WebPage& web_page);
        virtual void visit(const Item::Simple& simple);
        virtual void visit(const Item::Virtual& virtual_item);
        virtual void visit(const Item::Bundle& bundle);
        virtual QWidget* getWidget() const;
        virtual QPushButton* getViewButton() const;
        virtual QPushButton* getEditButton() const;
        virtual QPushButton* getDeleteButton() const;  
        virtual QPushButton* getAddButton() const;
        virtual QPushButton* getRemoveButton() const;        
        virtual QPushButton* getSearchButton() const;
};

}
}

#endif