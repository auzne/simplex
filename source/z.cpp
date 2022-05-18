#include "z.h"
#include <cmath>
#include <iostream>
#include <vector>

std::vector<double> getZ() {
    int total_x{0};
    std::vector<double> z_vector{};
    std::cout << "Informe os valores z" << '\n'
              << "Para parar, insira um valor igual ou menor a 0" << '\n';

    double z_x;
    do {
        z_x = getXValueZ(total_x);
        if (z_x != 0) {
            z_vector.push_back(z_x);
            ++total_x;
        }
    } while (z_x != 0 || total_x == 0);

    return z_vector;
}

double getXValueZ(int total_x) {
    std::cout << "Insira o x" << (total_x + 1) << " de z: ";
    double x{};
    std::cin >> x;
    // asks for x, stops when x=0 and more than one x's have been informed
    if (x == 0 && total_x < 1) {
        std::cout << "É necessário pelo menos um x em z" << '\n';
    }
    return x;
}

bool hasOnlyPositives(std::vector<double> &z_vector) {
    for (int i{0}; i < z_vector.size(); ++i) {
        if (z_vector.at(i) < 0.0)
            return false;
    }
    return true;
}

bool hasOnlyNegatives(std::vector<double> &z_vector) {
    for (int i{0}; i < z_vector.size(); ++i) {
        if (z_vector.at(i) > 0.0)
            return false;
    }
    return true;
}

std::vector<double> zToRow(std::vector<double> &z_vector, int total_constr, int max_or_min) {
    // z have first value 1 (column z)
    std::vector<double> row{1};
    // xn column
    for (int i{0}; i < z_vector.size(); ++i) {
        if (max_or_min == 1)
            // maximize multiply by -1 once
            row.push_back(z_vector.at(i) * -1.0);
        else
            // minimize multiply twice by -1, and -1^2 = 1
            row.push_back(z_vector.at(i));
    }
    // fn column
    for (int i{0}; i < total_constr; ++i)
        row.push_back(0.0);
    // b column
    row.push_back(0.0);

    return row;
}

void zPerfectSolution(std::vector<double> &z_vector, bool is_minimize) {
    if (!is_minimize)
        std::cout << '\n' << "z possui somente valores x negativos" << '\n';
    else
        std::cout << '\n' << "Não é possível minimizar quando todos os valores x são positivos na fórmula atual"
                  << '\n';
    printZ(z_vector, -1);
}

void printZ(std::vector<double> &z_vector, int max_or_min) {
    if (max_or_min == 1)
        std::cout << "(max) ";
    else if (max_or_min == 2)
        std::cout << "(min) ";
    std::cout << "z =";
    for (int i{0}; i < z_vector.size(); ++i) {
        double xn{z_vector.at(i)};
        std::cout << ' ';
        if (xn >= 0 && i > 0)
            std::cout << "+ ";
        else if (xn < 0) {
            std::cout << '-';
            if (i > 0)
                std::cout << ' ';
        }
        std::cout << std::abs(xn) << 'x' << (i + 1);
    }
    std::cout << '\n';
}
