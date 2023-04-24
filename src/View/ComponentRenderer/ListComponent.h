#ifndef VIEW_COMPONENT_RENDERER_LIST_COMPONENT_H
#define VIEW_COMPONENT_RENDERER_LIST_COMPONENT_H

#include "IComponentRenderer.h"
#include "../ResultsWidget.h"

namespace View {
namespace ComponentRenderer {

    class ListComponent : public IComponentRenderer {
        private:
            bool has_controls;
            QWidget* widget;
            QPushButton* view_button;
            QPushButton* edit_button;
            QPushButton* delete_button;
            QPushButton* add_button;
            QPushButton* remove_button;
            QPushButton* search_button;

        public:
            ListComponent();
        
            virtual void visit(const Component::MotherBoard& mother_board);
            virtual void visit(const Component::CPU& cpu);
            virtual void visit(const Component::GPU& gpu);
            virtual void visit(const Component::PSU& psu);
            virtual void visit(const Component::RAM& ram);

            bool hasControls() const;
            void setHasControls(const bool has_controls);

            virtual QWidget* getWidget() const;
            virtual QPushButton* getViewButton() const;
            virtual QPushButton* getEditButton() const;
            virtual QPushButton* getDeleteButton() const;
            virtual QPushButton* getAddButton() const;
            virtual QPushButton* getRemoveButton() const;        // remove toglie dal carello
            virtual QPushButton* getSearchButton() const;
    };
}
} 

#endif
