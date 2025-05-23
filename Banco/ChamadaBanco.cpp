#include <iostream>
#include <stdio.h>
#include "sqlite3.h"

using namespace std;

static int getMaxID(string tabela, string coluna);

static void createTables()
{
    sqlite3 *db;
    char *erro;

    int banco = sqlite3_open("banco.db", &db);
    string createTablesSQL(
        "CREATE TABLE IF NOT EXISTS Flashcards"
            "(ID_Flashcard INT PRIMARY KEY UNIQUE,"
            "Pergunta VARCHAR(255) NOT NULL,"
            "Resposta VARCHAR(255) NOT NULL,"
            "ID_Materia INT NOT NULL,"
            "Dificuldade INT NOT NULL,"
            "Acertos INT NOT NULL,"
            "Erros INT NOT NULL,"
            "Melhor_tempo_resposta INT NOT NULL);"
        "CREATE TABLE IF NOT EXISTS Materias ("
            "ID_Materia INT PRIMARY KEY UNIQUE,"
            "Nome_Materia VARCHAR(255) NOT NULL);"
        "CREATE TABLE IF NOT EXISTS Runs ("
            "ID_Run int PRIMARY KEY UNIQUE,"
            "Taxa_acerto int NOT NULL,"
            "Tempo_total int NOT NULL);"
        "CREATE TABLE IF NOT EXISTS Instancias ("
            "ID_Instancia int PRIMARY KEY UNIQUE,"
            "ID_Run int NOT NULL,
            "ID_Flashcard int NOT NULL,"
            "Tempo_resposta int NOT NULL,"
            "Acertou BOOLEAN NOT NULL);"
    );
    banco = sqlite3_exec(db, createTablesSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao criar tabela: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Tabelas criadas com sucesso!" << endl;
    }
}

static void insertFlashcard(string pergunta, string resposta, int id_materia, int dificuldade, int acertos, int erros, int melhor_tempo_resposta)
{
    sqlite3 *db;
    char *erro;
    int id = getMaxID("Flashcards","ID_Flashcard") + 1;

    int banco = sqlite3_open("banco.db", &db);
    string insertSQL = "INSERT INTO Flashcards (ID_Flashcard, Pergunta, Resposta, ID_Materia, Dificuldade, Acertos, Erros, Melhor_tempo_resposta) VALUES ('"
        + to_string(id) + "', '" + pergunta + "', '" + resposta + "', " + to_string(id_materia) + ", " + to_string(dificuldade) + ", " + to_string(acertos) + ", " + to_string(erros) + ", " + to_string(melhor_tempo_resposta) + ");";
    banco = sqlite3_exec(db, insertSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao inserir flashcard: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Flashcard inserido com sucesso!" << endl;
    }
}

static void insertMateria(string nome_materia)
{
    sqlite3 *db;
    char *erro;
    int id = getMaxID("Materias", "ID_Materia") + 1;

    int banco = sqlite3_open("banco.db", &db);
    string insertSQL = "INSERT INTO Materias (ID_Materia, Nome_Materia) VALUES ('"
        + to_string(id) + "', '" + nome_materia + "');";
    banco = sqlite3_exec(db, insertSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao inserir materia: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Materia inserida com sucesso!" << endl;
    }
}

static void insertRun(int taxa_acerto, int tempo_total)
{
    sqlite3 *db;
    char *erro;
    int id = getMaxID("Runs", "ID_Run") + 1;

    int banco = sqlite3_open("banco.db", &db);
    string insertSQL = "INSERT INTO Runs (ID_Run, Taxa_acerto, Tempo_total) VALUES ('"
        + to_string(id) + "', '" + to_string(taxa_acerto) + "', '" + to_string(tempo_total) + "');";
    banco = sqlite3_exec(db, insertSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao inserir run: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Run inserido com sucesso!" << endl;
    }
}

static void insertInstancia(int id_run, int id_flashcard, int tempo_resposta, bool acertou)
{
    sqlite3 *db;
    char *erro;
    int id = getMaxID("Instancias", "ID_Instancia") + 1;

    int banco = sqlite3_open("banco.db", &db);
    string insertSQL = "INSERT INTO Instancias (ID_Instancia, ID_Run, ID_Flashcard, Tempo_resposta, Acertou) VALUES ('"
        + to_string(id) + "', '" + to_string(id_run) + "', '" + to_string(id_flashcard) + "', '" + to_string(tempo_resposta) + "', '" + to_string(acertou) + "');";
    banco = sqlite3_exec(db, insertSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao inserir instancia: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Instancia inserida com sucesso!" << endl;
    }
}

static int getMaxID(string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    int maxID = 0;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT MAX("+coluna+") FROM " + tabela + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            int *maxID = static_cast<int *>(data);
            *maxID = atoi(argv[0]);
        }
        return 0;
    }, &maxID, &erro);
    return maxID;
}
