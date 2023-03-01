//
// Created by Филипп Евдокимов on 15.02.2023.
//

#include "Individual.h"
#include "Randoms.h"

/// Приспособленность особи, то есть целевая функция (может быть любой): f(x,y,z,w) = |(x + 11 * y + 111 * z + 1111 * w) / 100|
int Individual::fitness() {
    return abs((individual[0] + 11 * individual[1] + 111 * individual[2] + 1111 * individual[3]) / 100);
}

/// Мутация: случайное изменение генома особи (прибавление случайного числа к случайному элементу вектора)
void Individual::mutation() {
    Randoms scenarios = {0, 5};
    int scenario = scenarios.randomNumber();
    if (scenario == 0) {
    } else if (scenario == 1 || scenario == 2 || scenario == 3) {
        Randoms range = {-100, 100};
        individual[scenario] += range.randomNumber();
    } else if (scenario == 4) {
        Randoms indexes = {1, 3};
        std::pair<int, int> randomIndexes = indexes.twoRandomNumbers();
        Randoms range = {-100, 100};
        individual[randomIndexes.first] += range.randomNumber();
        individual[randomIndexes.second] += range.randomNumber();
    } else if (scenario == 5) {
        Randoms range = {-100, 100};
        individual[1] += range.randomNumber();
        individual[2] += range.randomNumber();
        individual[3] += range.randomNumber();
    }
    individual[0] = individual[1] + individual[2] + individual[3];
}

/// Печать особи (вектора из пяти элементов)
inline void Individual::printIndividual() {
    std::cout << individual[0] << " " << individual[1] << " " << individual[2] << " " << individual[3] << " "
              << individual[4] << std::endl;
}

/// Создание особи (формирование вектора из пяти элементов из данного шестизначного числа)
Individual::Individual(int n) {
    int a1 = n / 10000;
    int a2 = (n / 100) % 100;
    int a3 = n % 100;
    individual = {(a1 + a2 + a3), a1, a2, a3, 1};
}

/// Создание особи (формирование вектора из пяти элементов из пяти данных числел)
Individual::Individual(int n0, int n1, int n2, int n3, int n4) {
    individual = {n0, n1, n2, n3, n4};
}