#ifndef SIMPLEX_Z_H
#define SIMPLEX_Z_H

#include <vector>

std::vector<double> getZ();

double getXValueZ(int total_x);

bool hasOnlyPositives(const std::vector<double> &z_vector);

bool hasOnlyNegatives(const std::vector<double> &z_vector);

std::vector<double> zToRow(const std::vector<double> &z_vector, int total_constr, int max_or_min);

void zPerfectSolution(const std::vector<double> &z_vector, bool is_minimize);

void printZ(const std::vector<double> &z_vector, int max_or_min);

#endif //SIMPLEX_Z_H
