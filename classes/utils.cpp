//
// Created by satyamedh on 11/10/23.
//

#include "utils.h"

int** utils::createDynamicArray(int rows, int cols) {
    int** array = new int*[rows]; // Allocate an array of pointers to integers (rows)
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols]; // Allocate an array of integers (columns) for each row
    }
    return array;
}
