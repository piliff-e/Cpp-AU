cmake_minimum_required(VERSION 3.24)
project(Genetic_algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Genetic_algorithm main.cpp Genetic.cpp Genetic.h Run_Genetic.h Run_Genetic.cpp)