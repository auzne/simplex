#include "pivot.h"
#include <cmath>
#include <vector>

std::vector<int> findPivot(std::vector<std::vector<double>> &table, int total_x, int forced_pivot_column) {
    int pivot_column{forced_pivot_column};
    if (forced_pivot_column == -1)
        pivot_column = findPivotColumn(table.at(0), total_x);
    int pivot_row{findPivotRow(table, pivot_column)};
    // pivot indexes in table
    std::vector<int> pivot{pivot_row, pivot_column};

    return pivot;
}

int findPivotColumn(std::vector<double> &first_row, int total_x) {
    // greater number and it's index in the vector
    double greater_abs{0};
    int greater_index{1};
    // look for greater numbers
    for (int i{1}; i <= total_x; ++i) {
        if (std::fabs(first_row.at(i)) > greater_abs) {
            greater_abs = std::fabs(first_row.at(i));
            greater_index = i;
        }
    }
    return greater_index;
}

int findPivotRow(std::vector<std::vector<double>> &table, int column_index) {
    double smaller_value{0};
    int smaller_index{0};
    for (int i{1}; i < table.size(); ++i) {
        double value{table.at(i).at(column_index)};
        double b{table.at(i).at(table.at(0).size() - 1)};
        if (value > 0.0 || value < 0.0) {
            double division{b / value};
            if (division < smaller_value || smaller_value == 0.0) {
                smaller_value = division;
                smaller_index = i;
            }
        }
    }
    return smaller_index;
}
