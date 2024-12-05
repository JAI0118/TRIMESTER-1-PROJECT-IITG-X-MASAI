# Traveling Salesman Problem Solver Using Simulated Annealing

This project is a C++ program that solves the Traveling Salesman Problem (TSP) using the Simulated Annealing algorithm. Given a set of cities with specific coordinates, the program attempts to find the shortest possible tour that visits each city exactly once and returns to the starting point.

## Table of Contents

- [Description](#description)
- [Requirements](#requirements)
- [Usage](#usage)


## Description

This program reads city coordinates from a `.tsp` file, optimizes the route using Simulated Annealing, and outputs the best tour and its distance. Simulated Annealing is a probabilistic technique that searches for an approximate global optimum in a large solution space, making it well-suited for TSP, an NP-hard problem.

## Requirements

- **C++ Compiler**: A compiler that supports C++11 or later.
- **Input File**: A `.tsp` file containing city coordinates in the TSPLIB format.

## Usage

1. **Clone the Repository**
    ```bash
    git clone <repository_url>
    cd <repository_name>
    ```

2. **Compile the Program**
    ```bash
    g++ -o tsp_solver tsp_solver.cpp -std=c++11
    ```

3. **Run the Program**
    ```bash
    ./tsp_solver
    ```

4. **Input the Filename**
   When prompted, enter the name of the `.tsp` file (e.g., `xqf131.tsp`).

