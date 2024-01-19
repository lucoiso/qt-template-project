// Copyright Notices: [...]

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtQml/QQmlExtensionPlugin>
Q_IMPORT_QML_PLUGIN(UserInterfacePlugin)

int main(int Argc, char *Argv[])
{
    QGuiApplication const Application(Argc, Argv);
    QQmlApplicationEngine AppEngine;

    QObject::connect(
            &AppEngine,
            &QQmlApplicationEngine::objectCreationFailed,
            &Application,
            []
            {
                QCoreApplication::exit(-1);
            },
            Qt::QueuedConnection);

    AppEngine.load(QUrl(u"qrc:/UserInterface/MainWindow.qml"_qs));

    return QGuiApplication::exec();
}
