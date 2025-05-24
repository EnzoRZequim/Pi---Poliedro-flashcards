#include "FlashcardDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int FlashcardDAO::obterMaiorID() {
    QSqlQuery query("SELECT MAX(ID_Flashcard) FROM Flashcards");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

bool FlashcardDAO::salvarFlashcard(Flashcard& f) {
    int novoID = obterMaiorID() + 1;
    f.id = novoID;

    QSqlQuery query;
    query.prepare("INSERT INTO Flashcards "
                  "(ID_Flashcard, Pergunta, Resposta, ID_Materia, Dificuldade, Acertos, Erros, Melhor_tempo_resposta) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(f.id);
    query.addBindValue(f.pergunta);
    query.addBindValue(f.resposta);
    query.addBindValue(f.idMateria);
    query.addBindValue(static_cast<int>(f.dificuldade));
    query.addBindValue(f.acertos);
    query.addBindValue(f.erros);
    query.addBindValue(f.melhorTempoResposta);

    if (!query.exec()) {
        qDebug() << "Erro ao salvar flashcard:" << query.lastError().text();
        return false;
    }

    qDebug() << "Flashcard salvo com sucesso com ID:" << f.id;
    return true;
}

bool FlashcardDAO::removerFlashcard(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Flashcards WHERE ID_Flashcard = ?");
    query.addBindValue(id);
    return query.exec();
}

bool FlashcardDAO::removerFlashcards(const QList<int>& ids) {
    if (ids.isEmpty()) return false;
    QStringList placeholders;
    for (int i = 0; i < ids.size(); ++i) placeholders << "?";
    QString sql = QString("DELETE FROM Flashcards WHERE ID_Flashcard IN (%1)")
                      .arg(placeholders.join(", "));

    QSqlQuery query;
    query.prepare(sql);
    for (int id : ids) query.addBindValue(id);

    return query.exec();
}

