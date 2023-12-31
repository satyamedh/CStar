//
// Created by satyamedh on 11/10/23.
//

#include <iostream>
#include "algorithm.h"

// Constructor
algorithm::algorithm(bool diagonal_movement_allowed, bool debug) {
    this->diagonal_movement_allowed = diagonal_movement_allowed;
    this->debug = debug;

    this->solution_found = false;
    this->solution_nodes = std::vector<node*>();

    this->open_list = std::vector<node*>();
    this->closed_list = std::vector<node*>();
}

// Functions
void algorithm::populate_grid(int** grid_base, int width, int height) {
    // Populating the grid resets the solution flags and the open and closed lists
    this->solution_found = false;
    this->solution_nodes = std::vector<node*>();

    this->open_list = std::vector<node*>();
    this->closed_list = std::vector<node*>();

    // Convert the grid base to a grid
    g = grid(grid_base, width, height);
    g.create_grid();

    // check if the grid was created successfully
    if (g.real_grid == nullptr) {
        std::cout << "Grid not created successfully. Are you sure you have a start and an end node?" << std::endl;
        return;
    }

}

void algorithm::sort_open_list() {
    // Sort the open list based on the f value of the nodes
    // This is a simple bubble sort
    for (int i = 0; i < open_list.size(); i++) {
        for (int j = 0; j < open_list.size() - i - 1; j++) {
            if (open_list[j]->f > open_list[j + 1]->f) {
                node* temp = open_list[j];
                open_list[j] = open_list[j + 1];
                open_list[j + 1] = temp;
            }
        }
    }
}

void algorithm::open_node(node *n) {
    // Check if the node is already in the open list
    for (auto & i : open_list) {
        if (i == n) {
            return;
        }
    }

    // Check if the node is already in the closed list
    for (auto & i : closed_list) {
        if (i == n) {
            return;
        }
    }

    // Add the node to the open list
    open_list.push_back(n);
    n->opened = true;
}

void algorithm::close_node(node *n) {
    // Check if the node is already in the closed list
    for (auto & i : closed_list) {
        if (i == n) {
            return;
        }
    }

    // remove the node from the open list
    // I know I should use vector.erase() but I'm too lazy so sorry
    for (int i = 0; i < open_list.size(); i++) {
        if (open_list[i] == n) {
            open_list.erase(open_list.begin() + i);
            break;
        }
    }

    // Add the node to the closed list
    closed_list.push_back(n);
    n->closed = true;
}

std::vector<node *> algorithm::solve() {
    // Print a message if debug is enabled
    if (debug) {
        std::cout << "Solving the maze" << std::endl;
    }
    // Return the solution if it has already been found
    if (solution_found) {
        return solution_nodes;
    }
    // Make sure the grid is populated
    if (g.grid_base == nullptr) {
        std::cout << "Grid not populated" << std::endl;
        return {};
    }

    // Add the start node to the open list
    open_node(g.get_node(g.start));

    // Get the end node
    node* end_node = g.get_node(g.end);

    // Loop until the open list is empty
    while (!open_list.empty()){
        // Sort the open list
        sort_open_list();

        // Get the node with the lowest f cost
        node* current_node = open_list[0];
        this->close_node(current_node);

        // Check if the current node is the end node
        if (current_node == end_node) {
            // Print a message if debug is enabled
            if (debug) {
                std::cout << "Solution found" << std::endl;
            }
            // Set the solution found flag
            solution_found = true;

            // Get the path
            std::vector<node*> path = g.get_path(current_node);

            // Set the solution nodes
            solution_nodes = path;

            // Return the path
            return path;
        }

        // Get the neighbors of the current node
        node** neighbors = g.get_neighbors(current_node, this->diagonal_movement_allowed);
        for (int i = 0; i < (this->diagonal_movement_allowed?8:4); i++) { // 8 if diagonal movement is allowed, 4 otherwise
            // Check if the neighbor is null
            if (neighbors[i] == nullptr) {
                // if debug is enabled, print a message
                if (debug) {
                    std::cout << "Neighbor " << i << " is null" << std::endl;
                }
                continue;
            }

            // Check if the neighbor is an obstacle
            if (neighbors[i]->obstacle) {
                // if debug is enabled, print a message
                if (debug) {
                    std::cout << "Neighbor at (" << neighbors[i]->loc.x << ", " << neighbors[i]->loc.y << ") is an obstacle" << std::endl;
                }
                continue;
            }

            // Check if the neighbor is in the closed list
            if (neighbors[i]->closed) {
                // if debug is enabled, print a message
                continue;
            }

            // check if the neighbor already has a parent, and if it does, check if the current node is a
            // better parent
            if (neighbors[i]->parent == nullptr || neighbors[i]->g > ((current_node->g) + 1)) {
                // if debug is enabled, print a message
                if (debug) {
                    std::cout << "Setting parent of node at (" << neighbors[i]->loc.x << ", " << neighbors[i]->loc.y << ") to (" << current_node->loc.x << ", " << current_node->loc.y << ")" << std::endl;
                }
                // Set the parent of the neighbor to the current node
                neighbors[i]->set_parent(current_node);
                // Calculate the new costs of the neighbor
                neighbors[i]->calculate_costs(current_node->g, g.end);
                // Add the neighbor to the open list
                open_node(neighbors[i]);
            }
        }
        // Delete the neighbors array
        delete[] neighbors;
    }

    // A solution was not found :(
    // Print a message if debug is enabled
    if (debug) {
        std::cout << "Solution not found" << std::endl;
    }

    // Return an empty vector
    return {};
}








