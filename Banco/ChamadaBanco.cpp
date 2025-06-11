#include "ChamadaBanco.h"
#include <iostream>
#include <stdio.h>
#include <list>

#include "sqlite3.h"

using namespace std;

static int getMaxID(string tabela, string coluna);

void createTables()
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

// Funções de inserção

void insertFlashcard(string pergunta, string resposta, int id_materia, int dificuldade)
{
    sqlite3 *db;
    char *erro;
    int id = getMaxID("Flashcards","ID_Flashcard") + 1;

    int banco = sqlite3_open("banco.db", &db);
    string insertSQL = "INSERT INTO Flashcards (ID_Flashcard, Pergunta, Resposta, ID_Materia, Dificuldade, Acertos, Erros, Melhor_tempo_resposta) VALUES ('"
        + to_string(id) + "', '" + pergunta + "', '" + resposta + "', " + to_string(id_materia) + ", " + to_string(dificuldade) + ", 0, 0, 180);";
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

void insertMateria(string nome_materia)
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

void insertRun(int taxa_acerto, int tempo_total)
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

void insertInstancia(int id_run, int id_flashcard, int tempo_resposta, bool acertou)
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

// Funções de limpeza e deleção

void clearTable(string tabela)
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

void clearAllTables()
{
    clearTable("Flashcards");
    clearTable("Materias");
    clearTable("Runs");
    clearTable("Instancias");
}

void deleteTable(string tabela)
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

void deleteAllTables()
{
    deleteTable("Flashcards");
    deleteTable("Materias");
    deleteTable("Runs");
    deleteTable("Instancias");
}

// Funções de seleção

list<int> selectAllIntsTabela(string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    list<int> valores;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT " + coluna + " FROM " + tabela + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            list<int> *valores = static_cast<list<int> *>(data);
            valores->push_back(atoi(argv[0]));
        }
        return 0;
    }, &valores, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dados: " << erro << endl;
        sqlite3_free(erro);
    }
    return valores;
}

int selectIntTabela ( int id, string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    int valor = 0;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT " + coluna + " FROM " + tabela + " WHERE ID_Flashcard = " + to_string(id) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            int *valor = static_cast<int *>(data);
            *valor = atoi(argv[0]);
        }
        return 0;
    }, &valor, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dado: " << erro << endl;
        sqlite3_free(erro);
    }
    return valor;
}

string selectStringTabela(int id, string tabela, string coluna)
{
    sqlite3 *db;
    char *erro;
    string valor;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT " + coluna + " FROM " + tabela + " WHERE ID_Flashcard = " + to_string(id) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            string *valor = static_cast<string *>(data);
            *valor = argv[0];
        }
        return 0;
    }, &valor, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dado: " << erro << endl;
        sqlite3_free(erro);
    }
    return valor;
}

bool selectAcertou (int id)
{
    sqlite3 *db;
    char *erro;
    bool acertou = false;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT Acertou FROM Instancias WHERE ID_Instancia = " + to_string(id) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            bool *acertou = static_cast<bool *>(data);
            *acertou = (atoi(argv[0]) != 0);
        }
        return 0;
    }, &acertou, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar dado: " << erro << endl;
        sqlite3_free(erro);
    }
    return acertou;
}

string selectPergunta (int id)
{
    return selectStringTabela(id, "Flashcards", "Pergunta");
}

string selectResposta (int id)
{
    return selectStringTabela(id, "Flashcards", "Resposta");
}

int selectIDMateriaFromFlashcards (int id)
{
    return selectIntTabela(id, "Flashcards", "ID_Materia");
}

int selectDificuldade (int id)
{
    return selectIntTabela(id, "Flashcards", "Dificuldade");
}

int selectAcertos (int id)
{
    return selectIntTabela(id, "Flashcards", "Acertos");
}

int selectErros (int id)
{
    return selectIntTabela(id, "Flashcards", "Erros");
}

int selectMelhorTempoResposta (int id)
{
    return selectIntTabela(id, "Flashcards", "Melhor_tempo_resposta");
}

string selectNomeMateria (int id)
{
    return selectStringTabela(id, "Materias", "Nome_Materia");
}

int selectIDRunFromInstancias (int id)
{
    return selectIntTabela(id, "Instancias", "ID_Run");
}

int selectIDFlashcardFromInstancias (int id)
{
    return selectIntTabela(id, "Instancias", "ID_Flashcard");
}

int selectTempoResposta (int id)
{
    return selectIntTabela(id, "Instancias", "Tempo_resposta");
}

int selectTaxaAcerto (int id)
{
    return selectIntTabela(id, "Runs", "Taxa_acerto");
}

int selectTaxaErro (int id)
{
    return selectIntTabela(id, "Runs", "Taxa_erro");
}

list<int> selectAllFlashcards()
{
    return selectAllIntsTabela("Flashcards", "ID_Flashcard");
}

list<int> selectAllMaterias()
{
    return selectAllIntsTabela("Materias", "ID_Materia");
}

list<int> selectAllRuns()
{
    return selectAllIntsTabela("Runs", "ID_Run");
}

list<int> selectFlashcardsByMateria(int id_materia)
{
    sqlite3 *db;
    char *erro;
    list<int> flashcards;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT ID_Flashcard FROM Flashcards WHERE ID_Materia = " + to_string(id_materia) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            list<int> *flashcards = static_cast<list<int> *>(data);
            flashcards->push_back(atoi(argv[0]));
        }
        return 0;
    }, &flashcards, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar flashcards por materia: " << erro << endl;
        sqlite3_free(erro);
    }
    return flashcards;
}

list<int> selectFlashcardsByDificuldade(int dificuldade)
{
    sqlite3 *db;
    char *erro;
    list<int> flashcards;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT ID_Flashcard FROM Flashcards WHERE Dificuldade = " + to_string(dificuldade) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            list<int> *flashcards = static_cast<list<int> *>(data);
            flashcards->push_back(atoi(argv[0]));
        }
        return 0;
    }, &flashcards, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar flashcards por dificuldade: " << erro << endl;
        sqlite3_free(erro);
    }
    return flashcards;
}

list<int> selectFlashcardsByDificuldadeAndMateria(int dificuldade, int id_materia)
{
    sqlite3 *db;
    char *erro;
    list<int> flashcards;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT ID_Flashcard FROM Flashcards WHERE Dificuldade = " + to_string(dificuldade) + " AND ID_Materia = " + to_string(id_materia) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            list<int> *flashcards = static_cast<list<int> *>(data);
            flashcards->push_back(atoi(argv[0]));
        }
        return 0;
    }, &flashcards, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar flashcards por dificuldade e materia: " << erro << endl;
        sqlite3_free(erro);
    }
    return flashcards;
}

list<int> selectInstaciasByRun(int id_run)
{
    sqlite3 *db;
    char *erro;
    list<int> instancias;

    int banco = sqlite3_open("banco.db", &db);
    string selectSQL = "SELECT ID_Instancia FROM Instancias WHERE ID_Run = " + to_string(id_run) + ";";
    banco = sqlite3_exec(db, selectSQL.c_str(), [](void *data, int argc, char **argv, char **azColName) {
        if (argc > 0 && argv[0] != nullptr)
        {
            list<int> *instancias = static_cast<list<int> *>(data);
            instancias->push_back(atoi(argv[0]));
        }
        return 0;
    }, &instancias, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao selecionar instancias por run: " << erro << endl;
        sqlite3_free(erro);
    }
    return instancias;
}

int escolherFlashcard(const list<int> &idList)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int numeroAleatorio = rand() % idList.size();
    auto it = idList.begin();
    advance(it, numeroAleatorio);
    int escolhido = *it;
    return escolhido;
}

// Funções de atualização

void updateAcertos(int id_flashcard)
{
    sqlite3 *db;
    char *erro;
    int banco = sqlite3_open("banco.db", &db);
    string updateSQL = "UPDATE Flashcards SET Acertos = Acertos + 1 WHERE ID_Flashcard = " + to_string(id_flashcard) + ";";
    banco = sqlite3_exec(db, updateSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao atualizar Acertos: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Acertos atualizado com sucesso para o flashcard com ID " << id_flashcard << "!" << endl;
    }
}

void updateErros(int id_flashcard)
{
    sqlite3 *db;
    char *erro;
    int banco = sqlite3_open("banco.db", &db);
    string updateSQL = "UPDATE Flashcards SET Erros = Erros + 1 WHERE ID_Flashcard = " + to_string(id_flashcard) + ";";
    banco = sqlite3_exec(db, updateSQL.c_str(), NULL, 0, &erro);
    if (banco != SQLITE_OK)
    {
        cerr << "Erro ao atualizar Erros: " << erro << endl;
        sqlite3_free(erro);
    }
    else
    {
        cout << "Erros atualizado com sucesso para o flashcard com ID " << id_flashcard << "!" << endl;
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