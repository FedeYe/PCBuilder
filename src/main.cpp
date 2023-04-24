#include <QApplication>
#include <QFile>

#include "Engine/Memory.h"
#include "View/MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":Assets/appIcon.jpeg"));        

    //QFile stylesheet(":/Assets/stylesheet.qss");       //da aggiustare in seguito
    //styleshhet.open(QFile::ReadOnly);
    //app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    Engine::Memory catalog;
    View::MainWindow w(catalog);
    //w.resize();       //da aggiustare in seguito
    w.show();
    
    return app.exec();
}
