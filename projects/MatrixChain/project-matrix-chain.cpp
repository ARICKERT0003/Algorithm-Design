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
  std::chrono::duration< double, std::milli> elapsedTab;
  std::chrono::duration< double, std::milli> elapsedRec;
  elapsedTab = std::chrono::duration< double, std::milli>::zero();
  elapsedRec = std::chrono::duration< double, std::milli>::zero();

  // Create container for solution set
  math::Matrix<int> costTab;
  math::Matrix<int> costRec;
  math::Matrix<int> orderTab;
  math::Matrix<int> orderRec;

  //=========================
  // 5 Data Points
  // ========================

  std::vector< int > dims1{ 30, 1, 40, 10, 25 };
  costTab.resize( dims1.size()-1, std::vector( dims1.size()-1, 0 ) );
  orderTab.resize( dims1.size()-1, std::vector( dims1.size()-1, 0 ) );
  costRec.resize( dims1.size()-1, std::vector( dims1.size()-1, 0 ) );
  orderRec.resize( dims1.size()-1, std::vector( dims1.size()-1, 0 ) );

  for( int i=0; i<100; i++ )
  {
    // Zero
    math::zero( costTab );
    math::zero( costRec );
    math::zero( orderTab );
    math::zero( orderRec );

    // start timer
    start = std::chrono::steady_clock::now();
    
    // Run algorithm
    math::matrixChainCost( dims1, costTab, orderTab );

    // Stop timer
    end = std::chrono::steady_clock::now();
    elapsedTab += (end - start);

    // Start timer
    start = std::chrono::steady_clock::now();

    // Run algorithm
    math::matrixChainCostRecursive( dims1, 0, dims1.size()-2, costRec, orderRec );

    // Stop timer
    end = std::chrono::steady_clock::now();
    elapsedRec += (end - start);
  }

  // Print Results
  math::print( costTab );
  math::print( orderTab );
  math::print( costRec );
  math::print( orderRec );
  std::cout << "Tabular time: " << elapsedTab.count()/100 << "\n";
  std::cout << "Recursive time: " << elapsedRec.count()/100 << "\n\n";

  // Clear
  costTab.clear();
  orderTab.clear();
  costRec.clear();
  orderRec.clear();
  
  //=========================
  // 9 Data Points
  // ========================
  std::vector< int > dims2{ 80, 96, 66, 4, 85, 94, 68, 76, 75 };
  costTab.resize( dims2.size()-1, std::vector( dims2.size()-1, 0 ) );
  orderTab.resize( dims2.size()-1, std::vector( dims2.size()-1, 0 ) );
  costRec.resize( dims2.size()-1, std::vector( dims2.size()-1, 0 ) );
  orderRec.resize( dims2.size()-1, std::vector( dims2.size()-1, 0 ) );

  for( int i=0; i<100; i++ )
  {
    // Zero
    math::zero( costTab );
    math::zero( costRec );
    math::zero( orderTab );
    math::zero( orderRec );

    // start timer
    start = std::chrono::steady_clock::now();
    
    // Run algorithm
    math::matrixChainCost( dims2, costTab, orderTab );

    // Stop timer
    end = std::chrono::steady_clock::now();
    elapsedTab += (end - start);

    // Start timer
    start = std::chrono::steady_clock::now();

    // Run algorithm
    math::matrixChainCostRecursive( dims2, 0, dims2.size()-2, costRec, orderRec );

    // Stop timer
    end = std::chrono::steady_clock::now();
    elapsedRec += (end - start);
  }

  // Print Results
  math::print( costTab );
  math::print( orderTab );
  math::print( costRec );
  math::print( orderRec );
  std::cout << "Tabular time: " << elapsedTab.count()/100 << "\n";
  std::cout << "Recursive time: " << elapsedRec.count()/100 << "\n\n";
}
