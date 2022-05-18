#include "utils.h"
#include <algorithm>
#include <cmath>
#include <iostream>

// https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{std::abs(a - b)};
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int maximizeOrMinimize(int row, int z_max_or_min) {
    // -1 is z row
    if (row == -1) {
        std::cout << "Selecione o que deseja fazer com a função z" << '\n'
                  << "1) Maximizar" << '\n'
                  << "2) Minimizar" << '\n';
    } else {
        std::cout << "O resultado da L" << row << " é" << '\n'
                  << "1) Menor ou igual (<=)" << '\n'
                  << "2) Maior ou igual (>=)" << '\n'
                  << "3) Igual (=)" << '\n';
    }
    std::cout << "Digite um número";
    if (z_max_or_min == 1 || z_max_or_min == 2)
        std::cout << " (padrão: " << z_max_or_min << ")";
    std::cout << ": ";

    int max_or_min{};
    std::cin >> max_or_min;

    if (max_or_min == 1 || max_or_min == 2 || max_or_min == 3) {
        if (row != -1)
            std::cout << '\n';
        if (!(row == -1 && max_or_min == 3))
            return max_or_min;
    }
    return maximizeOrMinimize(row, z_max_or_min);
}

int continueLooping(int loop_count) {
    clearTerminal();
    std::cout << "Já foram feitas " << loop_count << " para encontrar a solução perfeita." << '\n'
              << "Pode existir algum erro de aproximação." << '\n'
              << "1) Perguntar novamente em " << loop_count << " iterações" << '\n'
              << "2) Não perguntar novamente até a próxima milésima iteração (1000, 2000...)" << '\n'
              << "3) Finalizar e mostrar a solução não perfeita" << '\n'
              << "Digite um número: ";
    int option{};
    std::cin >> option;

    switch (option) {
        case 1:
        case 2:
        case 3:
            return option;
        default:
            return continueLooping(loop_count);
    }
}

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
