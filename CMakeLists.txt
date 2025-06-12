# Use a modern CMake version
cmake_minimum_required(VERSION 3.16)

# Define the project name
project(FlashCardsProject)

# Set the C++ standard and other global settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick Qml)


# --- Define os ficheiros QML a serem incluídos como recursos ---
set(QML_FILES
    FlashCards/FlashCard/Constants.qml
    FlashCards/FlashCard/EventListModel.qml
    FlashCards/FlashCard/EventListSimulator.qml
    FlashCards/FlashCardContent/App.qml
    FlashCards/FlashCardContent/TelaCriaEditaFlashcard.qml
    FlashCards/FlashCardContent/TelaCriaEditaGeral.qml
    FlashCards/FlashCardContent/TelaHistoricoGeral.qml
    FlashCards/FlashCardContent/TelaInicio.qml
    FlashCards/FlashCardContent/TelaPergunta.qml
    FlashCards/FlashCardContent/TelaPopUpSair.qml
    FlashCards/FlashCardContent/TelaResposta.qml
)


# --- Define a Aplicação Principal ---
add_executable(FlashCardsApp
    FlashCards/App/main.cpp
    FlashCards/Banco/PonteBackFront.cpp
    FlashCards/Banco/ChamadaBanco.cpp
    FlashCards/Banco/sqlite/sqlite3.c
)

# --- Adiciona os ficheiros QML e de Imagem ao executável ---
qt_add_resources(FlashCardsApp "qml_resources"
    PREFIX "/"
    FILES
        ${QML_FILES}
)

# Informa a aplicação onde encontrar os seus ficheiros de cabeçalho C++
target_include_directories(FlashCardsApp PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/FlashCards/Banco"
    "${CMAKE_CURRENT_SOURCE_DIR}/FlashCards/Banco/sqlite"
)

# Liga a aplicação às bibliotecas Qt necessárias, INCLUINDO o plugin de imagem
target_link_libraries(FlashCardsApp PRIVATE
    Qt6::Widgets
    Qt6::Quick
    Qt6::Qml
)
