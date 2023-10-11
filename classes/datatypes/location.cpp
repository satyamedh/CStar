//
// Created by satyamedh on 11/10/23.
//

#include "location.h"

// Define the constructor
location::location(int x, int y, bool not_set) {
    this->x = x;
    this->y = y;
    this->not_set = not_set;
}

// Define the check_not_set function.
// This just returns the not_set variable.
bool location::check_not_set() const {
    return not_set;
}

// Define the set_location function.
// This sets the x and y variables to the given values, and clears the not_set variable.
void location::set_location(int x, int y) {
    this->x = x;
    this->y = y;
    not_set = false;
}

// Define the distance function.
// Distance formula: sqrt((x2 - x1)^2 + (y2 - y1)^2)
// This function takes a location object as an argument.
// It returns the distance between the two locations.
double location::distance(location loc) const {
    return sqrt(pow(loc.x - x, 2) + pow(loc.y - y, 2));
}

// Define the == operator.
// This function takes a location object as an argument.
// It returns true if the two locations are the same, and false otherwise.
bool location::operator==(const location& loc) const {
    return x == loc.x && y == loc.y;
}

// Define the to_string function.
// This function returns a string representation of the location.
std::string location::to_string() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}


