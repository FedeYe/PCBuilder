#ifndef VIEW_COMPONENT_EDITOR_PSU_H
#define VIEW_COMPONENT_EDITOR_PSU_H

#include <QWidget>
#include <QSpinBox>
// #include <QComboBox>

#include "AbstractComponentEditor.h"

namespace View
{
    namespace ComponentEditor
    {

        class PSUEditor : public AbstractComponentEditor
        {
        private:
            QSpinBox *suppliedWatt_input;
            QSpinBox *efficiency_input;
            QComboBox *modular_input;   //probabilmente sbagliato ma non trovo nella documentazione cosa usare

        public:
            PSUEditor(QWidget *parent = 0);
            virtual ~PSUEditor();
            virtual Component::AbstractComponent *create(
                const unsigned int identifier,
                const QString &name,
                const double price,
                const QString &brand,
                const QString &image_path) const;
            void setValues(const Component::PSU &psu);
        };

    }
}

#endif
