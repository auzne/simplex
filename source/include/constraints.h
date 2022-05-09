#ifndef SIMPLEX_CONSTRAINTS_H
#define SIMPLEX_CONSTRAINTS_H

#include <vector>

int getNumberOfConstraints();

void printConstraints(std::vector<std::vector<double>> &table, std::vector<int> max_or_min, int total_x);

void printConstr(std::vector<double> &constr, int total_x, int max_or_min);

void printLastConstr(int total_x);

#endif //SIMPLEX_CONSTRAINTS_H
