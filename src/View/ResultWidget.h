#ifndef VIEW_RESULTS_WIDGET_H
#define VIEW_RESULTS_WIDGET_H

#include <QVector>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "../Engine/Query.h"
#include "../Engine/ResultSet.h"
#include "ResultRenderer/IResultRenderer.h"
#include "WidgetLookup.h"

namespace View
{

    class ResultsWidget : public QWidget
    {
        Q_OBJECT
    private:
        QLabel* component_name;
        QLabel* results_total;
        QPushButton* order_ascendent;
        QPushButton* order_descendent;
        QPushButton* prev_component;
        QPushButton* next_component;
        QVector<WidgetLookup> lookup;
        QGridLayout* grid;
        ResultRenderer::IResultRenderer *renderer;

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
