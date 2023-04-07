#ifndef VIEW_EDIT_WIDGET_H
#define VIEW_EDIT_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include <QVector>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QStackedLayout>

#include "MainWindow.h"
#include "../Component/AbstractComponent.h"
// #include "ComponentEditor/AbstractComponentEditor.h"   da implementare
#include "../Component/Repository/JsonRepository.h"

namespace View
{

    class EditWidget : public QWidget
    {
        Q_OBJECT
    private:
        MainWindow* main_window;
        const Component::AbstractComponent *subject;
        QSpinBox* identifier_input;
        QLineEdit* name_input;
        QDoubleSpinBox* price_input;
        QLineEdit* brand_input;
        QLineEdit* image_input;
        QStackedLayout* stacked_editor;
        QVector<ComponentEditor::AbstractComponentEditor*> editors;

    public:
        EditWidget(
            MainWindow* main_window,
            Component::Repository::JsonRepository* repository,
            const Component::AbstractComponent* subject);

    public slots:
        void selectImage();
        void showType(int index);
        void apply();
    };

}

#endif
