#include "PonteBackFront.h"
#include "ChamadaBanco.h"

// Função auxiliar para converter QVariantList para std::list<int>
std::list<int> toIntList(const QVariantList &variantList) {
    std::list<int> intList;
    for (const QVariant &v : variantList) {
        intList.push_back(v.toInt());
    }
    return intList;
}

// Função auxiliar para converter std::list<int> para QVariantList
QVariantList toVariantList(const std::list<int> &intList) {
    QVariantList variantList;
    for (int i : intList) {
        variantList.append(i);
    }
    return variantList;
}

PonteBackFront::PonteBackFront(QObject *parent) : QObject(parent) {}

// --- Funções de Criação e Inserção ---
void PonteBackFront::insertFlashcard(const QString &p, const QString &r, int id_m, int d) { ::insertFlashcard(p.toStdString(), r.toStdString(), id_m, d); }
void PonteBackFront::insertMateria(const QString &n) { ::insertMateria(n.toStdString()); }
void PonteBackFront::insertRun(int ta, int tt) { ::insertRun(ta, tt); }
void PonteBackFront::insertInstancia(int id_r, int id_f, int tr, bool a) { ::insertInstancia(id_r, id_f, tr, a); }

// --- Funções de Limpeza e Deleção ---
void PonteBackFront::clearTable(const QString &t) { ::clearTable(t.toStdString()); }
void PonteBackFront::clearAllTables() { ::clearAllTables(); }
void PonteBackFront::deleteTable(const QString &t) { ::deleteTable(t.toStdString()); }
void PonteBackFront::deleteAllTables() { ::deleteAllTables(); }

// --- Funções de Seleção (Select) ---
bool PonteBackFront::selectAcertou(int id) { return ::selectAcertou(id); }
QString PonteBackFront::selectPergunta(int id) { return QString::fromStdString(::selectPergunta(id)); }
QString PonteBackFront::selectResposta(int id) { return QString::fromStdString(::selectResposta(id)); }
int PonteBackFront::selectIDMateriaFromFlashcards(int id) { return ::selectIDMateriaFromFlashcards(id); }
int PonteBackFront::selectDificuldade(int id) { return ::selectDificuldade(id); }
int PonteBackFront::selectAcertos(int id) { return ::selectAcertos(id); }
int PonteBackFront::selectErros(int id) { return ::selectErros(id); }
int PonteBackFront::selectMelhorTempoResposta(int id) { return ::selectMelhorTempoResposta(id); }
QString PonteBackFront::selectNomeMateria(int id) { return QString::fromStdString(::selectNomeMateria(id)); }
int PonteBackFront::selectIDRunFromInstancias(int id) { return ::selectIDRunFromInstancias(id); }
int PonteBackFront::selectIDFlashcardFromInstancias(int id) { return ::selectIDFlashcardFromInstancias(id); }
int PonteBackFront::selectTempoResposta(int id) { return ::selectTempoResposta(id); }
int PonteBackFront::selectTaxaAcerto(int id) { return ::selectTaxaAcerto(id); }
int PonteBackFront::selectTaxaErro(int id) { return ::selectTaxaErro(id); }

QVariantList PonteBackFront::selectAllFlashcards() { return toVariantList(::selectAllFlashcards()); }
QVariantList PonteBackFront::selectAllMaterias() { return toVariantList(::selectAllMaterias()); }
QVariantList PonteBackFront::selectAllRuns() { return toVariantList(::selectAllRuns()); }
QVariantList PonteBackFront::selectFlashcardsByMateria(int id) { return toVariantList(::selectFlashcardsByMateria(id)); }
QVariantList PonteBackFront::selectFlashcardsByDificuldade(int d) { return toVariantList(::selectFlashcardsByDificuldade(d)); }
QVariantList PonteBackFront::selectFlashcardsByDificuldadeAndMateria(int d, int id) { return toVariantList(::selectFlashcardsByDificuldadeAndMateria(d, id)); }
QVariantList PonteBackFront::selectInstaciasByRun(int id) { return toVariantList(::selectInstaciasByRun(id)); }

// --- Funções de Lógica ---
int PonteBackFront::escolherFlashcard(const QVariantList &idList) {
    return ::escolherFlashcard(toIntList(idList));
}

// --- Funções de Atualização (Update) ---
void PonteBackFront::updateAcertos(int id) { ::updateAcertos(id); }
void PonteBackFront::updateErros(int id) { ::updateErros(id); }