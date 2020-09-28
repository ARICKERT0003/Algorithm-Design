/** 
 *  @file    project-insertion-sort.h
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
  std::srand( std::time(NULL) );
  time_t timer;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  std::chrono::duration< double, std::milli> elapsed;
  elapsed = std::chrono::duration< double, std::milli>::zero();

  // ========================
  // Part 1.
  // Sample set of 30, 300, 
  // 3000, and 30000 random positive ints
  // ========================
  
  for(int vSize=30; vSize<=30000; vSize*=10)
  {
    // Print Current set size
    std::cout << "\n" << vSize << "\n";

    // Create container for sample set
    std::vector< int > vData( vSize );

    // ========================
    // Part 1.1
    // Sort using insertion sort w/ linear search
    // Iterate 5 times to get average runtime
    // ========================
    
    // Pack conatiner with random numbers
    makeRandom( vData.begin(), vData.end() );

    // Print unsorted
    //print( vData );

    // Iterate a couple times to get average running time
    for(int i=0; i<iMax; i++)
    {
      // Start timer
      start = std::chrono::steady_clock::now();

      // Sort using insertion sort (linear search)
      sort::insertLinear( vData );

      // End timer
      end = std::chrono::steady_clock::now();
      elapsed += (end - start);
    }

    // Print sorted
    //print( vData );

    // Print average runtime
    elapsed = elapsed / iMax;
    std::cout << elapsed.count() << "\n";
    elapsed = std::chrono::duration< double, std::milli>::zero();

    // ========================
    // Part 1.2
    // Sort using insertion sort w/ binary search
    // Iterate 5 times to get average runtime
    // ========================

    // Pack container with random numbers
    makeRandom( vData.begin(), vData.end() );

    // Print unsorted
    //print( vData );

    // Iterate a couple times to get average running time
    for(int i=0; i<iMax; i++)
    {
      // Start timer
      start = std::chrono::steady_clock::now();

      // Sort using insertion sort (linear search)
      sort::insertBinary( vData );

      // End timer
      end = std::chrono::steady_clock::now();
      elapsed += (end - start);
    }

    // Print sorted
    //print( vData );

    // Print average runtime
    elapsed = elapsed / iMax;
    std::cout << elapsed.count() << "\n";
  } 

  int vSize = 15;

  // Create container for sample set
  std::vector< int > vData( vSize );

  // Pack container with random numbers
  makeRandom( vData.begin(), vData.end() );

  // Print unsorted
  print( vData );

  // Iterate a couple times to get average running time
  for(int i=0; i<iMax; i++)
  {
    // Start timer
    start = std::chrono::steady_clock::now();

    // Sort using insertion sort (linear search)
    sort::insertLinearReverse( vData );

    // End timer
    end = std::chrono::steady_clock::now();
    elapsed += (end - start);
  }

  // Print sorted
  print( vData );

  // Print average runtime
  elapsed = elapsed / iMax;
  std::cout << elapsed.count() << "\n";
}
