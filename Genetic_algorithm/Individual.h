//
// Created by Филипп Евдокимов on 15.02.2023.
//

#pragma once

#include <vector>

class Individual {
private:
    /// Особь
    std::vector<int> individual;

public:
    /// Перегрузка оператора [] для класса Individual (для нахождения элемента особи по его индексу в произвольном случае)
    /// \param i (индекс искомого элемента)
    /// \return Элемент особи с индексом i
    int &operator[](int i) {
        return individual[i];
    }

    /// Перегрузка оператора [] для класса Individual (для нахождения элемента особи по его индексу в константном случае)
    /// \param i (индекс искомого элемента)
    /// \return Элемент особи с индексом i
    const int &operator[](int i) const {
        return individual[i];
    }

    /// Перегрузка оператора < для класса Individual (для сравнения особей)
    /// \param ind_2 (вторая сравниваемая особь)
    /// \return true, если меньше, иначе false
    bool operator<(const Individual &ind_2) const {
        return (individual[4] < ind_2.individual[4]);
    }

    /// Приспособленность особи, то есть целевая функция (может быть любой): f(x,y,z,w) = |(x + 11 * y + 111 * z + 1111 * w) / 100|
    /// \return Приспособленность особи
    int fitness();

    /// Мутация: случайное изменение генома особи (прибавление случайного числа к случайному элементу вектора)
    void mutation();

    /// Печать особи (вектора из пяти элементов)
    inline void printIndividual();

    /// Создание особи (формирование вектора из пяти элементов из данного шестизначного числа)
    /// \param n (фиксированное шестизначное число)
    explicit Individual(int n);

    /// Создание особи (формирование вектора из пяти элементов из пяти данных числел)
    /// \param n0 (фиксированное целое число)
    /// \param n1 (фиксированное целое число)
    /// \param n2 (фиксированное целое число)
    /// \param n3 (фиксированное целое число)
    /// \param n4 (фиксированное целое число)
    Individual(int n0, int n1, int n2, int n3, int n4);
};