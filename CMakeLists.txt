cmake_minimum_required(VERSION 3.31)
project(Pi___Poliedro_flashcards)

# Adicione o SQLite ao projeto
add_library(sqlite3 STATIC Banco/sqlite/sqlite3.c)  # Compila o SQLite como estático

# Configurações do executável
set(CMAKE_CXX_STANDARD 14)

add_executable(Pi___Poliedro_flashcards
        Banco/ChamadaBanco.cpp)

# Vincule o SQLite ao executável
target_include_directories(Pi___Poliedro_flashcards PRIVATE Banco/sqlite)  # Inclui o diretório do SQLite
target_link_libraries(Pi___Poliedro_flashcards sqlite3)