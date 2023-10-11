//
// Created by satyamedh on 11/10/23.
//

#include "node.h"

// Constructor
node::node(location loc, bool start, bool end, bool obstacle) {
    this->loc = loc;
    this->start = start;
    this->end = end;
    this->obstacle = obstacle;

    this->opened = false;
    this->closed = false;
    this->solution = false;

    this->g = 0;
    this->h = 0;
    this->f = 0;
}

// Functions
double node::calculate_costs(double parent_g, location end_loc) {
    // Check if not an obstacle
    if (obstacle) {
        return -1;
    }

    // Check if parent is set
    if (parent == nullptr) {
        return -1;
    }

    // Calculate the costs
    this->h = this->loc.distance(end_loc);
    this->g = this->loc.distance(parent->loc) + parent_g;
    this->f = this->g + this->h;

    return this->f;
}

void node::set_parent(node* parent_node) {
    this->parent = parent_node;
}

node *node::get_parent() const {
    return this->parent;
}

// Operators
bool node::operator==(const node& n) const {
    return loc == n.loc;
}

// Conversions
state node::get_state() const {
    if (solution) {
        return SOLUTION;
    } else if (start) {
        return START;
    } else if (end) {
        return END;
    } else if (obstacle) {
        return OBSTACLE;
    } else if (closed) {
        return CLOSED;
    } else if (opened) {
        return OPENED;
    } else {
        return TRAVERSABLE;
    }
}

node::node(){
    // initialize the node with a default location - (0, 0)
    this->loc = location(0, 0, false);
    // initialize the node with default values
    this->start = false;
    this->end = false;
    this->obstacle = false;
    this->opened = false;
    this->closed = false;
    this->solution = false;
    this->g = 0;
    this->h = 0;
    this->f = 0;
    this->parent = nullptr;
}
