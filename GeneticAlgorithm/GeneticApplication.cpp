//
// Created by Филипп Евдокимов on 04.02.2023.
//

#include "GeneticApplication.h"
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

    input();

    Genetic evolution(n1, n2);
    const auto iterationsNumber = evolution.startEvolution();
    std::cout << iterationsNumber << " iterations" << std::endl;

    return 0;
}