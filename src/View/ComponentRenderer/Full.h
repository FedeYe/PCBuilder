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
        virtual void visit(const Component::MotherBoard& mother_board);
        virtual void visit(const Component::CPU& cpu);
        virtual void visit(const Component::GPU& gpu);
        virtual void visit(const Component::PSU& psu);
        virtual void visit(const Component::RAM& ram);
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
