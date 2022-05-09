#include "npr.h"
#include "table.h"
#include "utils.h"
#include <iostream>
#include <vector>

void addRows(std::vector<std::vector<double>> &table, std::vector<int> &max_or_min, int total_x, int total_constr) {
    // row 1 (z) is already added
    for (int i{0}; i < total_constr; ++i) {
        table.push_back(getRow(max_or_min, total_x, total_constr, (i + 2)));
    }
}

std::vector<double> getRow(std::vector<int> &max_or_min, int total_x, int total_constr, int current_row) {
    // row vector
    std::vector<double> row{0};
    double b_value;
    int row_max_or_min;

    // x input
    for (int i{0}; i < total_x; ++i)
        row.push_back(getXValue(current_row, (i + 1)));
    // b input
    b_value = getBValue(current_row);
    // maximize or minimize this row
    row_max_or_min = maximizeOrMinimize(static_cast<char>(current_row), max_or_min.at(0));
    // push to max or min array
    max_or_min.push_back(row_max_or_min);
    // f
    for (int i{0}; i < total_constr; ++i)
        row.push_back(getFValue(i, current_row, row_max_or_min));
    // b
    row.push_back(b_value);

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
    double f {0.0};

    if (current_f == (current_row - 2)) {
        if (max_or_min == 1)
            f = 1.0;
        else if (max_or_min == 2)
            f = -1.0;
    }

    return f;
}

double getBValue(int current_row) {
    std::cout << "Informe o resultado da restrição " << (current_row - 1) << ": ";
    double b{};
    std::cin >> b;

    return b;
}

void maximizeAllRows(std::vector<std::vector<double>> &table, std::vector<int> &max_or_min) {
    for (int i{1}; i < max_or_min.size(); ++i) {
        if (max_or_min.at(i) == 2) {
            table.at(i) = multiplyByMinusOne(table.at(i));
            max_or_min.at(i) = 1;
        }
    }
}

std::vector<double> multiplyByMinusOne(std::vector<double> &row) {
    std::vector<double> multiplied_row{row.at(0)};
    // might need to change to `i < row.size() - 1`
    // need to check later
    for (int i{1}; i < row.size(); ++i) {
        if (approximatelyEqualAbsRel(row.at(i), 0.0, 1e-8, 1e-4))
            multiplied_row.push_back(row.at(i));
        else
            multiplied_row.push_back((row.at(i) * (-1.0)));
    }
    return multiplied_row;
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
    std::cout << "\tz";
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
