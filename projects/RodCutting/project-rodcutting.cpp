/** 
 *  @file    project-fibonacci.cpp
 *  @author  Alex Rickert
 *  @date    10/27/20
 *  @version 1.0
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <chrono>
#include <algorithm>
#include "AlgorithmDesign.h"

void makeRandom( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
  for(; begin!=end; begin++)
  { (*begin) = std::rand() % 15 + 1; } 
}

int main()
{
  time_t timer;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  std::chrono::duration< double, std::milli> elapsed;
  elapsed = std::chrono::duration< double, std::milli>::zero();

  // Create container for sample set
  std::vector< int > vCost{1,5,8,9,10,17,17,20,24,30};
  std::vector< int > vOptimize(10, 0);
  
  // Run algorithm
  optimize::rodCutting( vCost, vOptimize );

  // Print result
  print( vOptimize );
}
