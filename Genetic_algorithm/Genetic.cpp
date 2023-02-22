//
// Created by Филипп Евдокимов on 14.12.2022.
//

#include <iostream>
#include "Genetic.h"

namespace {
    /// Выбор случайного числа из заданного диапазона
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    /// \return Случайное число из диапазона от from до to
    inline int randomNumber(int from, int to) {
        return from + std::rand() % (to - from + 1);
    }

    /// Выбор двух случайных индексов из вектора в заданном диапазоне
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    /// \return Два случайных числа из диапазона от from до to
    inline std::pair<int, int> getRandomNumbers(int from, int to) {
        int i = randomNumber(from, to);
        int j = randomNumber(from, to);
        /// Добивается различия i и j, если изначально они были равны
        while (i == j) {
            j = randomNumber(from, to);
        }
        return {i, j};
    }
}


/// Кроссинговер: скрещивание двух особей (получение 8 векторов из 2 путём перемешивания их элементов)
void Genetic::crossover(const Individual &a, const Individual &b) {
    Individual c1 = {(a[1] + a[2] + b[3]), a[1], a[2], b[3], 1};
    Individual c2 = {(a[1] + b[2] + a[3]), a[1], b[2], a[3], 1};
    Individual c3 = {(a[1] + b[2] + b[3]), a[1], b[2], b[3], 1};
    Individual c4 = {(b[1] + a[2] + a[3]), b[1], a[2], a[3], 1};
    Individual c5 = {(b[1] + a[2] + b[3]), b[1], a[2], b[3], 1};
    Individual c6 = {(b[1] + b[2] + a[3]), b[1], b[2], a[3], 1};
    population.push_back(c1);
    population.push_back(c2);
    population.push_back(c3);
    population.push_back(c4);
    population.push_back(c5);
    population.push_back(c6);
}

/// Формирование популяции из 128 особей (создание вектора векторов длины 128)
void Genetic::createPopulation(const Individual &a, const Individual &b) {
    population.push_back(a);
    population.push_back(b);
    /// Добавляет в популяцию из двух особей оставшихся до 128 путём их скрещивания
    while (population.size() <= 122) {
        std::pair<int, int> randoms = getRandomNumbers(0, population.size() - 1);
        Individual x = population[randoms.first];
        Individual y = population[randoms.second];
        crossover(x, y);
    }
    /// Применяет случайную мутацию к каждой особи получившейся популяции
    for (auto & i : population) i.mutation();
}

/// Вычисление приспособленности каждой особи популяции (применение целевой функции к каждому вектору из вектора векторов)
void Genetic::calcFitness() {
    for (int i = 0; i < population.size(); i++)
        population[i][4] = population[i].fitness();
}

/// Селекция: отбор наиболее приспособленных особей (удаление из конца вектора векторов половины векторов)
void Genetic::selection() {
    calcFitness(); /// Вычисление приспособленности каждой особи
    sort(population.begin(), population.end(), [this] (const Individual &a, const Individual &b){
        return (a < b);});
    population.erase(population.begin() + (population.size() / 2), population.end());
}

/// Эволюция: создание новых популяций и проведение селекции до решения задачи (...)
int Genetic::evolution() {
    while (population[0][4] != 0) {
        std::pair<int, int> randoms = getRandomNumbers(0, population.size() - 1);
        Individual x = population[randoms.first];
        Individual y = population[randoms.second];
        createPopulation(x, y);
        selection();
        iterations += 1;
        std::cout << "Iteration " << iterations << ":\n\tBest solution: " << population[0][4] << "\n\tWorst solution: "
             << population[population.size() - 1][4] << "\n\n";
    }
    return iterations;
}

/// Запуск эволюции
int Genetic::Start() {
    return evolution();
}

/// Конструктор класса Genetic: формирование популяции из двух "родительских" особей, заданных фиксированными шестизначными числами
Genetic::Genetic(int n1, int n2) {
    Individual a (n1);
    Individual b (n2);
    createPopulation(a, b);
}