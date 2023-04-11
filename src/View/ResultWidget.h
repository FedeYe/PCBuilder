#ifndef VIEW_RESULTS_WIDGET_H
#define VIEW_RESULTS_WIDGET_H

#include <QVector>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "../Engine/Query.h"
#include "../Engine/ResultSet.h"
#include "ResultRenderer/IResultRendererStrategy.h"
#include "WidgetLookup.h"

namespace View
{

    class ResultsWidget : public QWidget
    {
        Q_OBJECT
    private:
        QLabel* results_total;
        QPushButton* order_ascendent;
        QPushButton* order_descendent;
        QPushButton* prev_component;
        QPushButton* next_component;
        QVector<WidgetLookup> lookup;
        ResultRenderer::IResultRendererStrategy *renderer;

    public:
        explicit ResultsWidget(QWidget *parent = 0);

    signals:
        void refreshResults();
        void prevComponentType();
        void nextComponentType();
        void showComponent(const Component::AbstractComponent *component);
        void editComponent(const Component::AbstractComponent *component);
        void deleteComponent(const Component::AbstractComponent *component);
        void addComponentToCart(const Component::AbstractComponent *component);

    public slots:
        void showResults(Engine::Query query, Engine::ResultSet results);
        void setOrderAsc();
        void setOrderDesc();
    };

}

#endif
