#ifndef DIFICULDADE_H
#define DIFICULDADE_H

#include <QString>
#include <QList>

enum class Dificuldade {
    Facil = 1,
    Medio = 2,
    Dificil = 3
};

QString dificuldadeParaTexto(Dificuldade d);
Dificuldade textoParaDificuldade(const QString& texto);


bool dificuldadeValida(int valor);
QList<Dificuldade> listarDificuldades();

#endif

