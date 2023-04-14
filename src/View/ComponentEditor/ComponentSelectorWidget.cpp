#include "ComponentSelectorWidget.h"

#include <stdexcept>
#include <QVBoxLayout>

namespace View
{
    namespace ComponentEditor
    {

        ComponentSelectorWidget::ComponentSelectorWidget(
            Component::Repository::JsonRepository *repository,
            QWidget *parent)
            : QWidget(parent), repository(repository)
        {
            vbox = new QVBoxLayout(this);
            vbox->setObjectName("component-selector");
            vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

            identifier_input = new QSpinBox();
            identifier_input->setObjectName("identifier-input");
            identifier_input->setMinimum(1);
            identifier_input->setMaximum(INT_MAX);
            vbox->addWidget(identifier_input);
            widget = nullptr;
            updateView(identifier_input->value());

            // Connect signals
            connect(identifier_input, QOverload<int>::of(&QSpinBox::valueChanged), this, &ComponentSelectorWidget::updateView);
        }

        int ComponentSelectorWidget::getIdentifier() const
        {
            return identifier_input->value();
        }

        Component::AbstractComponent *ComponentSelectorWidget::getComponent() const
        {
            return repository->read(getIdentifier());
        }

        void ComponentSelectorWidget::updateView(int identifier)
        {
            try
            {
                if (widget != nullptr)
                {
                    delete widget;
                }
                Component::AbstractComponent *component = repository->read(identifier);
                renderer.setHasControls(false);
                component->accept(renderer);
                widget = renderer.getWidget();
                vbox->addWidget(widget);
            }
            catch (const std::out_of_range &e) // a che  serve???
            {
                widget = nullptr;
            }
        }

        void ComponentSelectorWidget::setIdentifier(const int identifier)
        {
            identifier_input->setValue(identifier);
        }

    }
}