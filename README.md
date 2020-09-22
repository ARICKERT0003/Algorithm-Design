# Algorithm Design

| Author | Created | 
| ------ | ------- |
| Alex Rickert | 09/19/2020 |

## Table of Contents

  - [Overview](#overview)
  - [Dependencies](#dependencies)
  - [Using the library](#using-the-library)
  - [Projects](#projects)
      - [Project1](#project1)
      - [Project2](#project2)

---

## Overview

C++ Code for CSE619. Library to help complete projects and homework. 

## Dependencies

- C++17
- CMake minimum 3.9.6

## Using the library

1. Unzip Algorithm-Design to project directory
   
    `unzip Algorithm-Design-master.zip`

2. First time build (Linux)
   
    1. #### Make Build Directory
      
      `mkdir build && cd build`

    2. #### Build Libraries

      `cmake .. && make`

    3. #### Build Project

      `cmake -DLIBALGO_BUILD_PROJECTS=ON .. && make`

      All individual projects are default ON but may be switched OFF.

3. First time build (Windows)
   
    1. #### Make Build Directory
      
      Make directory titled `build` inside `Algorithm-Design` directory

    2. #### Build Libraries

      Open command prompt and type:
      `cmake .. && make`

    3. #### Build Project

      Open command prompt again and type:

      `cmake -DLIBALGO_BUILD_PROJECTS=ON .. && make`

      All individual projects are default ON but may be switched OFF.

## Projects

Projects are the individual assignment code. The projects link to the library are located in the `project/` directory.

### Available Projects

1. #### Project 1:

    1. #### Description

    This project compares 2 sorting algorithms, each a different
    version of insertion sort. One uses linear search to locate where data
    needs to be inserted and one uses binary search. Randomized data sets of
    sizes 30, 300, 3000, and 30000 are required to be tested. The data sets
    must be positive integers with 3 digits. Each algorithm is run 100 times to
    get accurately averaged data.
    
      * Makes vector of correct data size.
      * Packs vector with random numbers.
      * Runs insertion sort (linear) 100 times. 
      * Calculates average time. prints.
      * Packs vector with random numbers.
      * Runs insertion sort (binary) 100 times. 
      * Calculates average time. prints.
      * Iterates to next data set size. repeat.

    2. #### CMake Variable
    
    LIBALGO_BUILD_PROJECT_INSERTION_SORT (Default ON)

    3. #### Run Project

    (Windows)
    
    Make sure library and project have been built.

    Go to `projects/InsertionSort/`

    Open command prompt and type:

    `./project-insertion-sort`
