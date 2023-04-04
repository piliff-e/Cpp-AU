//
// Created by Филипп Евдокимов on 14.12.2022.
//

#pragma once

#include <vector>
#include "Individual.h"

/// Класс популяции с основными методами, реализующими генетический алгоритм, то есть эволюционный процесс
class Genetic {
public:
    /// Конструктор класса Genetic: формирование популяции из двух "родительских" особей, заданных фиксированными шестизначными числами
    /// \param n1 (фиксированное шестизначное число)
    /// \param n2 (фиксированное шестизначное число)
    Genetic(int n1, int n2);

    /// Кроссинговер: скрещивание двух особей (получение 8 векторов из 2 путём перемешивания их элементов)
    /// \param a (первая скрещиваемая особь)
    /// \param b (вторая скрещиваемая особь)
    void crossover(const Individual &a, const Individual &b);

    /// Формирование популяции из 128 особей (создание вектора векторов длины 128)
    /// \param a (первый "родитель")
    /// \param b (второй "родитель")
    void createPopulation(const Individual &a, const Individual &b);

    /// Вычисление приспособленности каждой особи популяции (применение целевой функции к каждому вектору из вектора векторов)
    void calcFitness();

    /// Селекция: отбор наиболее приспособленных особей (удаление из конца вектора векторов половины векторов)
    void selection();

    /// Эволюция: создание новых популяций и проведение селекции до решения задачи (...)
    /// \return Количество популяций (итераций), потребовавшихся для решения задачи
    int startEvolution();

private:
    /// Популяция (вектор особей)
    std::vector<Individual> population;

    /// Число итераций алгоритма, то есть поколений
    int iterations = 0;
};