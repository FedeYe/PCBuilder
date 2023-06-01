#ifndef VIEW_COMPONENT_EDITOR_MOTHER_BOARD_H
#define VIEW_COMPONENT_EDITOR_MOTHER_BOARD_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>

#include "AbstractComponentEditor.h"

namespace View
{
    namespace ComponentEditor
    {

        class MotherBoardEditor : public AbstractComponentEditor
        {
        private:
            QLineEdit *socket_input;
            QLineEdit *chipset_input;
            QLineEdit *generation_input;
            QSpinBox *numRAM_input;
            QSpinBox *numSSD_input;

        public:
            MotherBoardEditor(QWidget *parent = 0);
            virtual ~MotherBoardEditor();
            virtual Component::AbstractComponent *create(
                const unsigned int identifier,
                const QString &name,
                const double price,
                const QString &brand,
                const QString &image_path) const;
            void setValues(const Component::MotherBoard &mother_board);
        };

    }
}

#endif