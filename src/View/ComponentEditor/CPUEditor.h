#ifndef VIEW_COMPONENT_EDITOR_CPU_H
#define VIEW_COMPONENT_EDITOR_CPU_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

#include "AbstractComponentEditor.h"

namespace View
{
    namespace ComponentEditor
    {

        class CPUEditor : public AbstractComponentEditor
        {
        private:
            QLineEdit *chipset_input;
            QSpinBox *numCores_input;
            QSpinBox *threads_input;
            QDoubleSpinBox *coreclock_input;
            QDoubleSpinBox *boostclock_input;
            QSpinBox *cache_input;

        public:
            CPUEditor(QWidget *parent = 0);
            virtual ~CPUEditor();
            virtual Component::AbstractComponent *create(
                const unsigned int identifier,
                const QString &name,
                const double price,
                const QString &brand,
                const QString &image_path) const;
            void setValues(const Component::CPU &cpu);
        };

    }
}

#endif