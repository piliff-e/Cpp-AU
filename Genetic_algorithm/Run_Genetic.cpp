//
// Created by Филипп Евдокимов on 04.02.2023.
//

#include "Run_Genetic.h"
#include "Genetic.h"
#include <iostream>

/// Ввод с клавиатуры чисел, которые в дальнейшем будут преобразованы в "родительских" особей
void GeneticApplication::input() {
    std::cout << "Choose two six-digit numbers:\n" << "\t1) ";
    std::cin >> n1;
    std::cout << "\t2) ";
    std::cin >> n2;
    std::cout << std::endl;
}

/// Запуск проекта Genetic_algorithm
int GeneticApplication::run() {
    srand(time(nullptr));
    input();
    Genetic evol(n1, n2);
    std::cout << evol.Start() << " iterations" << std::endl;
    return 0;
}