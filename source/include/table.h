#ifndef SIMPLEX_TABLE_H
#define SIMPLEX_TABLE_H

#include <vector>

void addRows(std::vector<std::vector<double>> &table, int total_x, int total_constr, int max_or_min);

std::vector<double> getRow(int total_x, int total_constr, int max_or_min, int current_row);

double getXValue(int current_row, int current_x);

double getFValue(int current_f, int current_row, int max_or_min);

double getBValue(int current_row);

void updateRowsWithNPR(std::vector<std::vector<double>> &table, int pivot_row_index, int pivot_column_index);

void printTable(std::vector<std::vector<double>> &table, int total_x, int total_constr);

#endif //SIMPLEX_TABLE_H
