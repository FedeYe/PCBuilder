#include "CPUEditor.h"

#include <QFormLayout>
#include <limits>

#include "../../Component/CPU.h"

namespace View
{
    namespace ComponentEditor
    {

        CPUEditor::CPUEditor(QWidget *parent)
            : AbstractComponentEditor(parent)
        {
            QFormLayout *form = new QFormLayout(this);
            form->setObjectName("cpu-form");
            form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

            chipset_input = new QLineEdit();
            chipset_input->setObjectName("chipset-input");
            form->addRow("Chipset", chipset_input);

            numCores_input = new QSpinBox();
            numCores_input->setObjectName("numCores-input");
            numCores_input->setMinimum(0);
            numCores_input->setMaximum(INT_MAX);
            form->addRow("number of Cores", numCores_input);

            threads_input = new QSpinBox();
            threads_input->setObjectName("threads-input");
            threads_input->setMinimum(0);
            threads_input->setMaximum(INT_MAX);
            form->addRow("Threads", threads_input);

            coreclock_input = new QDoubleSpinBox();
            coreclock_input->setObjectName("coreclock-input");
            coreclock_input->setMinimum(0.0);
            coreclock_input->setMaximum(std::numeric_limits<double>::max());
            form->addRow("Coreclock", coreclock_input);

            boostclock_input = new QDoubleSpinBox();
            boostclock_input->setObjectName("boostclock-input");
            boostclock_input->setMinimum(0.0);
            boostclock_input->setMaximum(std::numeric_limits<double>::max());
            form->addRow("Boostclock", boostclock_input);

            cache_input = new QSpinBox();
            cache_input->setObjectName("cache-input");
            cache_input->setMinimum(0);
            cache_input->setMaximum(INT_MAX);
            form->addRow("Cache", cache_input);
        }

        CPUEditor::~CPUEditor()
        {
        }

        Component::AbstractComponent *CPUEditor::create(
            const unsigned int identifier,
            const QString &name,
            const double price,
            const QString &brand,
            const QString &image_path) const
        {
            return new Component::CPU(
                identifier,
                name.toStdString(),
                price,
                brand.toStdString(),
                image_path.toStdString(),
                chipset_input->text().toStdString(),
                numCores_input->value(),
                threads_input->value(),
                coreclock_input->value(),
                boostclock_input->value(),
                cache_input->value());
        }

        void CPUEditor::setValues(const Component::CPU &cpu)
        {
            chipset_input->setText(QString::fromStdString(cpu.getChipset()));
            numCores_input->setValue(cpu.getNumCores());
            threads_input->setValue(cpu.getThreads());
            coreclock_input->setValue(cpu.getCoreclock());
            boostclock_input->setValue(cpu.getBoostclock());
            cache_input->setValue(cpu.getCache());
        }

    }
}
