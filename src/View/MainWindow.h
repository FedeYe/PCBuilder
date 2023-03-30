#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "../Component/Repository/JsonRepository.h"
#include "../Engine/IEngine.h"
#include "../Engine/Query.h"
//#include "ResultWidget.h"
//#include "ShoppingCart.h"
//#include "ComponentRender/Full.h"

namespace View { 

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            bool has_unsaved_changes;
            QAction* create_item;
            QToolBar* toolbar;
            Engine::IEngine& ricerca;
            Component::Repository::JsonRepository* repo;
            //ResultWidget*  
            //
            //
            //
        public:
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow();

        
    };
}
#endif // MAINWINDOW_H
