#include <iostream>

// include the location class
#include "classes/datatypes/location.h"

int main() {
    // simple test of the location class
    // Create two locations, print their locations and then print the distance between them.

    // Create the first location
    location loc1(0, 0, false);
    // Create the second location
    location loc2(3, 4, false);

    // Print the locations
    std::cout << "Location 1: " << loc1.to_string() << std::endl;
    std::cout << "Location 2: " << loc2.to_string() << std::endl;

    // Print the distance between the two locations
    std::cout << "Distance between the two locations: " << loc1.distance(loc2) << std::endl;

    return 0;
}
