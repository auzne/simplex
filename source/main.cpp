#include "npr.h"
#include "pivot.h"
#include "questions.h"
#include "table.h"
#include "solution.h"
#include "z.h"
#include <vector>

int main() {
    bool perfect_solution{false};
    // get z function
    std::vector<double> z_vector{getZ()};
    // z having all x's negatives is already a perfect solution
    if (hasOnlyNegatives(z_vector)) {
        zPerfectSolution(z_vector);
        return 0;
    }
    // number of x's
    int total_x{static_cast<int>(z_vector.size())};
    // maximize or minimize z function
    int max_or_min{maximizeOrMinimize()};
    // number of constraints
    int total_constr{getNumberOfConstraints()};
    // create table vector, where all rows will be
    std::vector<std::vector<double>> table{{zToRow(z_vector, total_constr)}};
    // add rows to the table
    addRows(table, total_x, total_constr, max_or_min);

    // only used after first while
    int forced_pivot_column{-1};
    // loops until a perfect solution is found
    while (!perfect_solution) {
        // find pivot (row, column)
        std::vector<int> pivot_index{findPivot(table, total_x, forced_pivot_column)};
        // find new pivot row and replace in the table
        table.at(pivot_index.at(0)) = findNewPivotRow(table.at(pivot_index.at(0)), pivot_index.at(1));
        // update table with new rows calculated using npr
        updateRowsWithNPR(table, pivot_index.at(0), pivot_index.at(1));
        // check for perfect solution
        int first_negative_index{isPerfectSolution(table.at(0))};
        // when first_negative_index equals -1, there is no negative numbers in the first row
        // resulting in a perfect solution
        if (first_negative_index == -1)
            perfect_solution = true;
        else
            forced_pivot_column = first_negative_index;
    }
    // print table
    printTable(table, total_x, total_constr);
    // print solution (basic and non-basic variables and z value)
    printSolution(table, total_x);

    return 0;
}
