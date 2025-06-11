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

# Find all necessary Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick Qml)

# Force all QML modules in this project to be built statically.
set(QT_QML_MODULE_TYPE "static")

# --- Module Definitions ---
# Manually define the FlashCard QML module as a static library.
# This replaces the need for add_subdirectory().
qt_add_qml_module(FlashCard
        URI FlashCard
        VERSION 1.0
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/FlashCard
        QML_FILES
        FlashCards/FlashCard/Constants.qml
        FlashCards/FlashCard/EventListModel.qml
        FlashCards/FlashCard/EventListSimulator.qml
)

# Manually define the FlashCardContent QML module as a static library.
qt_add_qml_module(FlashCardContent
        URI FlashCardContent
        VERSION 1.0
        OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/FlashCardContent
        QML_FILES
        FlashCards/FlashCardContent/App.qml
        FlashCards/FlashCardContent/TelaCriaEditaFlashcard.qml
        FlashCards/FlashCardContent/TelaCriaEditaGeral.qml
        FlashCards/FlashCardContent/TelaHistoricoGeral.qml
        FlashCards/FlashCardContent/TelaInicio.qml
        FlashCards/FlashCardContent/TelaPergunta.qml
        FlashCards/FlashCardContent/TelaPopUpSair.qml
        FlashCards/FlashCardContent/TelaResposta.qml
)

# --- Main Application Definition ---
# Define the main application executable
add_executable(FlashCardsApp
        FlashCards/App/main.cpp
        FlashCards/Banco/PonteBackFront.cpp
        FlashCards/Banco/ChamadaBanco.cpp
        FlashCards/Banco/sqlite/sqlite3.c
)

# Tell the application where to find its C++ header files
target_include_directories(FlashCardsApp PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/FlashCards/Banco"
        "${CMAKE_CURRENT_SOURCE_DIR}/FlashCards/Banco/sqlite"
)

# Manually and explicitly link the main application against all necessary libraries.
target_link_libraries(FlashCardsApp PRIVATE
        # Link the core Qt libraries needed by the application.
        Qt6::Widgets
        Qt6::Quick
        Qt6::Qml

        # Use linker flags to force the inclusion of all code from our static
        # QML plugin libraries. This is the most reliable way to solve
        # "undefined reference" errors with static plugins on MinGW.
        -Wl,--whole-archive
        FlashCard
        FlashCardContent
        -Wl,--no-whole-archive
)
