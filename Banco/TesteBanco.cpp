#include <iostream>
#include <stdio.h>
#include "sqlite3.h"

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName);

/*int main() {
    sqlite3 *db;
    char* erro;

    int test = sqlite3_open("banco.db", &db);

    string createTableSQL("CREATE TABLE IF NOT EXISTS Flashcards (ID_Flashcard INT PRIMARY KEY UNIQUE,Pergunta VARCHAR(255) NOT NULL,Resposta VARCHAR(255) NOT NULL,ID_Submateria INT NOT NULL,Dificuldade INT NOT NULL,Acertos INT NOT NULL,Erros INT NOT NULL,Melhor_tempo_resposta INT NOT NULL);");

    test = sqlite3_exec(db, createTableSQL.c_str(), NULL, 0, &erro);
    if (test != SQLITE_OK) {
        cerr << "Erro ao criar tabela: " << erro << endl;
        sqlite3_free(erro);
        return 1;
    }

    string sqlInsert("INSERT INTO Flashcards (ID_Flashcard, Pergunta, Resposta, ID_Submateria, Dificuldade, Acertos, Erros, Melhor_tempo_resposta) VALUES (2, 'Qual é a capital da França?', 'Paris', 1, 2, 0, 0, 0);");

    test = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &erro);
    if (test != SQLITE_OK)
    {
        cerr << "SQL error: " << erro << endl;
        sqlite3_free(erro);
    }
    else
        cout << "Insert deu certo" << endl;

    string sqlSelect("SELECT * FROM Flashcards;");
    test = sqlite3_exec(db, sqlSelect.c_str(), callback, NULL, NULL);


    return 0;
}*/

static int callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << " = " << argv[i] << endl;
    }
    cout << endl;
    return 0;
}