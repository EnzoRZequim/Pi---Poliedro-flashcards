#ifndef FLASHCARDSERVICE_H
#define FLASHCARDSERVICE_H

#include <QString>

class FlashcardService {
public:
    static void criarEInserirFlashcard(const QString& pergunta,
                                       const QString& resposta,
                                       const QString& materia,
                                       int dificuldade);
    static int obterOuCriarMateria(const QString& nomeMateria);
};

#endif

// class FlashcardService {
// public:
//     static void criarEInserirFlashcard(const QString& pergunta,
//                                        const QString& resposta,
//                                        const QString& submateria,
//                                        int dificuldade);
// private:
//     static int obterOuCriarSubmateria(const QString& nomeSubmateria);
// };

// #endif
