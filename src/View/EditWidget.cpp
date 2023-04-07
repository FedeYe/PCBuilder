#include "EditWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>

// #include "ShoppingCartWidget.h"
#include "TypeSelector.h"
// #include "ComponentEditor/MotherBoardEditor.h"
// #include "ComponentEditor/CPUEditor.h"
// #include "ComponentEditor/GPUEditor.h"
// #include "ComponentEditor/PSUEditor.h"
// #include "ComponentEditor/RAMEditor.h"
// #include "ComponentEditor/ComponentInjector.h"

namespace View
{

    EditWidget::EditWidget(
        MainWindow* main_window,
        Component::Repository::JsonRepository* repository,
        const Component::AbstractComponent* subject)
        : main_window(main_window), subject(subject)
    {
        QVBoxLayout* vbox = new QVBoxLayout(this);
        vbox->setObjectName("widget-edit");
        vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

        QLabel* title = new QLabel("Component properties"); // dobbiamo scegliere che nome usare
        title->setObjectName("title");
        vbox->addWidget(title);

        QFormLayout* form = new QFormLayout();
        form->setObjectName("properties-form");
        form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
        vbox->addLayout(form);

        // aggiungo riga per identifier a form
        identifier_input = new QSpinBox();
        identifier_input->setObjectName("identifier-input");
        identifier_input->setMinimum(1);
        identifier_input->setMaximum(INT_MAX);
        if (subject != nullptr)
        {
            identifier_input->setValue(subject->getIdentifier());
        }
        form->addRow("identifier", identifier_input);

        // aggiungo name
        name_input = new QLineEdit();
        name_input->setObjectName("name-input");
        if (subject != nullptr)
        {
            name_input->setText(QString::fromStdString(subject->getName()));
        }
        form->addRow("name", name_input);

        // aggiungo price  NON USA METODO GET -> ANCHE DA PROF COSI (FILE SimpleEditor.cpp)
        price_input = new QDoubleSpinBox();
        price_input->setObjectName("price-input");
        price_input->setMinimum(0.0);
        price_input->setMaximum(__DBL_MAX__); // da rivedere
        form->addRow("price", price_input);

        // aggiungo brand
        brand_input = new QLineEdit();
        brand_input->setObjectName("brand-input");
        if (subject != nullptr)
        {
            brand_input->setText(QString::fromStdString(subject->getBrand()));
        }
        form->addRow("brand", brand_input);

        // aggiungo immagine
        image_input = new QLineEdit();
        image_input->setObjectName("image-input");
        if (subject != nullptr)
        {
            image_input->setText(QString::fromStdString(subject->getImagePath()));
        }
        image_selector->addWidget(image_input);

        // aggiung bottone per selezionare immagine
        QPushButton *select_image_button = new QPushButton("Select");
        select_image_button->setObjectName("select-image-button");
        image_selector->addWidget(select_image_button);

        // combobox per selezionare tipo
        QComboBox* type_input = new QComboBox();
        type_input->setObjectName("type-input");
        type_input->addItem("mother board"); // credo resti Item
        type_input->addItem("cpu");
        type_input->addItem("gpu");
        type_input->addItem("psu");
        type_input->addItem("ram");
        if (subject != nullptr)
        {
            TypeSelector type_selector(type_input);
            subject->accept(type_selector);
        }
        form->addRow("type", type_input);

        ComponentEditor::MotherBoardEditor* mother_board_editor = new ComponentEditor::MotherBoardEditor();
        stacked_editor->addWidget(mother_board_editor);
        editors.push_back(mother_board_editor);

        ComponentEditor::CPUEditor *cpu_editor = new ComponentEditor::CPUEditor();
        stacked_editor->addWidget(cpu_editor);
        editors.push_back(cpu_editor);

        ComponentEditor::GPUEditor *gpu_editor = new ComponentEditor::GPUEditor();
        stacked_editor->addWidget(gpu_editor);
        editors.push_back(gpu_editor);

        ComponentEditor::PSUEditor *psu_editor = new ComponentEditor::PSUEditor();
        stacked_editor->addWidget(psu_editor);
        editors.push_back(psu_editor);

        ComponentEditor::RAMEditor *ram_editor = new ComponentEditor::RAMEditor();
        stacked_editor->addWidget(ram_editor);
        editors.push_back(ram_editor);

        if (subject != nullptr)
        {
            ComponentEditor::ComponentInjector component_injector(
                *mother_board_editor,
                *cpu_editor,
                *gpu_editor,
                *psu_editor,
                *ram_editor);
            subject->accept(component_injector);
        }
        showType(type_input->currentIndex());

        vbox->addStretch();

        QHBoxLayout* actions = new QHBoxLayout();
        actions->setObjectName("actions");
        actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        vbox->addLayout(actions);

        actions->addStretch();

        QPushButton* apply_button = new QPushButton("Apply");
        apply_button->setObjectName("apply");
        actions->addWidget(apply_button);

        QPushButton* cancel_button = new QPushButton("Cancel");
        cancel_button->setObjectName("cancel");
        actions->addWidget(cancel_button);

        // Connects signals
        connect(select_image_button, &QPushButton::clicked, this, &EditWidget::selectImage);
        connect(type_input, qOverload<int>(&QComboBox::currentIndexChanged), this, &EditWidget::showType);
        connect(apply_button, &QPushButton::clicked, this, &EditWidget::apply);
        connect(cancel_button, &QPushButton::clicked, main_window->getShoppingCartWidget(), &ShoppingCartWidget::search);
    }

    void EditWidget::selectImage()
    {
        QString path = QFileDialog::getOpenFileName(
            this,
            "Select image",
            "./",
            "Image files (*.jpg *.jpeg *.png)");
        if (path.isEmpty())
        {
            return;
        }
        image_input->setText(path);
    }

    void EditWidget::showType(int index)
    {
        stacked_editor->setCurrentIndex(index);
    }

    void EditWidget::apply()
    {
        int identifier = identifier_input->value();
        QString name = name_input->text();
        double price = price_imput->value(); // non sono sicuro ma dovrebbere essere ok
        QString brand = brand_input->toPlainText();
        QString image_path = image_input->text();
        ComponentEditor::AbstractComponentEditor* editor = editors[stacked_editor->currentIndex()];
        Component::AbstractComponent* component = editor->create(identifier, name, price, brand, image_path);
        main_window->getRepository()->update(component);
        main_window->reloadData();
        // main_window->getShoppingCartWidget()->search();
    }
}
