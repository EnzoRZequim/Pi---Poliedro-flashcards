#ifndef FLASHCARDDAO_H
#define FLASHCARDDAO_H

#include "Flashcard.h"
#include <QList>

class FlashcardDAO {
public:
    static bool salvarFlashcard(Flashcard& flashcard);
    static bool removerFlashcard(int id);
    static bool removerFlashcards(const QList<int>& ids);
    static int obterMaiorID();
};

#endif

