#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "../Component/Repository/JsonRepository.h"
#include "../Engine/IEngine.h"
#include "../Engine/Query.h"
#include "ResultsWidget.h"
#include "ShoppingCartWidget.h"
#include "ComponentRenderer/Full.h"

namespace View
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    private:
        bool has_unsaved_changes;
        QAction* create_item;
        QToolBar* toolbar;
        Engine::IEngine& ricerca;
        Component::Repository::JsonRepository* repo;
        ResultsWidget* result_widget;
        ShoppingCartWidget* shopping_cart_widget;
        QStackedWidget* stacked_widget;
        ComponentRenderer::Full full_renderer;

    public:
        MainWindow(Engine::IEngine& ricerca, QWidget* parent = nullptr);
        Component::Repository::JsonRepository* getRepository();
        Engine::IEngine& getEngine();
        MainWindow& reloadData();
        ShoppingCartWidget* getShoppingCartWidget();

    private:
        void clearStack(); // usato da show,edit,create  ---> per implementarlo serve stacked widget

    public slots:
        void newDataset();
        void openDataset();
        void saveDataset();
        void saveAsDataset();
        void toggleToolbar();
        void showStatus(QString message);
        void search(Engine::Query query);
        void changeOfOrder(); 
        void createComponent();
        void showComponent(const Component::AbstractComponent *component);
        void editComponent(const Component::AbstractComponent *component);
        void deleteComponent(const Component::AbstractComponent *component);
        void close();
    };
}
#endif 
