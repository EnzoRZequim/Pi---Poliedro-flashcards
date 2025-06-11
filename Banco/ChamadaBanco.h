#ifndef CHAMADABANCO_H
#define CHAMADABANCO_H

#include <string>
#include <list>

using namespace std;

//Funções de Criação e Inserção
void createTables();
void insertFlashcard(string pergunta, string resposta, int id_materia, int dificuldade);
void insertMateria(string nome_materia);
void insertRun(int taxa_acerto, int tempo_total);
void insertInstancia(int id_run, int id_flashcard, int tempo_resposta, bool acertou);

//Funções de Limpeza e Deleção
void clearTable(string tabela);
void clearAllTables();
void deleteTable(string tabela);
void deleteAllTables();

// Funções de Seleção
// Seleções de Itens Específicos
bool selectAcertou(int id_instancia);
string selectPergunta(int id_flashcard);
string selectResposta(int id_flashcard);
int selectIDMateriaFromFlashcards(int id_flashcard);
int selectDificuldade(int id_flashcard);
int selectAcertos(int id_flashcard);
int selectErros(int id_flashcard);
int selectMelhorTempoResposta(int id_flashcard);
string selectNomeMateria(int id_materia);
int selectIDRunFromInstancias(int id_instancia);
int selectIDFlashcardFromInstancias(int id_instancia);
int selectTempoResposta(int id_instancia);
int selectTaxaAcerto(int id_run);
int selectTaxaErro(int id_run);

// Seleções de Listas
list<int> selectAllFlashcards();
list<int> selectAllMaterias();
list<int> selectAllRuns();
list<int> selectFlashcardsByMateria(int id_materia);
list<int> selectFlashcardsByDificuldade(int dificuldade);
list<int> selectFlashcardsByDificuldadeAndMateria(int dificuldade, int id_materia);
list<int> selectInstaciasByRun(int id_run);

// Funções de Lógica
int escolherFlashcard(const list<int> &idList);

// Funções de Atualização
void updateAcertos(int id_flashcard);
void updateErros(int id_flashcard);

#endif