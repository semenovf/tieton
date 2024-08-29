////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Vladislav Trifochkin
//
// This file is part of `tieton-lib`.
//
// Changelog:
//      2024.08.26 Initial version.
////////////////////////////////////////////////////////////////////////////////
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <cstdlib>

int main (int argc, char * argv[])
{
    QGuiApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);

#if _MSC_VER
    QGuiApplication::setAttribute(Qt::AA_UseDesktopOpenGL, true);
#endif

    QGuiApplication app {argc, argv};
    QQmlApplicationEngine engine;

//    engine.rootContext()->setContextProperty("Property", & property);

    engine.load("qrc:/main.qml");

    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    return app.exec();
}
