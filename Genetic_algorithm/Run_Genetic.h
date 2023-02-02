//
// Created by Филипп Евдокимов on 18.12.2022.
//

#pragma once

#include <iostream>
#include "Genetic.h"

class GeneticApplication {
public:
    static int run() {
        srand(time(nullptr));
        int n1, n2;
        cout << "Choose two six-digit numbers:\n" << "\t1) ";
        cin >> n1;
        cout << "\t2) ";
        cin >> n2;
        cout << endl;
        Genetic evol(n1,n2);
        cout << evol.Start() << " iterations" << endl;
        return 0;
    }
};