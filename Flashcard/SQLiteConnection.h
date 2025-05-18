#ifndef SQLITECONNECTION_H
#define SQLITECONNECTION_H

#include <QString>

class SQLiteConnection {
public:
    SQLiteConnection(const QString& caminhoBanco);
    bool conectar();

private:
    QString caminho;
};

#endif
