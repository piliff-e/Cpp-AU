cmake_minimum_required(VERSION 3.24)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GeneticAlgorithm
        main.cpp
        Randoms.cpp Randoms.h
        Individual.cpp Individual.h
        Genetic.cpp Genetic.h
        GeneticApplication.cpp GeneticApplication.h)

target_link_libraries(GeneticAlgorithm
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )