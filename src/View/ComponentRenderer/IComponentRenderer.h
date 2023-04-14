#ifndef VIEW_COMPONENT_RENDERER_I_COMPONENT_RENDERER_H 
#define VIEW_COMPONENT_RENDERER_I_COMPONENT_RENDERER_H

#include <QWidget>
#include <QPushButton>

#include "../../Component/AbstractComponent.h"
#include "../../Component/IConstVisitor.h"

namespace View {
namespace ComponentRenderer {

class IComponentRenderer: public Component::IConstVisitor {
        public:
            virtual QWidget* getWidget() const = 0;
            virtual QPushButton* getViewButton() const = 0;
            virtual QPushButton* getEditButton() const = 0;
            virtual QPushButton* getDeleteButton() const = 0;       // delete elimina dal catalogo(dataset)
            virtual QPushButton* getAddButton() const = 0;
            virtual QPushButton* getRemoveButton() const = 0;       // remove toglie dal carello
            virtual QPushButton* getSearchButton() const = 0;
    };
}
}

#endif
