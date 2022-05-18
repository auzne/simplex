#include "solution.h"
#include "utils.h"
#include <iostream>
#include <vector>

int isPerfectSolution(std::vector<double> &first_row) {
    // return first negative number occurrence
    // -1 is a perfect solution
    for (int i{1}; i < (first_row.size() - 1); ++i) {
        if (first_row.at(i) < 0.0)
            return i;
    }
    return -1;
}

std::vector<int> isBasicVariable(std::vector<double> &column, int column_index) {
    // a basic variable consists of only a single 1 and 0s
    int ones{0};
    int one_index{-1};
    for (int i{0}; i < column.size(); ++i) {
        if (approximatelyEqualAbsRel(column.at(i), 1.0, 1e-8, 1e-4)) {
            ++ones;
            one_index = i;
        } else if (approximatelyEqualAbsRel(column.at(i), 0.0, 1e-8, 1e-4))
            continue;
        else
            // when value differs from 0 and 1
            return {-1, column_index};
    }
    if (ones == 1)
        return {one_index, column_index};
    return {-1, column_index};
}

std::vector<double> columnToRow(std::vector<std::vector<double>> &table, int column_index) {
    std::vector<double> column{};
    for (int i{0}; i < table.size(); ++i)
        column.push_back(table.at(i).at(column_index));

    return column;
}

void printSolution(std::vector<std::vector<double>> &table, int total_x, bool perfect_solution, int loop_count) {
    std::vector<std::vector<int>> basics{};
    std::vector<std::vector<int>> non_basics{};
    // B column can not be a basic variable
    for (int i{1}; i < (table.at(0).size() - 1); ++i) {
        std::vector<double> column{columnToRow(table, i)};
        std::vector<int> variable{isBasicVariable(column, i)};
        if (variable.at(0) > -1)
            basics.push_back(variable);
        else
            non_basics.push_back(variable);
    }
    std::cout << '\n' << "Solução";
    if (!perfect_solution)
        std::cout << " não";
    std::cout << " ótima (em " << loop_count << " iterações)" << '\n';

    printBasics(table, basics, total_x);
    printNonBasics(non_basics, total_x);
    std::cout << "Valor de z: " << table.at(0).at(table.at(0).size() - 1) << '\n';
}

void printBasics(std::vector<std::vector<double>> &table, std::vector<std::vector<int>> basics, int total_x) {
    std::cout << "Variáveis básicas:";
    for (int i{0}; i < basics.size(); ++i) {
        char column_name;
        int column_number;
        int basic_variable_column{basics.at(i).at(1)};
        if (basic_variable_column > 0 && basic_variable_column < (1 + total_x)) {
            column_name = 'x';
            column_number = basic_variable_column;
        } else {
            column_name = 'f';
            column_number = basic_variable_column - total_x;
        }
        double variable_value{table.at(basics.at(i).at(0)).at(table.at(0).size() - 1)};
        std::cout << " " << column_name << column_number << "="
                  << variable_value;
        if (i != (basics.size() - 1))
            std::cout << ',';
    }
    std::cout << '\n';
}

void printNonBasics(std::vector<std::vector<int>> non_basics, int total_x) {
    std::cout << "Variáveis não básicas:";
    for (int i{0}; i < non_basics.size(); ++i) {
        char column_name;
        int column_number;
        int basic_variable_column{non_basics.at(i).at(1)};
        if (basic_variable_column > 0 && basic_variable_column < (1 + total_x)) {
            column_name = 'x';
            column_number = basic_variable_column;
        } else {
            column_name = 'f';
            column_number = basic_variable_column - total_x;
        }
        std::cout << " " << column_name << column_number << "=0";
        if (i != (non_basics.size() - 1))
            std::cout << ',';
    }
    std::cout << '\n';
}
