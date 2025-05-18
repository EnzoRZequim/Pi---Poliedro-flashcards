#include <QCoreApplication>
#include "SQLiteConnection.h"
#include "qdebug.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    SQLiteConnection conn("CriaBanco.db");

    if (!conn.conectar()) {
        qDebug() << "Falha ao conectar ao banco existente.";
        return -1;
    }

    return a.exec();
}
