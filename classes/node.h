//
// Created by satyamedh on 11/10/23.
//

#ifndef CSTAR_NODE_H
#define CSTAR_NODE_H

// include the location class
#include "datatypes/location.h"


// Node state enum
enum state {
    TRAVERSABLE,
    OBSTACLE,
    START,
    END,
    OPENED,
    CLOSED,
    SOLUTION
};

class node {
    public:
        // Constants
        location loc;
        bool start{};
        bool end{};
        bool obstacle{};
        bool opened{};
        bool closed{};

        bool solution{};

        // Costs
        double g{};
        double h{};
        double f{};

        // Parent
        node* parent{};


        // Constructor
        node(location loc, bool start, bool end, bool obstacle);
        node();

        // Functions
        double calculate_costs(double parent_g, location end_loc);
        void set_parent(node* parent);
        node* get_parent() const;

        // Operators
        bool operator==(const node& n) const;

        // Conversions
        state get_state() const;
        std::string to_string() const;

};

#endif //CSTAR_NODE_H
