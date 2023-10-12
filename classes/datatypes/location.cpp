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
// 1 for horizontal or vertical, sqrt(2) for diagonal.(assume as 1.4)
// This function takes a location object as an argument.
// It returns the distance between the two locations.
double location::distance(location loc) const {
    // Check if the locations are the same
    if (*this == loc) {
        return 0;
    }

    // Check if the locations are diagonal
    if (x != loc.x && y != loc.y) {
        return 1.4;
    }

    // Otherwise, the locations are horizontal or vertical
    return 1;
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

location::location() {
    x = 0;
    y = 0;
    not_set = false;
}


