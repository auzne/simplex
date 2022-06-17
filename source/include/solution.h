#ifndef SIMPLEX_SOLUTION_H
#define SIMPLEX_SOLUTION_H

#include <vector>

int isPerfectSolution(const std::vector<double> &first_row);

std::vector<int> isBasicVariable(const std::vector<double> &column, int column_index);

std::vector<double> columnToRow(const std::vector<std::vector<double>> &table, int column_index);

void printSolution(const std::vector<std::vector<double>> &table, int total_x, bool perfect_solution, int loop_count);

void printBasics(const std::vector<std::vector<double>> &table, const std::vector<std::vector<int>> &basics, int total_x);

void printNonBasics(const std::vector<std::vector<int>> &non_basics, int total_x);

#endif //SIMPLEX_SOLUTION_H
