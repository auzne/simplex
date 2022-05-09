#ifndef SIMPLEX_Z_H
#define SIMPLEX_Z_H

#include <vector>

std::vector<double> getZ();

double getXValueZ(int total_x);

bool hasOnlyNegatives(std::vector<double> &z_vector);

std::vector<double> zToRow(std::vector<double> &z_vector, int total_constr);

void zPerfectSolution(std::vector<double> &z_vector);

void printZ(std::vector<double> &z_vector, int max_or_min);

#endif //SIMPLEX_Z_H
