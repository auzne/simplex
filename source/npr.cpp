#include "npr.h"
#include <vector>

std::vector<double> findNewPivotRow(const std::vector<double> &pivot_row, int pivot_column_index) {
    double pivot{pivot_row.at(pivot_column_index)};
    std::vector<double> npr{};
    for (int i{0}; i < pivot_row.size(); ++i)
        // divide all pivot row by pivot, to make pivot equal one
        npr.push_back(pivot_row.at(i) / pivot);

    return npr;
}

std::vector<double> findNewRow(const std::vector<double> &row, const std::vector<double> &npr, int pivot_column_index) {
    double pivot_column{row.at(pivot_column_index)};
    std::vector<double> npr_multiplied{multiplyNPR(npr, pivot_column)};
    std::vector<double> new_row{};
    for (int i{0}; i < row.size(); ++i)
        new_row.push_back(row.at(i) + npr_multiplied.at(i));

    return new_row;
}

std::vector<double> multiplyNPR(const std::vector<double> &npr, double pivot_column) {
    std::vector<double> npr_multiplied{};
    for (int i{0}; i < npr.size(); ++i)
        npr_multiplied.push_back(npr.at(i) * (pivot_column * -1.0));

    return npr_multiplied;
}
