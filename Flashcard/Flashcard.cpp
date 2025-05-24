#include "Flashcard.h"

Flashcard::Flashcard(const QString& pergunta,
                     const QString& resposta,
                     int idMateria,
                     Dificuldade dificuldade,
                     int acertos,
                     int erros,
                     int melhorTempoResposta)
    : id(0),
    pergunta(pergunta),
    resposta(resposta),
    idMateria(idMateria),
    dificuldade(dificuldade),
    acertos(acertos),
    erros(erros),
    melhorTempoResposta(melhorTempoResposta)
{}
// Flashcard::Flashcard(int id,
//                      const QString& pergunta,
//                      const QString& resposta,
//                      int idSubmateria,
//                      Dificuldade dificuldade,
//                      int acertos,
//                      int erros,
//                      int melhorTempoResposta)
//     : id(id),
//     pergunta(pergunta),
//     resposta(resposta),
//     idSubmateria(idSubmateria),
//     dificuldade(dificuldade),
//     acertos(acertos),
//     erros(erros),
//     melhorTempoResposta(melhorTempoResposta)
// {}

// Flashcard::Flashcard(const QString& pergunta,
//                      const QString& resposta,
//                      int idSubmateria,
//                      Dificuldade dificuldade,
//                      int acertos,
//                      int erros,
//                      int melhorTempoResposta)
//     : id(0),
//     pergunta(pergunta),
//     resposta(resposta),
//     idSubmateria(idSubmateria),
//     dificuldade(dificuldade),
//     acertos(acertos),
//     erros(erros),
//     melhorTempoResposta(melhorTempoResposta)
// {}
