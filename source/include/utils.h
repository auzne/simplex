#ifndef SIMPLEX_UTILS_H
#define SIMPLEX_UTILS_H

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);

int maximizeOrMinimize(int row, int z_max_or_min);

int continueLooping(int loop_count);

void clearTerminal();

#endif //SIMPLEX_UTILS_H
