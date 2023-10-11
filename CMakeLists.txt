cmake_minimum_required(VERSION 3.26)
project(CStar)

set(CMAKE_CXX_STANDARD 17)

add_executable(CStar main.cpp
        classes/node.cpp
        classes/node.h
        classes/datatypes/location.cpp
        classes/datatypes/location.h
        classes/grid.cpp
        classes/grid.h)
