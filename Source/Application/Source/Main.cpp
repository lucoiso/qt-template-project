// Copyright Notices: [...]

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QIcon>

#include <QtPlugin>
Q_IMPORT_PLUGIN(UserInterfacePlugin)

std::int32_t main(std::int32_t InArgc, char* InArgv[])
{
    const QGuiApplication Application(InArgc, InArgv);
    QQmlApplicationEngine AppEngine;

    QQuickStyle::setStyle("Material");

    QObject::connect
    (
        &AppEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        &Application,
        []
        {
            QCoreApplication::exit(EXIT_FAILURE);
        },
        Qt::QueuedConnection
    );

    // https://doc.qt.io/qt-6/qtquickcontrols2-material.html
    // https://doc.qt.io/qt-6/qml-color.html#colorbasictypedocs
    // https://doc.qt.io/qt-6/qtquickcontrols2-material.html#pre-defined-shades
    qputenv("QT_QUICK_CONTROLS_MATERIAL_THEME", "Dark");
    qputenv("QT_QUICK_CONTROLS_MATERIAL_VARIANT", "Dense");
    qputenv("QT_QUICK_CONTROLS_MATERIAL_ACCENT", "dodgerblue");

    QGuiApplication::setWindowIcon(QIcon(":/UserInterface/Resources/Images/Placeholder.png"));
    AppEngine.load(QUrl(u"qrc:/QtTemplateProject/Source/MainWindow.qml"_qs));

    return QGuiApplication::exec();
}