//
// Created by Филипп Евдокимов on 22.02.2023.
//

#pragma once

#include <iostream>

class Randoms {
public:
    /// Конструктор класса Randoms
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    Randoms(int n1, int n2);

    /// Выбор случайного числа из заданного диапазона
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    /// \return Случайное число из диапазона от from до to
    int randomNumber();

    /// Выбор двух случайных индексов из вектора в заданном диапазоне
    /// \param from (начало диапазона)
    /// \param to (конец диапазона)
    /// \return Два случайных числа из диапазона от from до to
    std::pair<int, int> twoRandomNumbers();

private:
    /// Начало диапазона, из которого выбирается случайное число
    int from;

    /// Конец диапазона, из которого выбирается случайное число
    int to;

    /// Вспомогательный класс для вызова srand перед функцией main
    class Randomizer {
    public:
        Randomizer() { srand(time(nullptr)); }

        static Randomizer r;
    };
};