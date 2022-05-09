#ifndef SIMPLEX_UTILS_H
#define SIMPLEX_UTILS_H

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);

int maximizeOrMinimize(char row, int z_max_or_min);

#endif //SIMPLEX_UTILS_H
