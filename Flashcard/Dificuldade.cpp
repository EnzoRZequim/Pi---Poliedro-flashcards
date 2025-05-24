#include "Dificuldade.h"

QString dificuldadeParaTexto(Dificuldade d) {
    switch (d) {
    case Dificuldade::Facil: return "Fácil";
    case Dificuldade::Medio: return "Médio";
    case Dificuldade::Dificil: return "Difícil";
    default: return "Desconhecido";
    }
}

Dificuldade textoParaDificuldade(const QString& texto) {
    if (texto.compare("Fácil", Qt::CaseInsensitive) == 0) return Dificuldade::Facil;
    if (texto.compare("Médio", Qt::CaseInsensitive) == 0) return Dificuldade::Medio;
    if (texto.compare("Difícil", Qt::CaseInsensitive) == 0) return Dificuldade::Dificil;
    return Dificuldade::Facil;
}

bool dificuldadeValida(int valor) {
    return valor >= static_cast<int>(Dificuldade::Facil)
    && valor <= static_cast<int>(Dificuldade::Dificil);
}

QList<Dificuldade> listarDificuldades() {
    return {Dificuldade::Facil, Dificuldade::Medio, Dificuldade::Dificil};
}
