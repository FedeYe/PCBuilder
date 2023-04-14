#include "ResultWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

#include "ResultRenderer/List.h"

// MODIFICARE NEXT E PREVIOUS COMPONENT

namespace View
{
    ResultsWidget::ResultsWidget(QWidget* parent)
        : QWidget(parent)
    {
        QVBoxLayout* vbox = new QVBoxLayout(this);
        vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

        QHBoxLayout* hbox = new QHBoxLayout();
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        vbox->addLayout(hbox);

        component_name = new QLabel();
        hbox->addWidget(component_name);

        hbox->addStretch();

        QPushButton* order_ascendent = new QPushButton(QIcon(QPixmap(":/Assets/icons/priceasc.png")), "Prezzo crescente");
        hbox->addWidget(order_ascendent);

        QPushButton* order_descendend = new QPushButton(QIcon(QPixmap(":/Assets/icons/pricedesc.png")), "Prezzo decrescente");
        hbox->addWidget(order_descendend);

        QScrollArea* scroll_area = new QScrollArea();
        scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setWidgetResizable(true);
        scroll_area->setWidget(container);
        vbox->addWidget(scroll_area);

        renderer = new ResultRenderer::List();

        /*parte sotto con precedente e next */
        QHBoxLayout* hbox2 = new QHBoxLayout();
        hbox2->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
        vbox->addLayout(hbox2); 

        prev_component = new QPushButton(QIcon(QPixmap(":/Assets/icons/previous.svg")), "Componente Precedente");
        prev_component->setEnabled(false);
        hbox2->addWidget(prev_component);

        next_component = new QPushButton(QIcon(QPixmap(":/Assets/icons/next.svg")), "Componente Successiva");
        next_component->setEnabled(false);
        hbox2->addWidget(next_component); 

        // Connects signals
        connect(order_ascendent, &QPushButton::clicked, this, &ResultsWidget::setOrderAsc); // DEFAULT MODE
        connect(order_descendent, &QPushButton::clicked, this, &ResultsWidget::setOrderDesc);
        connect(prev_component, &QPushButton::clicked, this, &ResultsWidget::prevComponentType);
        connect(next_component, &QPushButton::clicked, this, &ResultsWidget::nextComponentType);
    }

    void ResultsWidget::showResults(Engine::Query query, Engine::ResultSet results)
    {
        // Clears previous data
        while (!lookup.isEmpty())
        {
            WidgetLookup info = lookup.takeLast();
            delete info.getWidget();
        }

        // Shows new data
        if (results.getTotal() > 0)
        {
            results_total->setText(QString::number(results.getTotal()) + " results for component \"" + QString::number(query.getType()) + "\":");        // aggiungendo una stringa text è possibile mostrare nome della componente
        }
        else
        {
            results_total->setText("No results for component \"" + QString::number(query.getType()) + "\".");
        }
        prev_component->setEnabled(true);
        next_component->setEnabled(true);
        // renderer->render(grid, results, &lookup);    DA NOI NO?

        // Connect signals per INFO, EDIT, DELETE
        for (
            QVector<WidgetLookup>::const_iterator it = lookup.begin();
            it != lookup.end();
            it++)
        {
            if (it->getViewButton())
            {
                connect(it->getViewButton(), &QPushButton::clicked, std::bind(&ResultsWidget::showComponent, this, it->getComponent()));
            }
            if (it->getEditButton())
            {
                connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editComponent, this, it->getComponent()));
            }
            if (it->getDeleteButton())
            {
                connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteComponent, this, it->getComponent()));
            }
            if (it->getAddButton())
            {
                connect(it->getAddButton(), &QPushButton::clicked, std::bind(&ResultsWidget::addComponentToCart, this, it->getComponent()))
            }
        }
    }

    void ResultsWidget::setOrderAsc()
    {
        delete renderer;
        renderer = new ResultRenderer::ListAsc();
        emit refreshResults();
    }

    void ResultsWidget::setOrderDesc()
    {
        delete renderer;
        renderer = new ResultRenderer::ListDesc();
        emit refreshResults();
    }
}
