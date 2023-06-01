#include <QApplication>
#include <QFile>

#include "Engine/Memory.h"
#include "Engine/ShoppingCart.h"
#include "View/MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":Assets/appIcon.jpeg"));
    app.setQuitOnLastWindowClosed(false);        

    QFile stylesheet(":/Assets/stylesheet.qss");       //da aggiustare in seguito
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    Engine::Memory catalog;
    Engine::ShoppingCart default_cart;
    View::MainWindow w(catalog, default_cart);      
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    
    return app.exec();
}
