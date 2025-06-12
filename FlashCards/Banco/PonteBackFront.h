#ifndef PONTEBACKFRONT_H
#define PONTEBACKFRONT_H

#include <QObject>
#include <QString>
#include <QVariantList>

class PonteBackFront : public QObject
{
    Q_OBJECT
public:
    explicit PonteBackFront(QObject *parent = nullptr);

    //Funções de Criação e Inserção
    Q_INVOKABLE void insertFlashcard(const QString &pergunta, const QString &resposta, int id_materia, int dificuldade);
    Q_INVOKABLE void insertMateria(const QString &nome_materia);
    Q_INVOKABLE void insertRun(int taxa_acerto, int tempo_total);
    Q_INVOKABLE void insertInstancia(int id_run, int id_flashcard, int tempo_resposta, bool acertou);

    //Funções de Limpeza e Deleção
    Q_INVOKABLE void clearTable(const QString &tabela);
    Q_INVOKABLE void clearAllTables();
    Q_INVOKABLE void deleteTable(const QString &tabela);
    Q_INVOKABLE void deleteAllTables();

    //Funções de Seleção
    //Seleções de Itens Específicos
    Q_INVOKABLE bool selectAcertou(int id_instancia);
    Q_INVOKABLE QString selectPergunta(int id_flashcard);
    Q_INVOKABLE QString selectResposta(int id_flashcard);
    Q_INVOKABLE int selectIDMateriaFromFlashcards(int id_flashcard);
    Q_INVOKABLE int selectDificuldade(int id_flashcard);
    Q_INVOKABLE int selectAcertos(int id_flashcard);
    Q_INVOKABLE int selectErros(int id_flashcard);
    Q_INVOKABLE int selectMelhorTempoResposta(int id_flashcard);
    Q_INVOKABLE QString selectNomeMateria(int id_materia);
    Q_INVOKABLE int selectIDRunFromInstancias(int id_instancia);
    Q_INVOKABLE int selectIDFlashcardFromInstancias(int id_instancia);
    Q_INVOKABLE int selectTempoResposta(int id_instancia);
    Q_INVOKABLE int selectTaxaAcerto(int id_run);
    Q_INVOKABLE int selectTaxaErro(int id_run);

    //Seleções de Listas
    Q_INVOKABLE QVariantList selectAllFlashcards();
    Q_INVOKABLE QVariantList selectAllMaterias();
    Q_INVOKABLE QVariantList selectAllRuns();
    Q_INVOKABLE QVariantList selectFlashcardsByMateria(int id_materia);
    Q_INVOKABLE QVariantList selectFlashcardsByDificuldade(int dificuldade);
    Q_INVOKABLE QVariantList selectFlashcardsByDificuldadeAndMateria(int dificuldade, int id_materia);
    Q_INVOKABLE QVariantList selectInstaciasByRun(int id_run);

    //Funções de Lógica
    Q_INVOKABLE int escolherFlashcard(const QVariantList &idList);

    //Funções de Atualização
    Q_INVOKABLE void updateAcertos(int id_flashcard);
    Q_INVOKABLE void updateErros(int id_flashcard);

};

#endif