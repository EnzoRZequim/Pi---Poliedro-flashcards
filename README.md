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

