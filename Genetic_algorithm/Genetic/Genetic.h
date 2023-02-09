//
// Created by Филипп Евдокимов on 14.12.2022.
//

#pragma once

#include <vector>

class Individual {
    friend class Genetic;

private:
    std::vector<int> individual;

    /// Перегрузка оператора [] для класса Individual (для нахождения элемента особи по его индексу в произвольном случае)
    /// \param i (индекс искомого элемента)
    /// \return Элемент особи с индексом i
    int& operator [] (int i) {
        return individual[i];
    }

    /// Перегрузка оператора [] для класса Individual (для нахождения элемента особи по его индексу в константном случае)
    /// \param i (индекс искомого элемента)
    /// \return Элемент особи с индексом i
    const int& operator [] (int i) const {
        return individual[i];
    }

    /// Перегрузка оператора < для класса Individual (для сравнения особей)
    /// \param ind_2 (вторая сравниваемая особь)
    /// \return true, если меньше, иначе false
    bool operator < (const Individual& ind_2) const {
        return (individual[4] < ind_2.individual[4]);
    }

public:
    /// Приспособленность особи, то есть целевая функция (может быть любой): f(x,y,z,w) = |(x + 11 * y + 111 * z + 1111 * w) / 100|
    /// \return Приспособленность особи
    inline int fitness();

    /// Мутация: случайное изменение генома особи (прибавление случайного числа к случайному элементу вектора)
    void mutation();

    /// Печать особи (вектора из пяти элементов)
    inline void print_individual();

    /// Создание особи (формирование вектора из пяти элементов из данного шестизначного числа)
    /// \param n (фиксированное шестизначное число)
    explicit Individual(int n) {
        int a1 = n / 10000;
        int a2 = (n / 100) % 100;
        int a3 = n % 100;
        individual = {(a1 + a2 + a3), a1, a2, a3, 1};
//        cout << individual[0] << " " << individual[1] << " " << individual[2] << " " << individual[3] << " " << individual[4] << endl;
    }

    /// Создание особи (формирование вектора из пяти элементов из пяти данных числел)
    /// \param n0 (фиксированное целое число)
    /// \param n1 (фиксированное целое число)
    /// \param n2 (фиксированное целое число)
    /// \param n3 (фиксированное целое число)
    /// \param n4 (фиксированное целое число)
    Individual(int n0, int n1, int n2, int n3, int n4) {
        individual = {n0, n1, n2, n3, n4};
    }
};

class Genetic {
private:
    std::vector<Individual> population;
    int iterations = 0;

public:
    /// Кроссинговер: скрещивание двух особей (получение 8 векторов из 2 путём перемешивания их элементов)
    /// \param a (первая скрещиваемая особь)
    /// \param b (вторая скрещиваемая особь)
    void crossover(const Individual &a, const Individual &b);

    /// Формирование популяции из 128 особей (создание вектора векторов длины 128)
    /// \param a (первый "родитель")
    /// \param b (второй "родитель")
    void create_population(const Individual &a, const Individual &b);

    /// Вычисление приспособленности каждой особи популяции (применение целевой функции к каждому вектору из вектора векторов)
    void calc_fitness();

    /// Селекция: отбор наиболее приспособленных особей (удаление из конца вектора векторов половины векторов)
    void selection();

    /// Эволюция: создание новых популяций и проведение селекции до решения задачи (...)
    /// \return Количество популяций (итераций), потребовавшихся для решения задачи
    int evolution();

    /// Запуск эволюции
    /// \return Эволюция
    int Start() {
        return evolution();
    }

    /// Конструктор класса Genetic: формирование популяции из двух "родительских" особей, заданных фиксированными шестизначными числами
    /// \param n1 (фиксированное шестизначное число)
    /// \param n2 (фиксированное шестизначное число)
    Genetic(int n1, int n2) {
        Individual a (n1);
        Individual b (n2);
        create_population(a, b);
    }
};