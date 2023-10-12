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
    a.populate_grid(grid_base_, 5, 5);
    a.solve();

    // print the solution
    std::cout << "Solution: " << std::endl;
    for (auto & i : a.solution_nodes) {
        std::cout << i->to_string() << std::endl;
    }


    std::cout << std::endl << "Visualizing the solution: " << std::endl;
    // iterate through the grid
    for (int i = 0; i < a.g.height; i++) {
        for (int j = 0; j < a.g.width; j++) {
            // get the node
            node* n = a.g.get_node(location(j, i, false));

            // check if the node is in the solution
            bool in_solution = false;
            for (auto & k : a.solution_nodes) {
                if (k == n) {
                    in_solution = true;
                    break;
                }
            }

            // print the node state as integers
            if (in_solution && n->get_state() != 2 && n->get_state() != 3) {
                std::cout << 4 << " ";
            } else {
                std::cout << n->get_state() << " ";
            }

        }
        std::cout << std::endl;
    }

    return 0;
}
