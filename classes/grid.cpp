//
// Created by satyamedh on 11/10/23.
//

#include "grid.h"

// Constructor
grid::grid(location start, location end, state** grid_base){
    this->start = start;
    this->end = end;
    this->grid_base = grid_base;
    this->real_grid = create_grid(grid_base);
}


// Functions
node **grid::create_grid(state **) {
    // Create a new 2D array of nodes

    int GRID_SIZE_X = sizeof(grid_base) / sizeof(grid_base[0]);
    int GRID_SIZE_Y = sizeof(grid_base[0]) / sizeof(grid_base[0][0]);

    node** grid = new node*[GRID_SIZE_X];

    // Python equivalent:
    //    for y in range(len(grid)):
    //    new_grid.append([])
    //    for x in range(len(grid[y])):
    //    new_grid[y].append(Node(counter, Location(x, y), grid[y][x] == 1, Location(x, y) == self.START,
    //                            Location(x, y) == self.END))

    for (int y = 0; y < GRID_SIZE_Y; y++) {
        grid[y] = new node[GRID_SIZE_X];
        for (int x = 0; x < GRID_SIZE_X; x++) {
            grid[y][x] = node(location(x, y), grid_base[y][x] == START, grid_base[y][x] == END, grid_base[y][x] == OBSTACLE);
        }
    }
}

