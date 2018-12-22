TARGET = example

CONFIG += \
    c++14

QT += gui qml widgets

HEADERS += \
    src/model.h \
    src/provide.h

SOURCES += \
    src/main.cpp \
    src/model.cpp

RESOURCES += \
    resources.qrc
