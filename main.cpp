#include <iostream>

// include the location class
#include "classes/datatypes/location.h"
#include "classes/node.h"
#include "classes/grid.h"
#include "classes/utils.h"
#include "classes/algorithm.h"

int main() {
    // Sample grid
    int grid_base[5][5] = {
            {2, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 3}
    };

    // We will solve this grid using the A* algorithm(That I totally didn't use copilot for)

    // Convert the grid_base to a grid in int**
    int** grid_base_ = utils::createDynamicArray(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            grid_base_[i][j] = grid_base[i][j];
        }
    }

    // Create the algorithm object
    algorithm a(true, true);
    a.populate_grid(grid_base_);
    a.solve();

    return 0;
}
