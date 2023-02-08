//
// Created by Филипп Евдокимов on 14.12.2022.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Genetic.h"

namespace {
/// Выбор случайного числа из заданного диапазона
/// \param from (начало диапазона)
/// \param to (конец диапазона)
/// \return Случайное число из диапазона от from до to
    inline int random_number(int from, int to) {
        return from + rand() % (to - from + 1);
    }

}
/// Выбор двух случайных индексов из вектора в заданном диапазоне
/// \param from (начало диапазона)
/// \param to (конец диапазона)
/// \return Два случайных числа из диапазона от from до to
inline pair<int, int> get_random_numbers(int from, int to) {
    int i = random_number(from, to);
    int j = random_number(from, to);
    /// Добивается различия i и j, если изначально они были равны
    while (i == j) {
        j = random_number(from, to);
    }
    return {i, j};
}

/// Приспособленность особи, то есть целевая функция (может быть любой): f(x,y,z,w) = |(x + 11 * y + 111 * z + 1111 * w) / 100|
/// \return Приспособленность особи
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
        pair<int, int> randoms = get_random_numbers(1, 3);
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
inline void Individual::print_individual() {
    cout << individual[0] << " " << individual[1] << " " << individual[2] << " " << individual[3] << " " << individual[4] << endl;
}

/// Кроссинговер: скрещивание двух особей (получение 8 векторов из 2 путём перемешивания их элементов)
/// \param a (первая скрещиваемая особь)
/// \param b (вторая скрещиваемая особь)
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
/// \param a (первый "родитель")
/// \param b (второй "родитель")
void Genetic::create_population(const Individual &a, const Individual &b) {
    population.push_back(a);
    population.push_back(b);
    /// Добавляет в популяцию из двух особей оставшихся до 128 путём их скрещивания
    while (population.size() <= 122) {
        pair<int, int> randoms = get_random_numbers(0, population.size() - 1);
        Individual x = population[randoms.first];
        Individual y = population[randoms.second];
        crossover(x, y);
    }
    /// Применяет случайную мутацию к каждой особи получившейся популяции
    for (auto & i : population) i.mutation();
}

/// Вычисление приспособленности каждой особи популяции (применение целевой функции к каждому вектору из вектора векторов)
void Genetic::calc_fitness() {
    for (int i = 0; i < population.size(); i++)
        population[i][4] = population[i].fitness();
}

/// Селекция: отбор наиболее приспособленных особей (удаление из конца вектора векторов половины векторов)
void Genetic::selection() {
    calc_fitness(); /// Вычисление приспособленности каждой особи
    sort(population.begin(), population.end(), [this] (const Individual &a, const Individual &b){
        return (a < b);});
    population.erase(population.begin() + (population.size() / 2), population.end());
}

/// Эволюция: создание новых популяций и проведение селекции до решения задачи (...)
/// \return Количество популяций (итераций), потребовавшихся для решения задачи
int Genetic::evolution() {
    while (population[0][4] != 0) {
        pair<int, int> randoms = get_random_numbers(0, population.size() - 1);
        Individual x = population[randoms.first];
        Individual y = population[randoms.second];
        create_population(x, y);
        selection();
        iterations += 1;
        cout << "Iteration " << iterations << ":\n\tBest solution: " << population[0][4] << "\n\tWorst solution: "
             << population[population.size() - 1][4] << "\n\n";
    }
    return iterations;
}