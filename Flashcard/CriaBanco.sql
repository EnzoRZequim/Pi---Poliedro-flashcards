CREATE TABLE Flashcards (
    ID_Flashcard INT PRIMARY KEY UNIQUE,
    Pergunta VARCHAR(255) NOT NULL,
    Resposta VARCHAR(255) NOT NULL,
    ID_Submateria INT NOT NULL,
    Dificuldade INT NOT NULL,
    Acertos INT NOT NULL,
    Erros INT NOT NULL,
    Melhor_tempo_resposta INT NOT NULL
);

CREATE TABLE Submaterias (
    ID_Submateria INT PRIMARY KEY UNIQUE,
    Nome_Submateria VARCHAR(255) NOT NULL,
    ID_Materia INT NOT NULL
);

CREATE TABLE Materias (
    ID_Materia INT PRIMARY KEY UNIQUE,
    Nome_Materia VARCHAR(255) NOT NULL
);

CREATE TABLE Runs (
    ID_Run int PRIMARY KEY UNIQUE,
    Taxa_acerto int NOT NULL,
    Tempo_total int NOT NULL
);

CREATE TABLE Instancias (
    ID_Instancia int PRIMARY KEY UNIQUE,
    ID_Run int NOT NULL,
    ID_Flashcard int NOT NULL,
    Tempo_resposta int NOT NULL,
    Acertou BOOLEAN NOT NULL
);