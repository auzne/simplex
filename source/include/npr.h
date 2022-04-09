#ifndef SIMPLEX_NPR_H
#define SIMPLEX_NPR_H

#include <vector>

std::vector<double> findNewPivotRow(std::vector<double> &pivot_row, int pivot_column_index);

std::vector<double> findNewRow(std::vector<double> &row, std::vector<double> &npr, int pivot_column_index);

std::vector<double> multiplyNPR(std::vector<double> &npr, double pivot_column);

#endif //SIMPLEX_NPR_H
