#include "AbstractComponentEditor.h"

#include <QWidget>

namespace View
{
    namespace ComponentEditor
    {

        AbstractComponentEditor::AbstractComponentEditor(QWidget *parent)
            : QWidget(parent)
        {
        }

        AbstractComponentEditor::~AbstractComponentEditor()
        {
        }

    }
}