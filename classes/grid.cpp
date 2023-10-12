//
// Created by satyamedh on 11/10/23.
//

#include "grid.h"

// Constructor
grid::grid(int** grid_base, int width, int height){
    this->grid_base = grid_base;
    this->width = width;
    this->height = height;
    this->real_grid = create_grid();
}

grid::grid() {
    this->grid_base = nullptr;
    this->width = 0;
    this->height = 0;
    this->real_grid = nullptr;
}



// Functions
node **grid::create_grid() {
    bool found_start = false;
    bool found_end = false;
    // Create the grid_. To do this we need to iterate through the grid_ base and create nodes for each location
    node** grid_ = new node*[this->height];
    for (int i = 0; i < this->height; i++) {
        grid_[i] = new node[this->width];
        for (int j = 0; j < this->width; j++) {
            // Create the location
            location loc(j, i, false);

            // Create the node
            node n(loc, false, false, grid_base[i][j] == 1);

            // Set the start and end nodes. 2 is start, 3 is end
            if (grid_base[i][j] == 2) {
                n.start = true;
                start = loc;
                found_start = true;
            } else if (grid_base[i][j] == 3) {
                n.end = true;
                end = loc;
                found_end = true;
            }

            // Add the node to the grid_
            grid_[i][j] = n;
        }

    }


    if (!found_start || !found_end) {
        return nullptr;
    }

    this->real_grid = grid_;
    return grid_;
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

std::vector<node*> grid::get_path(node *n) {
    // I know this a bad way to do this, but I'm too lazy to do it the right way :P
    // Create a vector to store the path
    std::vector<node*> path;

    // Add the node to the path
    path.push_back(n);

    // Get parents until the start node is reached
    while (!n->start) {
        // Add the parent to the path
        path.push_back(n->parent);

        // Set the parent to the current node
        n = n->parent;
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

grid::~grid() {
    for (int i = 0; i < this->height; i++) {
        delete[] this->real_grid[i];
    }
    delete[] this->real_grid;
}
