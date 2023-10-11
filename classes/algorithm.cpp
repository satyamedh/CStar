//
// Created by satyamedh on 11/10/23.
//

#include "algorithm.h"

// Constructor
algorithm::algorithm(grid* g, bool diagonal_movement_allowed, bool debug) {
    this->g = g;
    this->diagonal_movement_allowed = diagonal_movement_allowed;
    this->debug = debug;

    this->solution_found = false;
    this->solution_nodes = nullptr;

    this->open_list = new node*[g->height * g->width];
    this->closed_list = new node*[g->height * g->width];
}

// Functions
void algorithm::populate_grid(int** grid_base) {
    // Populating the grid resets the solution flags and the open and closed lists
    this->solution_found = false;
    this->solution_nodes = nullptr;

    this->open_list = new node*[g->height * g->width];
    this->closed_list = new node*[g->height * g->width];
}


