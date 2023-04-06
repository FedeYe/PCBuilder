/*
#include "ResultWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

#include "ResultRenderer/List.h"

// MODIFICARE NEXT E PREVIOUS COMPONENT

namespace View
{
    ResultsWidget::ResultsWidget(QWidget *parent)
        : QWidget(parent)
    {
        QVBoxLayout *vbox = new QVBoxLayout(this);
        vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

        QHBoxLayout *hbox = new QHBoxLayout();
        hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        vbox->addLayout(hbox);

        component_name = new QLabel();
        hbox->addWidget(component_name);

        hbox->addStretch();

        QPushButton *order_ascendent = new QPushButton(QIcon(QPixmap(":/assets/icons/priceasc.svg")), "");
        hbox->addWidget(order_ascendent);

        QPushButton *order_descendend = new QPushButton(QIcon(QPixmap(":/assets/icons/pricedesc.svg")), "");
        hbox->addWidget(order_descendend);

        QScrollArea *scroll_area = new QScrollArea();
        scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll_area->setWidgetResizable(true);
        scroll_area->setWidget(container);
        vbox->addWidget(scroll_area);

        renderer = new ResultRenderer::List();

        /*parte sotto con precedente e next
        QHBoxLayout *hbox2 = new QHBoxLayout();
        hbox2->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
        vbox->addLayout(hbox2); */

        /* previous_page = new QPushButton(QIcon(QPixmap(":/assets/icons/previous.svg")), "");
         previous_page->setEnabled(false);
         hbox2->addWidget(previous_page); */

        /* next_page = new QPushButton(QIcon(QPixmap(":/assets/icons/next.svg")), "");
        next_page->setEnabled(false);
        hbox2->addWidget(next_page); */
        /*
        // Connects signals
        connect(order_ascendent, &QPushButton::clicked, this, &ResultsWidget::setOrderAsc); // SARA DEFAULT
        connect(order_descendent, &QPushButton::clicked, this, &ResultsWidget::setOrderDesc);
        // connect(previous_page, &QPushButton::clicked, this, &ResultsWidget::previousPage);
        // connect(next_page, &QPushButton::clicked, this, &ResultsWidget::nextPage);
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
            results_total->setText(QString::number(results.getTotal()) + " results for \"" + QString::fromStdString(query.getText()) + "\":");
        }
        else
        {
            results_total->setText("No results for \"" + QString::fromStdString(query.getText()) + "\".");
        }
        // previous_page->setEnabled(query.getOffset() > 0);
        // next_page->setEnabled(results.getItems().size() == query.getSize());
        //  renderer->render(grid, results, &lookup);    DA NOI NO?
        // Connect signals
        for (
            QVector<WidgetLookup>::const_iterator it = lookup.begin();
            it != lookup.end();
            it++)
        {
            if (it->getViewButton())
            {
                connect(it->getViewButton(), &QPushButton::clicked, std::bind(&ResultsWidget::showComponent, this, it->getItem()));
            }
            if (it->getEditButton())
            {
                connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editComponent, this, it->getItem()));
            }
            if (it->getDeleteButton())
            {
                connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteComponent, this, it->getItem()));
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
*/
