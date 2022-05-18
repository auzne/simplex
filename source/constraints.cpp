#include "constraints.h"
#include <cmath>
#include <iostream>
#include <vector>

int getNumberOfConstraints() {
    std::cout << "Informe a quantidade de restrições: ";
    int total{};
    std::cin >> total;

    if (total < 1)
        return getNumberOfConstraints();
    std::cout << '\n';
    return total;
}

void printConstraints(std::vector<std::vector<double>> &table, std::vector<int> max_or_min, int total_x) {
    for (int i{1}; i < table.size(); ++i) {
        printConstr(table.at(i), total_x, max_or_min.at(i));
    }
    printLastConstr(total_x);
    std::cout << '\n';
}

void printConstr(std::vector<double> &constr, int total_x, int max_or_min) {
    // print constraint
    std::cout << "\t{";
    for (int i{1}; i <= total_x; ++i) {
        double xn{constr.at(i)};
        if (xn != 0.0) {
            std::cout << ' ';
            if (xn >= 0 && i > 1)
                std::cout << "+ ";
            else if (xn < 0) {
                std::cout << '-';
                if (i > 0)
                    std::cout << ' ';
            }
            std::cout << std::abs(xn) << 'x' << i;
        }
    }
    // maximize or minimize operator
    if (max_or_min == 1)
        std::cout << " <= ";
    else if (max_or_min == 2)
        std::cout << " >= ";
    else
        std::cout << " = ";
    // result (b column)
    std::cout << constr.at(constr.size() - 1);
    std::cout << '\n';
}

void printLastConstr(int total_x) {
    std::cout << "\t{ ";
    for (int i{1}; i <= total_x; ++i) {
        std::cout << 'x' << i;
        if (i < total_x)
            std::cout << ", ";
    }
    std::cout << " >= 0";
    std::cout << '\n';
}
