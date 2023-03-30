QT += core widgets
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Component/Converter/Json/Json.cpp\
    Component/Converter/Json/JsonVisitor.cpp\
    Component/Converter/Json/Reader.cpp\
    \
    Component/DataMapper/JsonFile.cpp\
    \
    Component/Repository/JsonRepository.cpp\
    \
    Component/AbstractComponent.cpp\
    Component/MotherBoard.cpp\
    Component/CPU.cpp\
    Component/GPU.cpp\
    Component/PSU.cpp\
    Component/RAM.cpp\
    \
    Engine/ComponentShown.cpp\
    Engine/FilterVisitor.cpp\
    Engine/Memory.cpp\
    Engine/Query.cpp\
    Engine/ResultSet.cpp\
    \
    main.cpp \
    \
    View/MainWindow.cpp

HEADERS += \
    Component/Converter/Json/IReader.h\
    Component/Converter/Json/Json.h\
    Component/Converter/Json/JsonVisitor.h\
    Component/Converter/Json/Reader.h\
    \
    Component/DataMapper/JsonFile.h\
    \
    Component/Repository/IRepository.h\
    Component/Repository/JsonRepository.h\
    \
    Component/AbstractComponent.h\
    Component/MotherBoard.h\
    Component/CPU.h\
    Component/GPU.h\
    Component/PSU.h\
    Component/RAM.h\
    Component/IConstVisitor.h\
    Component/IVisitor.h\
    \
    Engine/ComponentShown.h\
    Engine/FilterVisitor.h\
    Engine/IEngine.h\
    Engine/Memory.h\
    Engine/Query.h\
    Engine/ResultSet.h\
    \
    Service/Container.h\
    \
    View/MainWindow.h


FORMS += \
    View/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target