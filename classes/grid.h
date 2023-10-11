//
// Created by satyamedh on 11/10/23.
//

#ifndef CSTAR_GRID_H
#define CSTAR_GRID_H


#include "datatypes/location.h"
#include "node.h"

class grid {
    public:
        location start;
        location end;
        // Grid base is a 2D array of a node state.
        // The node state is an enum defined in node.h
        state** grid_base;

        // Grid is a 2D array of nodes, which is the actual grid
        node** real_grid;

        // Functions
        node** create_grid(state**);
        node* get_node(location);
        node** get_neighbors(node*, bool include_diagonals = false);
        node** get_path(node*);

        // Constructor
        grid(location start, location end, state** grid_base);

        // Conversions
        std::string to_string() const;


};


#endif //CSTAR_GRID_H
