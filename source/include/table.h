#ifndef SIMPLEX_TABLE_H
#define SIMPLEX_TABLE_H

#include <vector>

void addRows(std::vector<std::vector<double>> &table, std::vector<int> &max_or_min, int total_x, int total_constr);

std::vector<double> getRow(std::vector<int> &max_or_min, int total_x, int total_constr, int current_row);

double getXValue(int current_row, int current_x);

double getFValue(int current_f, int current_row, int max_or_min);

double getBValue(int current_row);

void maximizeAllRows(std::vector<std::vector<double>> &table, std::vector<int> &max_or_min);

std::vector<double> multiplyByMinusOne(const std::vector<double> &row);

void updateRowsWithNPR(std::vector<std::vector<double>> &table, int pivot_row_index, int pivot_column_index);

void printTable(const std::vector<std::vector<double>> &table, int total_x, int total_constr);

#endif //SIMPLEX_TABLE_H
