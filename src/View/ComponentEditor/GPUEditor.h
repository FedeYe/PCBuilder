#ifndef VIEW_COMPONENT_EDITOR_GPU_H
#define VIEW_COMPONENT_EDITOR_GPU_H

#include <QWidget>
#include <QSpinBox>
#include <QComboBox>

#include "AbstractComponentEditor.h"

namespace View
{
    namespace ComponentEditor
    {

        class GPUEditor : public AbstractComponentEditor
        {
        private:
            QSpinBox *numPorte_input;
            QSpinBox *numVRam_input;
            QSpinBox *numVentole_input;
            QComboBox *availability_input;   //probabilmente sbagliato ma non trovo nella documentazione cosa cazzo usare

        public:
            GPUEditor(QWidget *parent = 0);
            virtual ~GPUEditor();
            virtual Component::AbstractComponent *create(
                const unsigned int identifier,
                const QString &name,
                const double price,
                const QString &brand,
                const QString &image_path) const;
            void setValues(const Component::GPU &gpu);
        };

    }
}

#endif
