cmake_minimum_required(VERSION 3.24)
project(Genetic_algorithm_2)

set(CMAKE_CXX_STANDARD 17)

include_directories("${CMAKE_SOURCE_DIR}/Genetic" "${CMAKE_SOURCE_DIR}/Run_Genetic")

add_executable(Genetic_algorithm_2 main.cpp Genetic/Genetic.cpp Genetic/Genetic.h Run_Genetic/Run_Genetic.cpp Run_Genetic/Run_Genetic.h)