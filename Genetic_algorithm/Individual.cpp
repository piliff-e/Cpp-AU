//
// Created by Филипп Евдокимов on 15.02.2023.
//

#include "Individual.h"
#include <iostream>

namespace {
    /// Выбор случайного числа из заданного диапазона
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    /// \return Случайное число из диапазона от from до to
    inline int random_number(int from, int to) {
        return from + std::rand() % (to - from + 1);
    }
    /// Выбор двух случайных индексов из вектора в заданном диапазоне
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    /// \return Два случайных числа из диапазона от from до to
    inline std::pair<int, int> get_random_numbers(int from, int to) {
        int i = random_number(from, to);
        int j = random_number(from, to);
        /// Добивается различия i и j, если изначально они были равны
        while (i == j) {
            j = random_number(from, to);
        }
        return {i, j};
    }
}

/// Приспособленность особи, то есть целевая функция (может быть любой): f(x,y,z,w) = |(x + 11 * y + 111 * z + 1111 * w) / 100|
inline int Individual::fitness() {
    return abs((individual[0] + 11 * individual[1] + 111 * individual[2] + 1111 * individual[3]) / 100);
}

/// Мутация: случайное изменение генома особи (прибавление случайного числа к случайному элементу вектора)
void Individual::mutation() {
    int n = random_number(0, 5);
    if (n == 0) {
    } else if (n == 1 || n == 2 || n == 3) {
        individual[n] += random_number(-100, 100);
    } else if (n == 4) {
        std::pair<int, int> randoms = get_random_numbers(1, 3);
        individual[randoms.first] += random_number(-100, 100);
        individual[randoms.second] += random_number(-100, 100);
    } else if (n == 5) {
        individual[1] += random_number(-100, 100);
        individual[2] += random_number(-100, 100);
        individual[3] += random_number(-100, 100);
    }
    individual[0] = individual[1] + individual[2] + individual[3];
}

/// Печать особи (вектора из пяти элементов)
inline void Individual::printIndividual() {
    std::cout << individual[0] << " " << individual[1] << " " << individual[2] << " " << individual[3] << " " << individual[4] << std::endl;
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