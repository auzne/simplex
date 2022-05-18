#include "constraints.h"
#include "npr.h"
#include "pivot.h"
#include "solution.h"
#include "table.h"
#include "utils.h"
#include "z.h"
#include <cstdlib>
#include <vector>

int main() {
    bool perfect_solution{false};
    // get z function
    std::vector<double> z_vector{getZ()};
    // z having all x's negatives is already a perfect solution
    if (hasOnlyNegatives(z_vector)) {
        zPerfectSolution(z_vector, false);
        return 0;
    }
    // number of x's
    int total_x{static_cast<int>(z_vector.size())};
    // stores info about "maximize or minimize" for each row
    std::vector<int> max_or_min{maximizeOrMinimize(-1, -1)};
    // not possible to minimize when all values are positive with current formula
    if (max_or_min.at(0) == 2) {
        if (hasOnlyPositives(z_vector)) {
            zPerfectSolution(z_vector, true);
            return 0;
        }
    }
    // number of constraints
    int total_constr{getNumberOfConstraints()};
    // create table vector, where all rows will be
    std::vector<std::vector<double>> table{{zToRow(z_vector, total_constr, max_or_min.at(0))}};
    // add rows to the table
    addRows(table, max_or_min, total_x, total_constr);

    // creates a copy of the table
    std::vector<std::vector<double>> initial_table{table};

    // multiply rows with max_or_min == 2 by -1
    maximizeAllRows(table, max_or_min);

    // only used after first while
    int forced_pivot_column{-1};
    // number of iterations
    int loop_count{1};
    // in the 10th loop, will ask if the user wants to break the loop
    int ask_to_stop{10};
    // loops until a perfect solution is found
    while (!perfect_solution) {
        // find pivot (row, column)
        std::vector<int> pivot_index{findPivot(table, total_x, forced_pivot_column)};
        // pivot not found (all b/value results are either zero or negative - invalid)
        if (pivot_index.at(0) == -1)
            break;
        // find new pivot row and replace in the table
        table.at(pivot_index.at(0)) = findNewPivotRow(table.at(pivot_index.at(0)), pivot_index.at(1));
        // update table with new rows calculated using npr
        updateRowsWithNPR(table, pivot_index.at(0), pivot_index.at(1));
        // check for perfect solution
        int first_negative_index{isPerfectSolution(table.at(0))};
        // when first_negative_index equals -1, there is no negative numbers in the first row
        // resulting in a perfect solution
        if (first_negative_index == -1) {
            perfect_solution = true;
        } else {
            // the user may ask the loop to stop
            if (loop_count == ask_to_stop) {
                int option{continueLooping(loop_count)};
                if (option == 1) {
                    // doubles the iterations needed
                    ask_to_stop *= 2;
                } else if (option == 2) {
                    // will ask in the next 1000th iteration
                    ask_to_stop = (((ask_to_stop / 1000) + 1) * 1000);
                } else if (option == 3) {
                    // simply stops looping
                    break;
                }
            }
            forced_pivot_column = first_negative_index;
            ++loop_count;
        }
    }
    // clear terminal for better visualization
    clearTerminal();
    // print z
    printZ(z_vector, max_or_min.at(0));
    // print the constraints
    printConstraints(initial_table, max_or_min, total_x);
    // print table
    printTable(table, total_x, total_constr);
    // print solution (basic and non-basic variables and z value)
    printSolution(table, total_x, perfect_solution, loop_count);

    return 0;
}
