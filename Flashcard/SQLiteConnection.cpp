#include "SQLiteConnection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDebug>

SQLiteConnection::SQLiteConnection(const QString& caminhoBanco)
    : caminho(caminhoBanco) {}

bool SQLiteConnection::conectar() {
    if (!QFile::exists(caminho)) {
        qDebug() << "Erro: o banco de dados não existe em:" << caminho;
        return false;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(caminho);

    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados:" << db.lastError().text();
        return false;
    }

    qDebug() << "Conexão com o banco de dados estabelecida!";
    return true;
}
