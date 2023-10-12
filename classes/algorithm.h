//
// Created by satyamedh on 11/10/23.
//

#ifndef CSTAR_ALGORITHM_H
#define CSTAR_ALGORITHM_H


#include "grid.h"
#include <vector>

class algorithm {
    public:
        grid g;
        // use vector instead of array
        std::vector<node*> open_list;
        std::vector<node*> closed_list;
        bool diagonal_movement_allowed;
        bool debug;

        bool solution_found;
        std::vector<node*> solution_nodes;

        // Constructor
        algorithm(bool diagonal_movement_allowed, bool debug);

        // Functions
        void populate_grid(int** grid_base, int width, int height);

        void sort_open_list();
        void open_node(node* n);
        void close_node(node* n);

        std::vector<node*> solve();

};


#endif //CSTAR_ALGORITHM_H
