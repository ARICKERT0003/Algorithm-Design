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
  int dim = 5;

  std::srand( std::time(NULL) );
  time_t timer;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  std::chrono::duration< double, std::milli> elapsed;
  elapsed = std::chrono::duration< double, std::milli>::zero();

  // Print Current dimension size
  std::cout << "\n" << dim << "\n";

  // Create container for sample set
  math::Matrix<int> matA;
  math::Matrix<int> matB;
  math::Matrix<int> matC;

  //=========================
  // Naive
  // ========================

  // Pack conatiner with random numbers
  makeRandom( matA, dim );
  makeRandom( matB, dim );
  makeZero( matC, dim );

  // Print unsorted
  math::print( matA );
  math::print( matB );
  math::print( matC );

  math::matrixMultNaive( matA, matB, dim, matC );

  // Print unsorted
  math::print( matC );

  //=========================
  // Straussen
  // ========================
  std::cout << "Straussen\n\n";
  dim = 8;
  matA.clear();
  math::Matrix<int> mat11;
  math::Matrix<int> mat12;
  math::Matrix<int> mat21;
  math::Matrix<int> mat22;

  // Pack conatiner with random numbers
  makeRandom( matA, dim );
  //makeRandom( matB, dim );
  //makeZero( matC, dim );

  // Print unsorted
  math::print( matA );
  //math::print( matB );
  //math::print( matC );

  math::matrixSplit<int>( matA, dim, mat11, mat12, mat21, mat22 );

  // Print unsorted
  math::print( mat11 );
  math::print( mat12 );
  math::print( mat21 );
  math::print( mat22 );

}
