#ifndef SIMPLEX_PIVOT_H
#define SIMPLEX_PIVOT_H

#include <vector>

std::vector<int> findPivot(const std::vector<std::vector<double>> &table, int total_x, int forced_pivot_column);

int findPivotColumn(const std::vector<double> &first_row, int total_x);

int findPivotRow(const std::vector<std::vector<double>> &table, int column_index);

#endif //SIMPLEX_PIVOT_H
