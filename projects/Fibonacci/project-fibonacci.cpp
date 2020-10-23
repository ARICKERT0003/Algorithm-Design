/** 
 *  @file    project-fibonacci.cpp
 *  @author  Alex Rickert
 *  @date    09/25/20
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

  // Create container for result set
  std::vector< int > vFib( vSize );
  std::vector< int > vRFib( vSize );
  std::vector< int > vGRFib( vSize );

  // Pack conatiner with random numbers
  makeRandom( vData.begin(), vData.end() );

  // Print indices
  print( vData );

  // Run standard algorithm
  std::vector< int >::iterator iFib = vFib.begin();
  std::vector< int >::iterator iNum = vData.begin();
  for(; iNum!=vData.end(); iNum++, iFib++)
  { (*iFib) = math::Fibonacci( *iNum ); }

  // Run recursive algorithm
  iFib = vRFib.begin();
  iNum = vData.begin();
  for(; iNum!=vData.end(); iNum++, iFib++)
  { (*iFib) = math::FibonacciRecursive( *iNum ); }

  // Run golden ratio algorithm
  iFib = vGRFib.begin();
  iNum = vData.begin();
  for(; iNum!=vData.end(); iNum++, iFib++)
  { (*iFib) = math::FibonacciGoldenRatio( *iNum ); }

  // Print result
  std::cout << "Standard\n";
  print( vFib );

  std::cout << "Recursive\n";
  print( vRFib );

  std::cout << "Golden Ratio\n";
  print( vGRFib );
}
