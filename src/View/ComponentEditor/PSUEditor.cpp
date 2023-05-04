#include "PSUEditor.h"

#include <QFormLayout>

#include "../../Component/PSU.h"

namespace View
{
    namespace ComponentEditor
    {

        PSUEditor::PSUEditor(QWidget *parent)
            : AbstractComponentEditor(parent)
        {
            QFormLayout *form = new QFormLayout(this);
            form->setObjectName("psu-form");
            form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

            suppliedWatt_input = new QSpinBox();
            suppliedWatt_input->setObjectName("suppliedWatt-input");
            suppliedWatt_input->setMinimum(0);
            suppliedWatt_input->setMaximum(INT_MAX);
            form->addRow("Supplied Watt", suppliedWatt_input);

            efficiency_input = new QSpinBox();
            efficiency_input->setObjectName("efficiency-input");
            efficiency_input->setMinimum(0);
            efficiency_input->setMaximum(INT_MAX);
            form->addRow("Efficiency", efficiency_input);

            /* QUELLO PER MODULAR  */
            modular_input = new QComboBox();
            modular_input->setObjectName("modular-input");
            modular_input->addItem("Modular");                  // index 1
            modular_input->addItem("Not Modular");              // index 2     -> per la conversione in bool necessita quindi -1
            form->addRow("is Modular", modular_input);

        }

        PSUEditor::~PSUEditor()
        {
        }

        Component::AbstractComponent *PSUEditor::create(
            const unsigned int identifier,
            const QString &name,
            const double price,
            const QString &brand,
            const QString &image_path) const
        {
            return new Component::PSU(
                identifier,
                name.toStdString(),
                price,
                brand.toStdString(),
                image_path.toStdString(),
                suppliedWatt_input->value(),
                efficiency_input->value(),
                (modular_input->currentIndex())-1); // devo mettere anche quello per bool
        }

        void PSUEditor::setValues(const Component::PSU &psu)
        {
            suppliedWatt_input->setValue(psu.getSuppWatt());
            efficiency_input->setValue(psu.getEfficiency());
            modular_input->setCurrentIndex(psu.isModular()+1);
        }

    }
}
