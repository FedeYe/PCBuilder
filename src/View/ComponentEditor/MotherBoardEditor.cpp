#include "MotherBoardEditor.h"

#include <QFormLayout>

#include "../../Component/MotherBoard.h"

namespace View
{
    namespace ComponentEditor
    {

        MotherBoardEditor::MotherBoardEditor(QWidget *parent)
            : AbstractComponentEditor(parent)
        {
            QFormLayout *form = new QFormLayout(this);
            form->setObjectName("mother-board-form");
            form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

            socket_input = new QLineEdit();
            socket_input->setObjectName("socket-input");
            form->addRow("Socket", socket_input);

            chipset_input = new QLineEdit();
            chipset_input->setObjectName("chipset-input");
            form->addRow("Chipset", chipset_input);

            generation_input = new QLineEdit();
            generation_input->setObjectName("generation-input");
            form->addRow("Generation", generation_input);

            numRAM_input = new QSpinBox();
            numRAM_input->setObjectName("numRAM-input");
            numRAM_input->setMinimum(0);
            numRAM_input->setMaximum(INT_MAX);
            form->addRow("number of RAM", numRAM_input);

            numSSD_input = new QSpinBox();
            numSSD_input->setObjectName("numSSD-input");
            numSSD_input->setMinimum(0);
            numSSD_input->setMaximum(INT_MAX);
            form->addRow("number of SSD", numSSD_input);
        }

        MotherBoardEditor::~MotherBoardEditor()
        {
        }

        Component::AbstractComponent *MotherBoardEditor::create(
            const unsigned int identifier,
            const QString &name,
            const double price,
            const QString &brand,
            const QString &image_path) const
        {
            return new Component::MotherBoard(
                identifier,
                name.toStdString(),
                price,
                brand.toStdString(),
                image_path.toStdString(),             
                socket_input->text().toStdString(),
                chipset_input->text().toStdString(),
                generation_input->text().toStdString(),
                numRAM_input->value(),
                numSSD_input->value());
        }

        void MotherBoardEditor::setValues(const Component::MotherBoard &mother_board)
        {
            socket_input->setText(QString::fromStdString(mother_board.getSocket()));
            chipset_input->setText(QString::fromStdString(mother_board.getChipset()));
            generation_input->setText(QString::fromStdString(mother_board.getGeneration()));
            numRAM_input->setValue(mother_board.getNumRAM());
            numSSD_input->setValue(mother_board.getNumSSD());
        }

    }
}
