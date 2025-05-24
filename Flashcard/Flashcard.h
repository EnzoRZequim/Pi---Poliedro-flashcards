#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QString>
#include "Dificuldade.h"

class Flashcard {
public:
    int id;
    QString pergunta;
    QString resposta;
    int idMateria;
    Dificuldade dificuldade;
    int acertos;
    int erros;
    int melhorTempoResposta;

    Flashcard(const QString& pergunta,
              const QString& resposta,
              int idMateria,
              Dificuldade dificuldade,
              int acertos = 0,
              int erros = 0,
              int melhorTempoResposta = 0);
};

#endif

// #endif // FLASHCARD_H
// class Flashcard {
// public:
//     int id;
//     QString pergunta;
//     QString resposta;
//     int idSubmateria;
//     Dificuldade dificuldade;  // ALTERADO de int para enum
//     int acertos;
//     int erros;
//     int melhorTempoResposta;

//     // Construtores atualizados:
//     Flashcard(int id,
//               const QString& pergunta,
//               const QString& resposta,
//               int idSubmateria,
//               Dificuldade dificuldade,
//               int acertos,
//               int erros,
//               int melhorTempoResposta);

//     Flashcard(const QString& pergunta,
//               const QString& resposta,
//               int idSubmateria,
//               Dificuldade dificuldade,
//               int acertos = 0,
//               int erros = 0,
//               int melhorTempoResposta = 0);
// };
// #endif // FLASHCARD_H
