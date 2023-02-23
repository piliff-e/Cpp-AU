cmake_minimum_required(VERSION 3.24)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneticAlgorithm
        main.cpp
        Randoms.cpp Randoms.h
        Individual.cpp Individual.h
        Genetic.cpp Genetic.h
        GeneticApplication.cpp GeneticApplication.h)