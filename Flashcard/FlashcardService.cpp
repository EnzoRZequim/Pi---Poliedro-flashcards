#include "FlashcardService.h"
#include "Dificuldade.h"
#include "Flashcard.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "FlashcardDAO.h"

int FlashcardService::obterOuCriarMateria(const QString& nomeMateria) {
    QSqlQuery query;
    query.prepare("SELECT ID_Materia FROM Materias WHERE Nome_Materia = ?");
    query.addBindValue(nomeMateria);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    // Gerar novo ID manualmente
    QSqlQuery maxIdQuery("SELECT MAX(ID_Materia) FROM Materias");
    int novoId = 1;
    if (maxIdQuery.exec() && maxIdQuery.next()) {
        novoId = maxIdQuery.value(0).toInt() + 1;
    }

    QSqlQuery insert;
    insert.prepare("INSERT INTO Materias (ID_Materia, Nome_Materia) VALUES (?, ?)");
    insert.addBindValue(novoId);
    insert.addBindValue(nomeMateria);

    if (!insert.exec()) {
        qDebug() << "Erro ao inserir matéria:" << insert.lastError().text();
        return -1;
    }

    return novoId;
}

void FlashcardService::criarEInserirFlashcard(const QString& pergunta,
                                              const QString& resposta,
                                              const QString& materia,
                                              int dificuldade) {
    if (!dificuldadeValida(dificuldade)) {
        qDebug() << "Dificuldade inválida:" << dificuldade;
        return;
    }

    int idMateria = obterOuCriarMateria(materia);
    if (idMateria <= 0) {
        qDebug() << "Erro ao encontrar ou criar matéria.";
        return;
    }

    Dificuldade nivelEnum = static_cast<Dificuldade>(dificuldade);
    Flashcard flashcard(pergunta, resposta, idMateria, nivelEnum);

    if (FlashcardDAO::salvarFlashcard(flashcard)) {
        qDebug() << "Flashcard criado e salvo com sucesso!";
    }
}



// Cria e insere o flashcard com vínculo à submatéria
// void FlashcardService::criarEInserirFlashcard(const QString& pergunta,
//                                               const QString& resposta,
//                                               const QString& submateria,
//                                               int dificuldade) {
//     if (!dificuldadeValida(dificuldade)) {
//         qDebug() << "Dificuldade inválida:" << dificuldade;
//         return;
//     }

//     int idSubmateria = obterOuCriarSubmateria(submateria);
//     qDebug() << "ID da submatéria recebido:" << idSubmateria;

//     if (idSubmateria <= 0) {
//         qDebug() << "Erro ao encontrar ou criar submatéria.";
//         return;
//     }

//     Dificuldade nivelEnum = static_cast<Dificuldade>(dificuldade);
//     Flashcard flashcard(pergunta, resposta, idSubmateria, nivelEnum);

//     if (FlashcardDAO::salvarFlashcard(flashcard)) {
//         qDebug() << "Flashcard criado e salvo com sucesso!";
//     }
// }


// int FlashcardService::obterOuCriarSubmateria(const QString& nomeSubmateria) {
//     QSqlQuery query;
//     query.prepare("SELECT ID_Submateria FROM Submaterias WHERE Nome_Submateria = ?");
//     query.addBindValue(nomeSubmateria);

//     if (query.exec() && query.next()) {
//         return query.value(0).toInt();
//     }

//     QSqlQuery maxIdQuery("SELECT MAX(ID_Submateria) FROM Submaterias");
//     int novoId = 1;
//     if (maxIdQuery.exec() && maxIdQuery.next()) {
//         novoId = maxIdQuery.value(0).toInt() + 1;
//     }

//     QSqlQuery insert;
//     insert.prepare("INSERT INTO Submaterias (ID_Submateria, Nome_Submateria) VALUES (?, ?)");
//     insert.addBindValue(novoId);
//     insert.addBindValue(nomeSubmateria);

//     if (!insert.exec()) {
//         qDebug() << "Erro ao inserir submatéria:" << insert.lastError().text();
//         return -1;
//     }
//     return novoId;
// }

// void FlashcardService::criarEInserirFlashcard(const QString& pergunta,
//                                               const QString& resposta,
//                                               const QString& submateria,
//                                               int dificuldade) {
//     if (!dificuldadeValida(dificuldade)) {
//         qDebug() << "Dificuldade inválida:" << dificuldade;
//         return;
//     }

//     int idSubmateria = obterOuCriarSubmateria(submateria);
//     if (idSubmateria <= 0) {
//         qDebug() << "Erro ao encontrar ou criar submateria.";
//         return;
//     }

//     Dificuldade nivelEnum = static_cast<Dificuldade>(dificuldade);
//     Flashcard flashcard(pergunta, resposta, idSubmateria, nivelEnum);

//     if (FlashcardDAO::salvarFlashcard(flashcard)) {
//         qDebug() << "Flashcard criado e salvo com sucesso!";
//     }
// }
