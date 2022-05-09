#ifndef SIMPLEX_SOLUTION_H
#define SIMPLEX_SOLUTION_H

#include <vector>

int isPerfectSolution(std::vector<double> &first_row);

std::vector<int> isBasicVariable(std::vector<double> &column, int column_index);

std::vector<double> columnToRow(std::vector<std::vector<double>> &table, int column_index);

void printSolution(std::vector<std::vector<double>> &table, int total_x, bool perfect_solution);

void printBasics(std::vector<std::vector<double>> &table, std::vector<std::vector<int>> basics, int total_x);

void printNonBasics(std::vector<std::vector<int>> non_basics, int total_x);

#endif //SIMPLEX_SOLUTION_H
