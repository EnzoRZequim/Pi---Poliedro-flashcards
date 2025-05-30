#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <string>

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
        "ID_Run int NOT NULL,"
        "ID_Flashcard int NOT NULL,"
        "Tempo_resposta int NOT NULL,"
        "Acertou BOOLEAN NOT NULL);");
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

static void insertFlashcard(string pergunta, string resposta, int id_materia, int dificuldade)
{
    sqlite3 *db;
    char *erro;
    int id = getMaxID("Flashcards", "ID_Flashcard") + 1;

    int banco = sqlite3_open("banco.db", &db);
    string insertSQL = "INSERT INTO Flashcards (ID_Flashcard, Pergunta, Resposta, ID_Materia, Dificuldade, Acertos, Erros, Melhor_tempo_resposta) VALUES ('" + to_string(id) + "', '" + pergunta + "', '" + resposta + "', " + to_string(id_materia) + ", " + to_string(dificuldade) + ", 0, 0, 180);";
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
    string insertSQL = "INSERT INTO Materias (ID_Materia, Nome_Materia) VALUES ('" + to_string(id) + "', '" + nome_materia + "');";
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
    string insertSQL = "INSERT INTO Runs (ID_Run, Taxa_acerto, Tempo_total) VALUES ('" + to_string(id) + "', '" + to_string(taxa_acerto) + "', '" + to_string(tempo_total) + "');";
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
    string insertSQL = "INSERT INTO Instancias (ID_Instancia, ID_Run, ID_Flashcard, Tempo_resposta, Acertou) VALUES ('" + to_string(id) + "', '" + to_string(id_run) + "', '" + to_string(id_flashcard) + "', '" + to_string(tempo_resposta) + "', '" + to_string(acertou) + "');";
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

static void printTable(string tabela)
{
    sqlite3 *db;
    char *erro;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT * FROM " + tabela + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName)
                         {
        for (int i = 0; i < argc; i++)
        {
            cout << azColName[i] << " = " << argv[i] << endl;
        }
        cout << endl;
        return 0; }, NULL, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dados: " << erro << endl;
        sqlite3_free(erro);
    }
}

static void clearTable(string tabela)
{
    sqlite3 *db;
    char *erro;

    int banco = sqlite3_open("banco.db", &db);
    string deleteSQL = "DELETE FROM " + tabela + ";";
    banco = sqlite3_exec(db, deleteSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao limpar tabela: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Tabela limpa com sucesso!" << endl;
    }
}

static void clearAllTables()
{
    clearTable("Flashcards");
    clearTable("Materias");
    clearTable("Runs");
    clearTable("Instancias");
}

static void deleteTable(string tabela)
{
    sqlite3 *db;
    char *erro;

    int banco = sqlite3_open("banco.db", &db);
    string deleteSQL = "DROP TABLE IF EXISTS " + tabela + ";";
    banco = sqlite3_exec(db, deleteSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao deletar tabela: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Tabela deletada com sucesso!" << endl;
    }
}

static void deleteAllTables()
{
    deleteTable("Flashcards");
    deleteTable("Materias");
    deleteTable("Runs");
    deleteTable("Instancias");
}

static int selectIntTabela(int id, string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    int valor = 0;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT " + coluna + " FROM " + tabela + " WHERE ID_Flashcard = " + to_string(id) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName)
                         {
        if (argc > 0 && argv[0] != nullptr)
        {
            int *valor = static_cast<int *>(data);
            *valor = atoi(argv[0]);
        }
        return 0; }, &valor, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dado: " << erro << endl;
        sqlite3_free(erro);
    }
    return valor;
}

static string selectStringTabela(int id, string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    string valor;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT " + coluna + " FROM " + tabela + " WHERE ID_Flashcard = " + to_string(id) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName)
                         {
        if (argc > 0 && argv[0] != nullptr)
        {
            string *valor = static_cast<string *>(data);
            *valor = argv[0];
        }
        return 0; }, &valor, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dado: " << erro << endl;
        sqlite3_free(erro);
    }
    return valor;
}

static bool selectAcertou(int id)
{
    sqlite3 *db;
    char *erro;
    bool acertou = false;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT Acertou FROM Instancias WHERE ID_Instancia = " + to_string(id) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName)
                         {
        if (argc > 0 && argv[0] != nullptr)
        {
            bool *acertou = static_cast<bool *>(data);
            *acertou = (atoi(argv[0]) != 0);
        }
        return 0; }, &acertou, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dado: " << erro << endl;
        sqlite3_free(erro);
    }
    return acertou;
}

static int selectDificuldade(int id)
{
    return selectIntTabela(id, "Flashcards", "Dificuldade");
}

static string selectPergunta(int id)
{
    return selectStringTabela(id, "Flashcards", "Pergunta");
}

static list<int> selectFlashcardsByMateria(int id_materia)
{
    sqlite3 *db;
    char *erro;
    list<int> flashcards;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT ID_Flashcard FROM Flashcards WHERE ID_Materia = " + to_string(id_materia) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName)
                         {
        if (argc > 0 && argv[0] != nullptr)
        {
            list<int> *flashcards = static_cast<list<int> *>(data);
            flashcards->push_back(atoi(argv[0]));
        }
        return 0; }, &flashcards, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar flashcards por materia: " << erro << endl;
        sqlite3_free(erro);
    }
    return flashcards;
}

static int escolherFlashcard(const list<int> &idList)
{
    if (idList.empty())
    {
        cerr << "Lista de IDs está vazia!" << endl;
        return -1;
    }

    sqlite3 *db;
    char *erro;
    vector<int> idsFiltrados;

    // monta a cláusula IN
    string inClause = "(";
    for (auto it = idList.begin(); it != idList.end(); ++it)
    {
        inClause += to_string(*it);
        if (next(it) != idList.end())
            inClause += ", ";
    }
    inClause += ")";

    // consulta os ids fornecidos
    string selectSQL = "SELECT ID_Flashcard FROM Flashcards WHERE ID_Flashcard IN " + inClause + ";";

    // conexão com banco
    int banco = sqlite3_open("banco.db", &db);
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr) {
            vector<int> *lista = static_cast<vector<int> *>(data);
            lista->push_back(atoi(argv[0]));
        }
        return 0;
    }, &idsFiltrados, &erro);

    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao buscar flashcards filtrados: " << erro << endl;
        sqlite3_free(erro);
        return -1;
    }

    sqlite3_close(db);

    if (idsFiltrados.empty())
    {
        cerr << "Nenhum flashcard encontrado com os IDs fornecidos." << endl;
        return -1;
    }

    // sorteia um ID aleatório
    srand(static_cast<unsigned int>(time(nullptr)));
    int escolhido = idsFiltrados[rand() % idsFiltrados.size()];
    return escolhido;
}

static int getMaxID(string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    int maxID = 0;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT MAX(" + coluna + ") FROM " + tabela + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName)
                         {
        if (argc > 0 && argv[0] != nullptr)
        {
            int *maxID = static_cast<int *>(data);
            *maxID = atoi(argv[0]);
        }
        return 0; }, &maxID, &erro);
    return maxID;
}

static void printIDList(list<int> idList)
{
    cout << "Flashcards de Geografia: ";
    for (int id : idList)
    {
        cout << id << " ";
    }
    cout << endl;
}

static void printPerguntaPorMateria(int id_materia)
{
    list<int> idFlashcards;
    idFlashcards = selectFlashcardsByMateria(id_materia);
    for (int id : idFlashcards)
    {
        string pergunta = selectPergunta(id);
        cout << "Pergunta ID " << id << ": " << pergunta << endl;
    }
}

int main()
{
    deleteAllTables();
    createTables();
    insertFlashcard("Qual é a capital da França?", "Paris", 1, 2);
    insertFlashcard("Qual é a capital do Brasil?", "Brasília", 1, 1);
    insertFlashcard("abc", "Paris", 3, 4);
    insertMateria("Geografia");
    insertRun(80, 120);
    insertInstancia(1, 1, 30, true);
    printTable("Materias");
    printTable("Runs");
    printTable("Instancias");
    printf("Dificuldade: %d\n", selectDificuldade(1));
    printIDList(selectFlashcardsByMateria(1));
    printPerguntaPorMateria(1);
    clearAllTables();

    return 0;
}
