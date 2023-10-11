//
// Created by satyamedh on 11/10/23.
//

#ifndef CSTAR_ALGORITHM_H
#define CSTAR_ALGORITHM_H


#include "grid.h"

class algorithm {
    public:
        grid* g;
        node** open_list;
        node** closed_list;
        bool diagonal_movement_allowed;
        bool debug;

        bool solution_found;
        node** solution_nodes;

        // Constructor
        algorithm(grid* g, bool diagonal_movement_allowed, bool debug);

        // Functions
        void populate_grid(int** grid_base);

        void sort_open_list();
        void open_node(node* n);
        void close_node(node* n);

        node** solve();

};


#endif //CSTAR_ALGORITHM_H
