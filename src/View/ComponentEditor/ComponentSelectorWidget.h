#ifndef VIEW_COMPONENT_EDITOR_COMPONENT_SELECTOR_WIDGET_H
#define VIEW_COMPONENT_EDITOR_COMPONENT_SELECTOR_WIDGET_H

#include <QWidget>
#include <QSpinBox>

#include "../../Component/Repository/JsonRepository.h"
#include "../ComponentRenderer/ListComponent.h"

namespace View
{
    namespace ComponentEditor
    {

        class ComponentSelectorWidget : public QWidget
        {
            Q_OBJECT
        private:
            Component::Repository::JsonRepository *repository;
            QSpinBox *identifier_input;
            ComponentRenderer::ListComponent renderer;
            QVBoxLayout *vbox;
            QWidget *widget;

        public:
            ComponentSelectorWidget(
                Component::Repository::JsonRepository *repository,
                QWidget *parent = 0);

            int getIdentifier() const;
            Component::AbstractComponent *getComponent() const;
            void setIdentifier(const int identifier);

        public slots:
            void updateView(int identifier);
        };

    }
}

#endif