#include "RAMEditor.h"

#include <QFormLayout>

#include "../../Component/RAM.h"

namespace View
{
    namespace ComponentEditor
    {

        RAMEditor::RAMEditor(QWidget *parent)
            : AbstractComponentEditor(parent)
        {
            QFormLayout *form = new QFormLayout(this);
            form->setObjectName("ram-form");
            form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

            /*
            capacity_input = new QSpinBox();
            capacity_input->setObjectName("capacity-input");
            capacity_input->setMinimum(0);
            capacity_input->setMaximum(INT_MAX);
            form->addRow("Capacity", capacity_input);
            */

            capacity_input = new QLineEdit("examples: 2x8GB/4x8GB/2x16GB/4x16GB");
            capacity_input->setObjectName("capacity-input");
            form->addRow("Capacity", capacity_input);

            stockSpeed_input = new QSpinBox();
            stockSpeed_input->setObjectName("stockSpeed-input");
            stockSpeed_input->setMinimum(0);
            stockSpeed_input->setMaximum(INT_MAX);
            form->addRow("StockSpeed", stockSpeed_input);

            maxSpeed_input = new QSpinBox();
            maxSpeed_input->setObjectName("maxSpeed-input");
            maxSpeed_input->setMinimum(0);
            maxSpeed_input->setMaximum(INT_MAX);
            form->addRow("MaxSpeed", maxSpeed_input);

            generation_input = new QLineEdit("examples: DDR3/DDR4/DDR5");
            generation_input->setObjectName("generation-input");
            form->addRow("Generation", generation_input);
        }

        RAMEditor::~RAMEditor()
        {
        }

        Component::AbstractComponent *RAMEditor::create(
            const unsigned int identifier,
            const QString &name,
            const double price,
            const QString &brand,
            const QString &image_path) const
        {
            return new Component::RAM(
                identifier,
                name.toStdString(),
                price,
                brand.toStdString(),
                image_path.toStdString(),
                capacity_input->text().toStdString(),
                stockSpeed_input->value(),
                maxSpeed_input->value(),
                generation_input->text().toStdString());
        }

        void RAMEditor::setValues(const Component::RAM &ram)
        {
            capacity_input->setText(QString::fromStdString(ram.getCapacity()));
            stockSpeed_input->setValue(ram.getStockSpeed());
            maxSpeed_input->setValue(ram.getMaxSpeed());
            generation_input->setText(QString::fromStdString(ram.getGeneration()));
        }

    }
}
