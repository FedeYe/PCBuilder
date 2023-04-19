#include "CartComponent.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>

#include "../../Component/MotherBoard.h"
#include "../../Component/CPU.h"
#include "../../Component/GPU.h"
#include "../../Component/PSU.h"
#include "../../Component/RAM.h"

namespace View {
namespace ComponentRenderer {

    CartComponent::CartComponent() {
    }

    void CartComponent::visit(const Component::MotherBoard& mother_board) {
        widget = new QWidget();
        widget->setObjectName("list-component-motherboard");
        view_button = nullptr;
        edit_button = nullptr;
        delete_button = nullptr;
        add_button = nullptr;
        remove_button = nullptr;
        search_button = nullptr;

        QHBoxLayout* hbox = new QHBoxLayout(widget);
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QPixmap image_object(mother_board.getImagePath().c_str());
        if (!image_object) {
        	image_object = QPixmap(":/Assets/images/placeholder.png");
        }
        QLabel* image = new QLabel();
        image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
        hbox->addWidget(image);

        //pannello informazioni prodotto
        QVBoxLayout* infobox = new QVBoxLayout();
        infobox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        hbox->addLayout(infobox);

        QLabel* name = new QLabel(QString::fromStdString(mother_board.getName()));
        name->setObjectName("Name");
        name->setWordWrap(true);
        infobox->addWidget(name);

        QLabel* price = new QLabel("Price: " + QString::number(mother_board.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignTop);
        hbox->addLayout(buttonsbox);

        remove_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/removeFromCart.png")), "");
        remove_button->setObjectName("remove-button");
        buttonsbox->addWidget(remove_button);

        buttonsbox->addStretch();

        search_button = new QPushButton("Cambia");
        search_button->setObjectName("search_button");
        buttonsbox->addWidget(search_button);
    }
    
    void CartComponent::visit(const Component::CPU& cpu) {

        widget = new QWidget();
        widget->setObjectName("list-component-cpu");
        view_button = nullptr;
        edit_button = nullptr;
        delete_button = nullptr;
        add_button = nullptr;
        remove_button = nullptr;
        search_button = nullptr;

        QHBoxLayout* hbox = new QHBoxLayout(widget);
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QPixmap image_object(cpu.getImagePath().c_str());
        if (!image_object) {
        	image_object = QPixmap(":/Assets/images/placeholder.png");
        }
        QLabel* image = new QLabel();
        image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
        hbox->addWidget(image);

        //pannello informazioni prodotto
        QVBoxLayout* infobox = new QVBoxLayout();
        infobox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        hbox->addLayout(infobox);

        QLabel* name = new QLabel(QString::fromStdString(cpu.getName()));
        name->setObjectName("Name");
        name->setWordWrap(true);
        infobox->addWidget(name);

        QLabel* price = new QLabel("Price: " + QString::number(cpu.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignTop);
        hbox->addLayout(buttonsbox);

        remove_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/removeFromCart.png")), "");
        remove_button->setObjectName("remove-button");
        buttonsbox->addWidget(remove_button);

        buttonsbox->addStretch();

        search_button = new QPushButton("Cambia");
        search_button->setObjectName("search_button");
        buttonsbox->addWidget(search_button);
    }
    
    void CartComponent::visit(const Component::GPU& gpu) {

        widget = new QWidget();
        widget->setObjectName("list-component-cpu");
        view_button = nullptr;
        edit_button = nullptr;
        delete_button = nullptr;
        add_button = nullptr;
        remove_button = nullptr;
        search_button = nullptr;

        QHBoxLayout* hbox = new QHBoxLayout(widget);
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QPixmap image_object(gpu.getImagePath().c_str());
        if (!image_object) {
        	image_object = QPixmap(":/Assets/images/placeholder.png");
        }
        QLabel* image = new QLabel();
        image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
        hbox->addWidget(image);

        //pannello informazioni prodotto
        QVBoxLayout* infobox = new QVBoxLayout();
        infobox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        hbox->addLayout(infobox);

        QLabel* name = new QLabel(QString::fromStdString(gpu.getName()));
        name->setObjectName("Name");
        name->setWordWrap(true);
        infobox->addWidget(name);

        QLabel* price = new QLabel("Price: " + QString::number(gpu.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignTop);
        hbox->addLayout(buttonsbox);

        remove_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/removeFromCart.png")), "");
        remove_button->setObjectName("remove-button");
        buttonsbox->addWidget(remove_button);

        buttonsbox->addStretch();

        search_button = new QPushButton("Cambia");
        search_button->setObjectName("search_button");
        buttonsbox->addWidget(search_button);
    }
    
    void CartComponent::visit(const Component::PSU& psu) {

        widget = new QWidget();
        widget->setObjectName("list-component-psu");
        view_button = nullptr;
        edit_button = nullptr;
        delete_button = nullptr;
        add_button = nullptr;
        remove_button = nullptr;
        search_button = nullptr;

        QHBoxLayout* hbox = new QHBoxLayout(widget);
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QPixmap image_object(psu.getImagePath().c_str());
        if (!image_object) {
        	image_object = QPixmap(":/Assets/images/placeholder.png");
        }
        QLabel* image = new QLabel();
        image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
        hbox->addWidget(image);

        //pannello informazioni prodotto
        QVBoxLayout* infobox = new QVBoxLayout();
        infobox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        hbox->addLayout(infobox);

        QLabel* name = new QLabel(QString::fromStdString(psu.getName()));
        name->setObjectName("Name");
        name->setWordWrap(true);
        infobox->addWidget(name);

        QLabel* price = new QLabel("Price: " + QString::number(psu.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignTop);
        hbox->addLayout(buttonsbox);

        remove_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/removeFromCart.png")), "");
        remove_button->setObjectName("remove-button");
        buttonsbox->addWidget(remove_button);

        buttonsbox->addStretch();

        search_button = new QPushButton("Cambia");
        search_button->setObjectName("search_button");
        buttonsbox->addWidget(search_button);
    }
    
    void CartComponent::visit(const Component::RAM& ram) {

        widget = new QWidget();
        widget->setObjectName("list-component-ram");
        view_button = nullptr;
        edit_button = nullptr;
        delete_button = nullptr;
        add_button = nullptr;
        remove_button = nullptr;
        search_button = nullptr;

        QHBoxLayout* hbox = new QHBoxLayout(widget);
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QPixmap image_object(ram.getImagePath().c_str());
        if (!image_object) {
        	image_object = QPixmap(":/Assets/images/placeholder.png");
        }
        QLabel* image = new QLabel();
        image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
        hbox->addWidget(image);

        //pannello informazioni prodotto
        QVBoxLayout* infobox = new QVBoxLayout();
        infobox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        hbox->addLayout(infobox);

        QLabel* name = new QLabel(QString::fromStdString(ram.getName()));
        name->setObjectName("Name");
        name->setWordWrap(true);
        infobox->addWidget(name);

        QLabel* capacity = new QLabel("Capacity: " + QString::fromStdString(ram.getCapacity()));
        capacity->setObjectName("Capacity");
        infobox->addWidget(capacity);

        QLabel* price = new QLabel("Price: " + QString::number(ram.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignTop);
        hbox->addLayout(buttonsbox);

        remove_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/removeFromCart.png")), "");
        remove_button->setObjectName("remove-button");
        buttonsbox->addWidget(remove_button);

        buttonsbox->addStretch();

        search_button = new QPushButton("Cambia");
        search_button->setObjectName("search_button");
        buttonsbox->addWidget(search_button);
    }


    
    QWidget* CartComponent::getWidget() const{
        return widget;
    }
    
    QPushButton* CartComponent::getViewButton() const {
        return view_button;
    }       
    
    QPushButton* CartComponent::getEditButton() const {
        return edit_button;
    }      
    
    QPushButton* CartComponent::getDeleteButton() const {
        return delete_button;
    }       
    
    QPushButton* CartComponent::getAddButton() const {
        return add_button;
    }         
    
    QPushButton* CartComponent::getRemoveButton() const {      // remove toglie dal carello
        return remove_button;
    }
    
    QPushButton* CartComponent::getSearchButton() const {
        return search_button;
    }    

}
}
