// Copyright Notices: [...]

#include "Application/Application.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQuickWindow>

#include <QtPlugin>
Q_IMPORT_PLUGIN(UserInterfacePlugin)

using namespace Qt::Literals::StringLiterals;

int Application::Run(std::int32_t InArgc, char* InArgv[])
{
#ifdef _DEBUG
    qputenv("QT_LOGGING_TO_CONSOLE", "1");
    qputenv("QT_FORCE_STDERR_LOGGING", "1");
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1");
    qputenv("QML_IMPORT_TRACE", "0");
#endif // defined(_DEBUG)

    const QGuiApplication Application(InArgc, InArgv);
    QQuickWindow::setGraphicsApi(QSGRendererInterface::Vulkan);

    QQmlApplicationEngine QmlAppEngine;

    QObject::connect
    (
        &QmlAppEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        &Application,
        []
        {
            QCoreApplication::exit(EXIT_FAILURE);
        },
        Qt::QueuedConnection
    );

    QQuickStyle::setStyle("FluentWinUI3");
    QGuiApplication::setWindowIcon(QIcon(":/UserInterface/Resources/Images/Placeholder.png"));

    QmlAppEngine.load(QUrl(u"qrc:/Application/Resources/QML/Components/MainWindow.qml"_s));
    return QGuiApplication::exec();
}