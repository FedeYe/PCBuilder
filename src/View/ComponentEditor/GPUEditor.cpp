#include "GPUEditor.h"

#include <QFormLayout>

#include "../../Component/GPU.h"

namespace View
{
    namespace ComponentEditor
    {

        GPUEditor::GPUEditor(QWidget *parent)
            : AbstractComponentEditor(parent)
        {
            QFormLayout *form = new QFormLayout(this);
            form->setObjectName("gpu-form");
            form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

            numPorte_input = new QSpinBox();
            numPorte_input->setObjectName("numPorte-input");
            numPorte_input->setMinimum(0);
            numPorte_input->setMaximum(INT_MAX);
            numPorte_input->addRow("number of Porte", numPorte_input);

            numCores_input = new QSpinBox();
            numCores_input->setObjectName("numCores-input");
            numCores_input->setMinimum(0);
            numCores_input->setMaximum(INT_MAX);
            form->addRow("number of Cores", numCores_input);

            numVentole_input = new QSpinBox();
            numVentole_input->setObjectName("numVentole-input");
            numVentole_input->setMinimum(0);
            numVentole_input->setMaximum(INT_MAX);
            form->addRow("number of Ventole", numVentole_input);

            /* QUELLO PER AVAIABILITY
            availability_input = new QComboBox();
            availability_input->setObjectName("availability-input");
            availability_input->addItem("si");
            availability_input->addItem("no");
            form->addRow("is Available", availability_input);
            */
        }

        GPUEditor::~GPUEditor()
        {
        }

        Component::AbstractComponent *GPUEditor::create(
            const unsigned int identifier,
            const QString &name,
            const double price,
            const QString &brand,
            const QString &image_path) const
        {
            return new Component::GPU(
                identifier,
                name.toStdString(),
                brand.toStdString(),
                price,
                image_path.toStdString(),
                numPorte_input->value(),
                numCores_input->value(),
                numVentole_input->value(),
                avaiability_input->currentIndex()); // devo mettere anche quello per bool
        }

        void GPU::setValues(const Component::GPU &gpu)
        {
            numPorte_input->setValue(gpu.getNumPorte());
            numCores_input->setValue(gpu.getNumCores());
            numVentole_input->setValue(gpu.getNumVentole());
            // avaiability_input->setCurrentIndex(gpu.isAvailable());
        }

    }
}
