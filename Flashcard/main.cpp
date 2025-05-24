#include "SQLiteConnection.h"
#include <QCoreApplication>
#include <QDebug>
#include "FlashcardDAO.h"
#include "FlashcardService.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    SQLiteConnection conn("C:/Users/GAMER/Documents/PI-Flashcard/Pi---Poliedro-flashcards/Flashcard/banco.db");

    if (!conn.conectar()) {
        qDebug() << "Falha ao conectar ao banco.";
        return -1;
    }

    FlashcardService::criarEInserirFlashcard("Quem descobriu o Brasil?", "Pedro Álvares Cabral", "História", 2);
    FlashcardService::criarEInserirFlashcard("Em que ano o Corinthians foi fundado?", "1910", "História", 1);
    FlashcardService::criarEInserirFlashcard("Qual a fórmula química da água?", "H2O", "Química", 3);
    FlashcardService::criarEInserirFlashcard("Qual o valor de PI?", "3,14", "Matemática", 3);
    FlashcardService::criarEInserirFlashcard("O que é verbo?", "Um verbo é uma palavra que expressa uma ação, um estado ou um fenômeno da natureza dentro de uma frase", "Português", 2);
    FlashcardService::criarEInserirFlashcard("O que é relevo?", "São diferentes formas e elevações da superfície terrestre, como montanhas, planícies, planaltos e depressões", "Geografia", 2);

    int idParaRemover = 0;
    bool sucesso = FlashcardDAO::removerFlashcard(idParaRemover);
    qDebug() << (sucesso ? "Flashcard removido." : "Falha ao remover flashcard.");

    QList<int> idsParaRemover = {};
    bool sucessoLote = FlashcardDAO::removerFlashcards(idsParaRemover);
    qDebug() << (sucessoLote ? "Remoção em lote concluída." : "Falha na remoção em lote.");

    return a.exec();
}
