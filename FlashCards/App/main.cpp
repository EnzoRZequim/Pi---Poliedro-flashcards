#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtPlugin> // Incluir para carregar plugins estaticamente
#include "../Banco/PonteBackFront.h"
#include "../Banco/ChamadaBanco.h"
// Garante que o plugin para o formato de imagem WebP é incluído na aplicação

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    createTables();

    PonteBackFront ponte;
    engine.rootContext()->setContextProperty("ponte", &ponte);

    const QUrl url(u"qrc:/FlashCards/FlashCardContent/App.qml"_qs);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
