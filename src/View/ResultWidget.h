/*

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
        QLabel *results_total;
        // QPushButton *previous_page;
        // QPushButton *next_page;
        QVector<WidgetLookup> lookup;
        ResultRenderer::IResultRendererStrategy *renderer;

    public:
        explicit ResultsWidget(QWidget *parent = 0);

    signals:
        void refreshResults();
        // void previousPage();
        //  void nextPage();
        void showComponent(const Component::AbstractComponent *component);
        void editComponent(const Component::AbstractComponent *component);
        void deleteComponent(const Component::AbstractComponent *component);

    public slots:
        void showResults(Engine::Query query, Engine::ResultSet results);
        void setListRenderer();
    };

}

#endif

*/
