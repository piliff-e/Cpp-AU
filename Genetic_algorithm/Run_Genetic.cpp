//
// Created by Филипп Евдокимов on 04.02.2023.
//
#include "Run_Genetic.h"
#include "Genetic.h"
#include <iostream>

int GeneticApplication::run() {
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