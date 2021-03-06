/** 
 *  @file    project-quick-sort.cpp
 *  @author  Alex Rickert
 *  @date    09/19/20
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
  { (*begin) = std::rand() % 900 + 100; } 
}

int main()
{
  int iMax = 100;
  int vSize = 15;
  std::srand( std::time(NULL) );
  time_t timer;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  std::chrono::duration< double, std::milli> elapsed;
  elapsed = std::chrono::duration< double, std::milli>::zero();

  // Print Current set size
  std::cout << "\n" << vSize << "\n";

  // Create container for sample set
  std::vector< int > vData( vSize );

  // Pack conatiner with random numbers
  makeRandom( vData.begin(), vData.end() );

  // Print unsorted
  print( vData );

  sort::quick( vData, 0, vData.size()-1 );

  // Print unsorted
  print( vData );
}
