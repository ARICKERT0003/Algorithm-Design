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
  std::vector< char > v1{'A','B','C','D','B','A','B'};
  std::vector< char > v2{'B','D','C','A','B','A'};
  math::Matrix< int > mat( v1.size(), std::vector<int>(v2.size(), 0));

  // Run algorithm
  search::LCS( v1, v2, v1.size()-1, v2.size()-1, mat);

  // Print result
  math::print( mat );
}
