/** 
 *  @file    project-matrix-multiplication.cpp
 *  @author  Alex Rickert
 *  @date    09/28/20
 *  @version 1.0
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <chrono>
#include <algorithm>
#include "AlgorithmDesign.h"

void makeRandom( math::Matrix<int>& mat, int dim )
{
  for(int i=0; i<dim; i++)
  {
    std::vector<int> temp;

    for(int j=0; j<dim; j++)
    { temp.push_back( std::rand() % 10 ); }

    mat.push_back( temp );
  }
}

void makeZero( math::Matrix<int>& mat, int dim )
{
  for(int i=0; i<dim; i++)
  {
    std::vector<int> temp(dim, 0);
    mat.push_back( temp );
  }
}

int main()
{
  // Create timers
  time_t timer;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  std::chrono::duration< double, std::milli> elapsedK;
  std::chrono::duration< double, std::milli> elapsedP;
  elapsedK = std::chrono::duration< double, std::milli>::zero();
  elapsedP = std::chrono::duration< double, std::milli>::zero();

  // Create container for solution set
  graph::AdjacencyGraph< int > inGraph;
  graph::AdjacencyGraph< int > outGraph;

  // Initialize graphs
  inGraph.resize( 7, std::vector<int>( 7, 0 ) );
  outGraph.resize( 7, std::vector<int>( 7, 0 ) );
  inGraph[0][1] = 7;  // A,B
  inGraph[0][3] = 5;  // A,D
  inGraph[1][2] = 8;  // B,C
  inGraph[1][4] = 7;  // B,E
  inGraph[2][4] = 5;  // C,E
  inGraph[3][4] = 18; // D,E
  inGraph[3][5] = 6;  // D,F
  inGraph[4][5] = 8;  // D,F
  inGraph[4][6] = 9;  // E,G
  inGraph[5][6] = 11; // F,G

  //=========================
  // Kruskal's Theorem
  // ========================

  // start timer
  start = std::chrono::steady_clock::now();
  
  // Run algorithm
  graph::mstKruskal( inGraph, outGraph );

  // Stop timer
  end = std::chrono::steady_clock::now();
  elapsedK = (end - start);

  // Print Results
  graph::print( inGraph );
  graph::print( outGraph );
  std::cout << "Kruskal time: " << elapsedK.count()/100 << "\n";

  // Clear
  //costTab.clear();
  //orderTab.clear();
  
}
