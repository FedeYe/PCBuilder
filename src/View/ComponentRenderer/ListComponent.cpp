#include "ListComponent.h"

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

    ListComponent::ListComponent() :has_controls(true) {
    }
    
    void ListComponent::visit(const Component::MotherBoard& mother_board) {

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
        	image_object = QPixmap(":/Assets/icons/defaultMB.svg");
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

        QLabel* brand = new QLabel(QString::fromStdString(mother_board.getBrand()));
        brand->setObjectName("Brand");
        infobox->addWidget(brand);

        QLabel* socket = new QLabel("Socket: " + QString::fromStdString(mother_board.getSocket()));
        socket->setObjectName("Socket");
        infobox->addWidget(socket);

        QLabel* price = new QLabel("Price: " + QString::number(mother_board.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        hbox->addLayout(buttonsbox);

        QHBoxLayout* controlsbox = new QHBoxLayout();
        controlsbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        buttonsbox->addLayout(controlsbox);
        if(has_controls) {  
            view_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/info.png")), "");
            view_button->setObjectName("view-button");
            controlsbox->addWidget(view_button);

            edit_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/edit.png")), "");
            edit_button->setObjectName("edit-button");
            controlsbox->addWidget(edit_button);

            delete_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/delete.png")), "");
            delete_button->setObjectName("delete-button");
            controlsbox->addWidget(delete_button);
        }
        
        buttonsbox->addStretch();

        add_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/addToCart.png")), "AddToCart");
        add_button->setObjectName("add-button");
        buttonsbox->addWidget(add_button);
    }


    void ListComponent::visit(const Component::CPU& cpu) {

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
        	image_object = QPixmap(":/Assets/icons/defaultCPU.svg");
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

        QLabel* brand = new QLabel(QString::fromStdString(cpu.getBrand()));
        brand->setObjectName("Brand");
        infobox->addWidget(brand);

        QLabel* coreClock = new QLabel("CoreClock: " + QString::number(cpu.getCoreclock()) + " GHz");
        coreClock->setObjectName("Coreclock");
        infobox->addWidget(coreClock);

        QLabel* price = new QLabel("Price: " + QString::number(cpu.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        hbox->addLayout(buttonsbox);

        QHBoxLayout* controlsbox = new QHBoxLayout();
        controlsbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        buttonsbox->addLayout(controlsbox);
        if(has_controls) {  
            view_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/info.png")), "");
            view_button->setObjectName("view-button");
            controlsbox->addWidget(view_button);

            edit_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/edit.png")), "");
            edit_button->setObjectName("edit-button");
            controlsbox->addWidget(edit_button);

            delete_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/delete.png")), "");
            delete_button->setObjectName("delete-button");
            controlsbox->addWidget(delete_button);
        }
        
        buttonsbox->addStretch();

        add_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/addToCart.png")), "AddToCart");
        add_button->setObjectName("add-button");
        buttonsbox->addWidget(add_button);
    }


    void ListComponent::visit(const Component::GPU& gpu) {
        
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
        	image_object = QPixmap(":/Assets/icons/defaultGPU.svg");
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

        QLabel* brand = new QLabel(QString::fromStdString(gpu.getBrand()));
        brand->setObjectName("Brand");
        infobox->addWidget(brand);

        QLabel* NVRam = new QLabel("N° VRam: " + QString::number(gpu.getNumVRam()) + "GB" );
        NVRam->setObjectName("Number of VRam");
        infobox->addWidget(NVRam);

        QLabel* price = new QLabel("Price: " + QString::number(gpu.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        if(!gpu.isAvailable()) {
            QLabel* availability = new QLabel("Out of stock");
            availability->setObjectName("availability");
            infobox->addWidget(availability);
        }

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        hbox->addLayout(buttonsbox);

        QHBoxLayout* controlsbox = new QHBoxLayout();
        controlsbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        buttonsbox->addLayout(controlsbox);
        if(has_controls) {  
            view_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/info.png")), "");
            view_button->setObjectName("view-button");
            controlsbox->addWidget(view_button);

            edit_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/edit.png")), "");
            edit_button->setObjectName("edit-button");
            controlsbox->addWidget(edit_button);

            delete_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/delete.png")), "");
            delete_button->setObjectName("delete-button");
            controlsbox->addWidget(delete_button);
        }
        
        buttonsbox->addStretch();

        add_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/addToCart.png")), "AddToCart");
        add_button->setObjectName("add-button");
        buttonsbox->addWidget(add_button);
        if(!gpu.isAvailable()) {
            add_button->setDown(true);
            add_button->setIcon(QIcon(QPixmap(":/Assets/icons/notAvailable.png")));
            add_button->setText("Not Available");
        }  
    }
    
    void ListComponent::visit(const Component::PSU& psu) {

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
        	image_object = QPixmap(":/Assets/icons/defaultPSU.svg");
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

        QLabel* brand = new QLabel(QString::fromStdString(psu.getBrand()));
        brand->setObjectName("Brand");
        infobox->addWidget(brand);

        QLabel* suppliedWatt = new QLabel("Supplied Wattage: " + QString::number(psu.getSuppWatt()));
        suppliedWatt->setObjectName("SuppliedWattage");
        infobox->addWidget(suppliedWatt);

        QLabel* price = new QLabel("Price: " + QString::number(psu.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        hbox->addLayout(buttonsbox);

        QHBoxLayout* controlsbox = new QHBoxLayout();
        controlsbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        buttonsbox->addLayout(controlsbox);
        if(has_controls) {  
            view_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/info.png")), "");
            view_button->setObjectName("view-button");
            controlsbox->addWidget(view_button);

            edit_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/edit.png")), "");
            edit_button->setObjectName("edit-button");
            controlsbox->addWidget(edit_button);

            delete_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/delete.png")), "");
            delete_button->setObjectName("delete-button");
            controlsbox->addWidget(delete_button);
        }
        
        buttonsbox->addStretch();

        add_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/addToCart.png")), "AddToCart");
        add_button->setObjectName("add-button");
        buttonsbox->addWidget(add_button);
    }

    void ListComponent::visit(const Component::RAM& ram) {

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
        	image_object = QPixmap(":/Assets/icons/defaultRAM.svg");
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

        QLabel* brand = new QLabel(QString::fromStdString(ram.getBrand()));
        brand->setObjectName("Brand");
        infobox->addWidget(brand);

        QLabel* capacity = new QLabel("Capacity: " + QString::fromStdString(ram.getCapacity()));
        capacity->setObjectName("Capacity");
        infobox->addWidget(capacity);

        QLabel* price = new QLabel("Price: " + QString::number(ram.getPrice()) + "€");
        price->setObjectName("Price");
        infobox->addWidget(price);

        hbox->addStretch();

        //pannello bottoni
        QVBoxLayout* buttonsbox = new QVBoxLayout();
        buttonsbox->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        hbox->addLayout(buttonsbox);

        QHBoxLayout* controlsbox = new QHBoxLayout();
        controlsbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        buttonsbox->addLayout(controlsbox);
        if(has_controls) {  
            view_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/info.png")), "");
            view_button->setObjectName("view-button");
            controlsbox->addWidget(view_button);

            edit_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/edit.png")), "");
            edit_button->setObjectName("edit-button");
            controlsbox->addWidget(edit_button);

            delete_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/delete.png")), "");
            delete_button->setObjectName("delete-button");
            controlsbox->addWidget(delete_button);
        }
        
        buttonsbox->addStretch();

        add_button = new QPushButton(QIcon(QPixmap(":/Assets/icons/addToCart.png")), "AddToCart");
        add_button->setObjectName("add-button");
        buttonsbox->addWidget(add_button);
    }

    bool ListComponent::hasControls() const {
        return has_controls;
    }

    void ListComponent::setHasControls(const bool has_controls) {
        this->has_controls = has_controls;
    }

    QWidget* ListComponent::getWidget() const {
        return widget;
    }

    QPushButton* ListComponent::getViewButton() const {
        return view_button;
    }

    QPushButton* ListComponent::getEditButton() const {
        return edit_button;
    }

    QPushButton* ListComponent::getDeleteButton() const {
        return delete_button;
    }
    
    QPushButton* ListComponent::getAddButton() const {
        return add_button;
    }

    QPushButton* ListComponent::getRemoveButton() const {
        return remove_button;
    }

    QPushButton* ListComponent::getSearchButton() const {
        return search_button;
    }

}
}
