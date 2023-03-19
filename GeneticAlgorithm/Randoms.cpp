//
// Created by Филипп Евдокимов on 22.02.2023.
//

#include "Randoms.h"

Randoms::Randomizer Randoms::Randomizer::r;

/// Конструктор класса Randoms
Randoms::Randoms(int n1, int n2) {
    from = n1;
    to = n2;
}

/// Выбор случайного числа из заданного диапазона
int Randoms::randomNumber() {
    return from + std::rand() % (to - from + 1);
}

/// Выбор двух случайных индексов из вектора в заданном диапазоне
std::pair<int, int> Randoms::twoRandomNumbers() {
    Randoms range = {from, to};
    int i = range.randomNumber();
    int j = range.randomNumber();
    /// Добивается различия i и j, если изначально они были равны
    while (i == j) {
        j = range.randomNumber();
    }
    return {i, j};
}