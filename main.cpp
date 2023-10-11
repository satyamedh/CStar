#include <iostream>

// include the location class
#include "classes/datatypes/location.h"
#include "classes/node.h"

int main() {
    // simple test of the node class
    // Create two nodes, calculate the costs, and print the results

    // Create the nodes
    location loc1(0, 0, false);
    location loc2(1, 1, false);
    node node1(loc1, false, false, false);
    node node2(loc2, false, false, false);

    // Set the parent of node2 to node1
    node2.set_parent(&node1);

    // Calculate the costs
    node2.calculate_costs(0, loc1);

    // Print the results
    std::cout << "Node 1: " << node1.loc.to_string() << std::endl;
    std::cout << "Node 2: " << node2.loc.to_string() << std::endl;
    std::cout << "Node 2 parent: " << node2.get_parent()->loc.to_string() << std::endl;
    std::cout << "Node 2 f: " << node2.f << std::endl;
}
