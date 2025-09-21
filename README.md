# Route Planning Project

## Overview

This project is a modern C++17 route planner built on OpenStreetMap (OSM) data. It parses OSM XML data, constructs roads graph, and computes optimal routes using an A* search. Results are rendered via the C++ 2D graphics io2d/Cairo libraries. The project was developed using modular CMake build, unit tests, and CI via GitHub actions for automated builds and tests.

<img src="map.png" width="600" height="450" />

## Dependencies for Running Locally

* Essential dependencies such as cmake, make, g++. 
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it
 

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```
### Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```

## Troubleshooting

* The googletest mock module causes build errors, so turn if off in the cmake file.
* Compiling the samples and tests files of IO2D seem to be also problematic for build, so better to turn off those things too in the cmake file.