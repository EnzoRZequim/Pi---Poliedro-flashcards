QT = core gui sql

CONFIG += c++17 cmdline
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Dificuldade.cpp \
        Flashcard.cpp \
        FlashcardDAO.cpp \
        FlashcardService.cpp \
        SQLiteConnection.cpp \
        main.cpp

TRANSLATIONS += \
    Flashcard_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Dificuldade.h \
    Flashcard.h \
    FlashcardDAO.h \
    FlashcardService.h \
    SQLiteConnection.h

DISTFILES += \
    ../../../../Pictures/CriaBanco.sql
