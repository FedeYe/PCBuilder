#ifndef VIEW_COMPONENT_RENDERER_CART_COMPONENT_H
#define VIEW_COMPONENT_RENDERER_CART_COMPONENT_H

#include "IComponentRenderer.h"

namespace View {
namespace ComponentRenderer {

    class CartComponent : public IComponentRenderer {
        private:
            QWidget* widget;
            QPushButton* view_button;
            QPushButton* edit_button;
            QPushButton* delete_button;
            QPushButton* add_button;
            QPushButton* remove_button;
            QPushButton* search_button;

        public:
            CartComponent();
        
            virtual void visit(const Component::MotherBoard& mother_board);
            virtual void visit(const Component::CPU& cpu);
            virtual void visit(const Component::GPU& gpu);
            virtual void visit(const Component::PSU& psu);
            virtual void visit(const Component::RAM& ram);

            virtual QWidget* getWidget() const;
            virtual QPushButton* getViewButton() const;         // non serve
            virtual QPushButton* getEditButton() const;         // non serve
            virtual QPushButton* getDeleteButton() const;       // non serve
            virtual QPushButton* getAddButton() const;          // non serve
            virtual QPushButton* getRemoveButton() const;       // remove toglie dal carello
            virtual QPushButton* getSearchButton() const;       
    };
}
} 

#endif