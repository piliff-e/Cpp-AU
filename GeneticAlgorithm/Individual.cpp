//
// Created by Филипп Евдокимов on 15.02.2023.
//

#include "Individual.h"
#include "Randoms.h"

namespace {
constexpr std::size_t defaultIndividualSize = 5;
constexpr std::size_t defaultRating = 1;

constexpr std::size_t nothingToDoScenario = 0;
constexpr std::size_t addToFirstScenario = 1;
constexpr std::size_t addToSecondScenario = 2;
constexpr std::size_t addToThirdScenario = 3;
constexpr std::size_t addToTwoScenario = 4;
constexpr std::size_t addToThreeScenario = 5;

constexpr std::int32_t minDecrease = -100;
constexpr std::size_t maxIncrease = 100;

constexpr std::int32_t firstMultiplier = 1;
constexpr std::int32_t secondMultiplier = 11;
constexpr std::int32_t thirdMultiplier = 111;
constexpr std::int32_t fourthMultiplier = 1111;
constexpr std::int32_t divider = 100;
}

/// Создание особи (формирование вектора из пяти элементов из данного шестизначного числа)
Individual::Individual(int n) : individual(defaultIndividualSize) {
    int a1 = n / 10000;  /// Первые две цифры n
    int a2 = (n / 100) % 100;  /// Центральные две цифры n
    int a3 = n % 100;  /// Последние две цифры n
    individual[0] = a1 + a2 + a3;
    individual[1] = a1;
    individual[2] = a2;
    individual[3] = a3;
    individual[4] = defaultRating;
}

/// Создание особи (формирование вектора из пяти элементов из пяти данных числел)
Individual::Individual(int n0, int n1, int n2, int n3, int n4) : individual(defaultIndividualSize) {
    individual[0] = n0;
    individual[1] = n1;
    individual[2] = n2;
    individual[3] = n3;
    individual[4] = n4;
}

/// Приспособленность особи, то есть целевая функция (может быть любой): f(x,y,z,w) = |(x + 11 * y + 111 * z + 1111 * w) / 100|
int Individual::fitness() {
    return abs((firstMultiplier * individual[0] + secondMultiplier * individual[1] + thirdMultiplier * individual[2] +
        fourthMultiplier * individual[3]) / divider);
}

/// Мутация: случайное изменение генома особи (прибавление случайного числа к случайному элементу вектора)
void Individual::mutation() {
    Randoms scenarios = {0, 5};
    int scenario = scenarios.randomNumber();
    if (scenario == nothingToDoScenario) {
    } else if (scenario == addToFirstScenario || scenario == addToSecondScenario || scenario == addToThirdScenario) {
        Randoms range = {minDecrease, maxIncrease};
        individual[scenario] += range.randomNumber();
    } else if (scenario == addToTwoScenario) {
        Randoms indexes = {1, 3};
        std::pair<int, int> randomIndexes = indexes.twoRandomNumbers();
        Randoms range = {minDecrease, maxIncrease};
        individual[randomIndexes.first] += range.randomNumber();
        individual[randomIndexes.second] += range.randomNumber();
    } else if (scenario == addToThreeScenario) {
        Randoms range = {minDecrease, maxIncrease};
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