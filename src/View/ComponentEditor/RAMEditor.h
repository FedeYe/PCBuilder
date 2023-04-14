#ifndef VIEW_COMPONENT_EDITOR_RAM_H
#define VIEW_COMPONENT_EDITOR_RAM_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>

#include "AbstractComponentEditor.h"

namespace View
{
    namespace ComponentEditor
    {

        class RAMEditor : public AbstractComponentEditor
        {
        private:
            QSpinBox *capacity_input;
            QSpinBox *stockSpeed_input;
            QSpinBox *maxSpeed_input;
            QLineEdit *generation_input;

        public:
            RAMEditor(QWidget *parent = 0);
            virtual ~RAMEditor();
            virtual Component::AbstractComponent *create(
                const unsigned int identifier,
                const QString &name,
                const double price,
                const QString &brand,
                const QString &image_path) const;
            void setValues(const Component::RAM &ram);
        };

    }
}

#endif