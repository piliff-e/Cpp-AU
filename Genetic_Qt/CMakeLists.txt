cmake_minimum_required(VERSION 3.24)
project(Genetic_Qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Genetic_Qt
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        Genetic_main.cpp
        Randoms.cpp Randoms.h
        Individual.cpp Individual.h
        Genetic.cpp Genetic.h
        GeneticApplication.cpp GeneticApplication.h)

target_link_libraries(Genetic_Qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
