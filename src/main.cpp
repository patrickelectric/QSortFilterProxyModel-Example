#include <QApplication>
#include <QQmlApplicationEngine>

#include "provide.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Provide>("Provide", 1, 0, "Provide");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine(QUrl("qrc:/main.qml"));
    return app.exec();
}
