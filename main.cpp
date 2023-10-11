#include <iostream>

// include the location class
#include "classes/datatypes/location.h"
#include "classes/node.h"
#include "classes/grid.h"
#include "classes/utils.h"

int main() {
    // Sample grid
    int grid_base[5][5] = {
            {2, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 3}
    };

    location start(0, 0, false);
    location end(4, 4, false);

    // convert the grid to an int**
    int** grid_base_intstarstar = utils::createDynamicArray(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            grid_base_intstarstar[i][j] = grid_base[i][j];
        }
    }

    // Create the grid
    grid g(grid_base_intstarstar, 5, 5);




    return 0;
}
