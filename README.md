# CStar

## what is this?
This is a C++ implementation of the A* algorithm. 

## why?
I wanted to learn C++ and I wanted to learn about pathfinding algorithms. I first implemented the A* algorithm in Python over [here](https://github.com/satyamedh/PyStar), but I wanted to see how much faster it would be in C++. (Spoiler: it's a lot faster)

## how do I use it?
Please don't. This is quite inefficient, literally the first thing I have written in c++. I'm sure there are better implementations out there. If you really want to use it, you can clone the repo use `cmake`(and `make`) to build the executable. Then run the generated executable to run the program. You can change the map in `main.cpp` to whatever you want. The map is a 2D array of integers. 0 is a walkable tile, 1 is a wall, 2 is the start, and 3 is the end. The program will print out the path it found and the time it took to find it.

## how does it work?
For a detailed explanation of the A* algorithm, check out [this youtube video](https://www.youtube.com/watch?v=-L-WgKMFuhE) from Sebastian Lague.(OK HOW DOES COPILOT KNOW WHICH VIDEO I WAS ABOUT TO LINK TO)

My implementation takes in a 2D array of integers(int**) and iterates through them to convert them into [nodes](https://github.com/satyamedh/CStar/blob/master/classes/node.cpp).

These nodes are a class which have properties like their position, their parent, and their f, g, and h costs. (If you want to know what those are, watch the video)

Then it is arranged into a [grid](https://github.com/satyamedh/CStar/blob/master/classes/grid.cpp) which is a class that has a 2D array of nodes and a few functions to manipulate them.

Finally, the [algorithm class](https://github.com/satyamedh/CStar/blob/master/classes/algorithm.cpp) takes in the grid and runs the A* algorithm on it. It returns a vector of nodes which is the path it found, or an empty vector if it couldn't find a path.

Thank you for attending my ted talk.

## what's next?
I shall get this to run on an esp32 for an upcoming competition


