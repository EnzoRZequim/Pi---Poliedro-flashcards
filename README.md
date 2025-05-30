# TDD
-----
# como testar
o teste foi implantando nesta branch **(teste-banco)**. Realizar o pull e verficar se todas as dependências do projeto  
estam corretamente na pasta  
_____________
# DAO
Os metodos foram criados junto com a instanciação do banco no arquivo **(ChamadaBanco.cpp)**
_____________
# TDD
foram feitas os testes na estrutura do método main  
int main()  
{  
    deleteAllTables();  
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
    clearAllTables();  
  
  return 0;  
}  

# Os resultados foram :  
Tabela deletada com sucesso!  
Tabela deletada com sucesso!  
Tabela deletada com sucesso!  
Tabela deletada com sucesso!  
Tabelas criadas com sucesso!  
Flashcard inserido com sucesso!  
Flashcard inserido com sucesso!  
Flashcard inserido com sucesso!  
Materia inserida com sucesso!  
Run inserido com sucesso!  
Instancia inserida com sucesso!  
ID_Materia = 1  
Nome_Materia = Geografia  
  
ID_Run = 1  
Taxa_acerto = 80  
Tempo_total = 120  

ID_Instancia = 1  
ID_Run = 1  
ID_Flashcard = 1  
Tempo_resposta = 30  
Acertou = 1  

Dificuldade: 2  
Flashcards de Geografia: 1 2  
Pergunta ID 1: Qual é a capital da França?  
Pergunta ID 2: Qual é a capital do Brasil?  
Tabela limpa com sucesso!  
Tabela limpa com sucesso!  
Tabela limpa com sucesso!  
Tabela limpa com sucesso!  
  
Process finished with exit code 0  

testamos sem subir a aplicação que estava no ciclo red, pois refatoramos em seguida(primeiro instanciamos o metodo de selecionar flashcards por materia usando um vector, e substituimos o método por um list para mostrar os flashcards relacionado à matéria)

