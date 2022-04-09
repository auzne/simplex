#include "questions.h"
#include <iostream>

int maximizeOrMinimize() {
    std::cout << "Selecione o que deseja fazer com a função z" << '\n'
              << "1) Maximizar" << '\n'
              << "2) Minimizar" << '\n'
              << "Digite um número: ";
    int max_or_min{};
    std::cin >> max_or_min;

    if (max_or_min == 1 || max_or_min == 2)
        return max_or_min;
    return maximizeOrMinimize();
}

int getNumberOfConstraints() {
    std::cout << "Informe a quantidade de restrições: ";
    int total{};
    std::cin >> total;

    if (total < 1)
        return getNumberOfConstraints();
    return total;
}
