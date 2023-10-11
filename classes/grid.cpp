//
// Created by satyamedh on 11/10/23.
//

#include <vector>
#include "grid.h"

// Constructor
grid::grid(int** grid_base, int width, int height){
    this->grid_base = grid_base;
    this->width = width;
    this->height = height;
    this->real_grid = create_grid();
}


// Functions
node **grid::create_grid() {
    // Create the grid. To do this we need to iterate through the grid base and create nodes for each location
    node** grid = new node*[this->height];
    for (int i = 0; i < this->height; i++) {
        grid[i] = new node[this->width];
        for (int j = 0; j < this->width; j++) {
            // Create the location
            location loc(j, i, false);

            // Create the node
            node n(loc, false, false, grid_base[i][j] == 1);

            // Set the start and end nodes. 2 is start, 3 is end
            if (grid_base[i][j] == 2) {
                n.start = true;
                start = loc;
            } else if (grid_base[i][j] == 3) {
                n.end = true;
                end = loc;
            }

            // Add the node to the grid
            grid[i][j] = n;
        }
    }

    return grid;

}

node *grid::get_node(location loc) {
    // Check if the location is in the grid
    if (loc.x < 0 || loc.x >= this->width || loc.y < 0 || loc.y >= this->height) {
        return nullptr;
    }

    return &(this->real_grid[loc.y][loc.x]);
}

node **grid::get_neighbors(node *n, bool include_diagonals) {
    // Get the location of the node
    location loc = n->loc;

    // Create the neighbors array
    node** neighbors = new node*[8];

    // Get the neighbors
    neighbors[0] = get_node(location(loc.x, loc.y - 1, false));
    neighbors[1] = get_node(location(loc.x + 1, loc.y, false));
    neighbors[2] = get_node(location(loc.x, loc.y + 1, false));
    neighbors[3] = get_node(location(loc.x - 1, loc.y, false));

    if (include_diagonals) {
        neighbors[4] = get_node(location(loc.x + 1, loc.y - 1, false));
        neighbors[5] = get_node(location(loc.x + 1, loc.y + 1, false));
        neighbors[6] = get_node(location(loc.x - 1, loc.y + 1, false));
        neighbors[7] = get_node(location(loc.x - 1, loc.y - 1, false));
    }

    return neighbors;
}

node **grid::get_path(node *n) {
    // I know this a bad way to do this, but I'm too lazy to do it the right way :P
    // Create a vector to store the path
    int path_length = 0;

    // Get the path length
    node* current_node = n;
    while (!current_node->start) {
        path_length++;
        current_node = current_node->parent;
    }

    // Create the path
    node** path = new node*[path_length];
    while (!current_node->start) {
        path[path_length - 1] = current_node;
        path_length--;
        current_node = current_node->parent;
    }

    return path;
}


// Conversions
std::string grid::to_string() const {
    std::string str = "";
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            // Get the node
            node n = this->real_grid[i][j];
            // get state
            state s = n.get_state();
            // Add to string
            str += std::to_string(s);
        }
        str += "\n";
    }

    return str;
}