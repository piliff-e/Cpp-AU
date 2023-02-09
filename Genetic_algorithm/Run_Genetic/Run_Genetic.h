//
// Created by Филипп Евдокимов on 18.12.2022.
//

#pragma once

class GeneticApplication {
private:
    static int n1, n2;

public:
    /// Ввод с клавиатуры чисел, которые в дальнейшем будут преобразованы в "родительских" особей
    static void input();

    /// Запуск проекта Genetic_algorithm
    /// \return 0 (стандартный вывод)
    static int run();

//    GeneticApplication(int m1, int m2){
//        n1 = m1;
//        n2 = m2;
//    }
};