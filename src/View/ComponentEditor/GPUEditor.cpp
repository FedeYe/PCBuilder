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
            form->addRow("number of Porte", numPorte_input);

            numVRam_input = new QSpinBox();
            numVRam_input->setObjectName("numCores-input");
            numVRam_input->setMinimum(0);
            numVRam_input->setMaximum(INT_MAX);
            form->addRow("number of VRam", numVRam_input);

            numVentole_input = new QSpinBox();
            numVentole_input->setObjectName("numVentole-input");
            numVentole_input->setMinimum(0);
            numVentole_input->setMaximum(INT_MAX);
            form->addRow("number of Ventole", numVentole_input);

            /* QUELLO PER AVAILABILITY */
            availability_input = new QComboBox();
            availability_input->setObjectName("availability-input");
            availability_input->addItem("Not available");                               // index 1
            availability_input->addItem("Available");                                   // index 2     -> per la conversione in bool necessita quindi -1
            form->addRow("is Available", availability_input);

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
                price,
                brand.toStdString(),
                image_path.toStdString(),
                numPorte_input->value(),
                numVRam_input->value(),
                numVentole_input->value(),
                (availability_input->currentIndex()-1)); // devo mettere anche quello per bool
        }

        void GPUEditor::setValues(const Component::GPU &gpu)
        {
            numPorte_input->setValue(gpu.getNumPorte());
            numVRam_input->setValue(gpu.getNumVRam());
            numVentole_input->setValue(gpu.getNumVentole());
            availability_input->setCurrentIndex(gpu.isAvailable()+1);
        }

    }
}
