#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml/qqmlextensionplugin.h> // Required for Q_IMPORT_QML_PLUGIN
#include "PonteBackFront.h"

// --- THE FIX ---
// Explicitly import the static plugins to satisfy the linker.
// This macro takes only the plugin's C++ class name as an argument.
Q_IMPORT_QML_PLUGIN(FlashCardPlugin)
Q_IMPORT_QML_PLUGIN(FlashCardContentPlugin)

int main(int argc, char *argv[])
{
    using namespace Qt::StringLiterals; // Required for the _s literal

    QApplication app(argc, argv);

    PonteBackFront ponte;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("ponte", &ponte);

    // Using the modern _s literal to address the deprecation warning.
    const QUrl url(u"qrc:/FlashCardContent/App.qml"_s);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
