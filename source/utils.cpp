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

int maximizeOrMinimize(char row, int z_max_or_min) {
    if (row == 'z') {
        std::cout << "Selecione o que deseja fazer com a função z" << '\n'
                  << "1) Maximizar" << '\n'
                  << "2) Minimizar" << '\n';
    } else {
        std::cout << "O resultado da L" << static_cast<int>(row) << "é" << '\n';
        std::cout << "1) Menor ou igual (<=)" << '\n'
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
        if (row != 'z')
            std::cout << '\n';
        if (!(row == 'z' && max_or_min == 3))
            return max_or_min;
    }
    return maximizeOrMinimize(row, z_max_or_min);
}
