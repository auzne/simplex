#ifndef SIMPLEX_NPR_H
#define SIMPLEX_NPR_H

#include <vector>

std::vector<double> findNewPivotRow(const std::vector<double> &pivot_row, int pivot_column_index);

std::vector<double> findNewRow(const std::vector<double> &row, const std::vector<double> &npr, int pivot_column_index);

std::vector<double> multiplyNPR(const std::vector<double> &npr, double pivot_column);

#endif //SIMPLEX_NPR_H
