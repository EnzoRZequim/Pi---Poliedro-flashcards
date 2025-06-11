#include <iostream>
#include <stdio.h>
#include <list>
#include "Banco/ChamadaBanco.cpp"

using namespace std;

int jogar (int idFlashcard)
{
    cout<< selectPergunta(idFlashcard)<<endl;
    cout<<"escreva 1 para ver a resposta ou 0 para parar: ";
    int opcaoPergunta;
    do
    {
        cin >> opcaoPergunta;
        if (opcaoPergunta == 1)
        {
            cout << "Resposta: " << selectResposta(idFlashcard) << endl;
            cout << "escreva 1 se acertou,2 se errou e 0 para parar: ";
            int opcaoResposta;
            do{
                cin >> opcaoResposta;
                if (opcaoResposta == 1)
                {
                    updateAcertos(idFlashcard);
                    return 1;
                }
                else if (opcaoResposta == 2)
                {
                    updateErros(idFlashcard);
                    return 1;
                }
                else if (opcaoResposta == 0)
                {
                    cout << "Parando o jogo." << endl;
                    return 0;
                }
                else
                {
                    cout << "Opção inválida. Tente novamente:" << endl;
                }
            }
            while (opcaoResposta != 1 && opcaoResposta != 2 && opcaoResposta != 0);

        }
        else if (opcaoPergunta == 0)
        {
            cout << "Parando o jogo." << endl;
            return 0;
        }
        else
        {
            cout << "Opção inválida. Tente novamente:" << endl;
        }
    }
    while (opcaoPergunta != 1 && opcaoPergunta != 0);
}

void estudarFlashcards()
{
    int continuar;
    do
    {
        continuar =jogar(escolherFlashcard(selectAllFlashcards()));
    }
    while (continuar != 0);
}

void estudarPorMateria()
{
}

void menuJogar()
{
    int opcao;
    cout << "Modo de Jogo:" << endl;
    cout << "1 - Estudar Flashcards" << endl;
    cout << "2 - Estudar Flashcards por Matéria" << endl;
    cout << "3 - Estudar Flashcards por Dificuldade" << endl;
    cout << "4 - Estudar Flashcards por Matéria e Dificuldade" << endl;
    cout << "0 - Voltar ao Menu Principal" << endl;
    do
    {
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                estudarFlashcards();
                break;
            case 2:
                // Implementar estudo por matéria
                cout << "Funcionalidade em desenvolvimento." << endl;
                break;
            case 3:
                // Implementar estudo por dificuldade
                cout << "Funcionalidade em desenvolvimento." << endl;
                break;
            case 4:
                // Implementar estudo por matéria e dificuldade
                cout << "Funcionalidade em desenvolvimento." << endl;
                break;
            case 0:
                cout << "Voltando ao menu principal." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente:" << endl;
        }
    }
    while (opcao < 0 || opcao > 4);
}

void menuPrincipal()
{
    int opcao;
    cout << "Escolha uma opção:" << endl;
    cout << "1 - Jogar" << endl;
    cout << "2 - Criar Flashcard" << endl;
    cout << "3 - Ver Flashcards" << endl;
    cout << "4 - Ver Runs" << endl;
    cout << "0 - Sair" << endl;
}

int main()
{
    /*deleteAllTables();
    createTables();
    insertFlashcard("Qual é a capital da França?", "Paris", 1, 2);
    insertFlashcard("Qual é a capital do Brasil?", "Brasília", 1, 1);
    insertFlashcard("abc", "Paris", 3, 4);
    insertMateria("Geografia");
    insertRun(80, 120);
    insertInstancia(1, 1, 30, true);
    printTable("Materias");
    printTable("Runs");
    printTable("Instancias");
    printf("Dificuldade: %d\n", selectDificuldade(1));
    printIDList(selectFlashcardsByMateria(1));
    printPerguntaPorMateria(1);
    clearAllTables();*/

    return 0;
}
