//
// Created by Филипп Евдокимов on 14.12.2022.
//

#pragma once

#include <vector>
using namespace std;

/// Вспомогательные функции
int random_number(int from, int to); /// Выбор случайного числа из диапазона
pair<int, int> get_random_numbers(int from, int to); /// Выбор двух случайных индексов из вектор

class Individual {
    friend class Genetic;

private:
    vector<int> individual;

    int operator [] (int i) const {
        return individual[i];
    }

    bool operator < (const Individual& ind_2) const {
        return (individual[4] < ind_2.individual[4]);
    }

public:
    int func(); /// Целевая функция (может быть любой)
    void mutation(); /// Мутация (см. Genetic.cpp)
    void print_individual(); /// Печать особи (вектора из пяти элементов)

    explicit Individual(int n) { /// Создание особи (формирование вектора из пяти элементов из данного шестизначного числа)
        int a1 = n / 10000;
        int a2 = (n / 100) % 100;
        int a3 = n % 100;
        individual = {(a1 + a2 + a3), a1, a2, a3, 1};
//        cout << individual[0] << " " << individual[1] << " " << individual[2] << " " << individual[3] << " " << individual[4] << endl;
    }

    Individual(int n0, int n1, int n2, int n3, int n4) { /// Создание особи (формирование вектора из пяти элементов из данного шестизначного числа)
        individual = {n0, n1, n2, n3, n4};
    }
};

class Genetic {
//    friend class Individual;

private:
    vector<Individual> population;
    int iterations = 0;

public:
    void crossover(const Individual &a, const Individual &b); /// Кроссинговер (см. Genetic.cpp)
    void create_population(const Individual &a, const Individual &b); /// Формирование популяции из 128 особей
    void calc_fitness(); /// Вычисление приспособленности каждой особи популяции
    void selection(); /// Селекция
    int evolution(); /// Эволюция (см. Genetic.cpp)

    int Start() {
        return evolution();
    }

    Genetic(int n1, int n2) {
        Individual a (n1);
        Individual b (n2);
        create_population(a, b);
    }
};