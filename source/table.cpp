#include "table.h"
#include "npr.h"
#include <iostream>
#include <vector>

void addRows(std::vector<std::vector<double>> &table, int total_x, int total_constr, int max_or_min) {
    // row 1 (z) is already added
    for (int i{0}; i < total_constr; ++i) {
        table.push_back(getRow(total_x, total_constr, max_or_min, (i + 2)));
    }
}

std::vector<double> getRow(int total_x, int total_constr, int max_or_min, int current_row) {
    // row vector
    std::vector<double> row{0};

    // x input
    for (int i{0}; i < total_x; ++i)
        row.push_back(getXValue(current_row, (i + 1)));
    // f
    for (int i{0}; i < total_constr; ++i)
        row.push_back(getFValue(i, current_row, max_or_min));
    // b input
    row.push_back(getBValue(current_row));

    return row;
}

double getXValue(int current_row, int current_x) {
    // asks for x (x can be equal to 0)
    std::cout << "Insira o x" << current_x << " da restrição " << (current_row - 1) << ": ";
    double x{};
    std::cin >> x;

    return x;
}

double getFValue(int current_f, int current_row, int max_or_min) {
    double f;
    if (current_f == (current_row - 2)) {
        if (max_or_min == 1)
            f = 1.0;
        else
            f = -1.0;
    } else
        f = 0.0;

    return f;
}

double getBValue(int current_row) {
    std::cout << "Informe o resultado da restrição " << (current_row - 1) << ": ";
    double b{};
    std::cin >> b;

    return b;
}

void updateRowsWithNPR(std::vector<std::vector<double>> &table, int pivot_row_index, int pivot_column_index) {
    for (int i{0}; i < table.size(); ++i) {
        if (i == pivot_row_index)
            continue;
        table.at(i) = findNewRow(table.at(i), table.at(pivot_row_index), pivot_column_index);
    }
}

void printTable(std::vector<std::vector<double>> &table, int total_x, int total_constr) {
    // z column
    std::cout << "\n\tz";
    // x column
    for (int i{0}; i < total_x; ++i)
        std::cout << "\tx" << (i + 1);
    // fn column
    for (int i{0}; i < total_constr; ++i)
        std::cout << "\tf" << (i + 1);
    // b column
    std::cout << "\tB" << '\n';
    // rows and values
    for (int i{0}; i < table.size(); ++i) {
        std::cout << "L" << (i + 1);
        for (int j{0}; j < table.at(i).size(); ++j)
            std::cout << '\t' << table.at(i).at(j);
        std::cout << '\n';
    }
}
