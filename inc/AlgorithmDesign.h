/** 
 *  @file    AlgorithmDesign.h
 *  @author  Alex Rickert
 *  @date    09/19/20
 *  @version 1.0
 */

#ifndef ALGORITHM_DESIGN
#define ALGORITHM_DESIGN

#include <iostream>
#include <math.h>
#include <memory>
#include <vector>
#include <algorithm>

template< typename T>
void print( const std::vector<T>& vData );

namespace sort
{
  template< typename T>
  void insertLinear( std::vector<T>& );

  template< typename T>
  void insertLinearReverse( std::vector<T>& );

  template< typename T>
  void insertBinary( std::vector<T>& );

  template< typename T>
  void merge( std::vector<T>&, int, int);

  template< typename T>
  void merge( std::vector<T>&, int, int, int );

  template< typename T>
  void heap( std::vector<T>& );

  template< typename T>
  void heapify( std::vector<T>&, int, int );

  template<typename T>
  void quick( std::vector<T>&, int, int);

  /*
   *  @fn      sort::partition
   *  @brief   A component of quick-sort. Will find all values less than the
   *  value at high index, move them forward, and move the value at high to 
   *  the index directly following the values found to be lower than it.
   */
  template<typename T>
  int partition( std::vector<T>&, int, int);
  
  /*
   *  @fn      sort::count
   *  @brief   Histogram based sorting solution.
   *  @param   inVector Vector of data to be sorted
   *  @param   maxValue Maximum value contained within inVector
   *  @param   outVector Sorted vector.
   */
  template<typename T>
  void count( std::vector<T>&, T , std::vector<T>&);
  
  /*
   *  @fn      sort::radix
   */
  template<typename T>
  void radix( std::vector<T>& );

  /*
   *  @fn      sort::countDigit
   *  @brief   Histogram based sorting solution.
   *  @param   inVector Vector of data to be sorted
   *  @param   digit Base 10 digit for which to sort by
   */
  template<typename T>
  void countDigit( std::vector<T>&, int);
}

namespace math
{
  const double GOLDEN_RATIO = 1.618033989;

  template< typename T>
  T exponent( T, int );

  template< typename T>
  T exponentDAC( T, int, int=4294967295 );

  template< typename T>
  using Matrix = std::vector< std::vector<T> >;

  /*
   *  @fn      math::matrixMultNaive
   *  @brief   Naive implementation of matrix multiplication for square matrices. 
   *  @param   matA Input matrix to multiply
   *  @param   matB Input matrix to multiply
   *  @param   dim Dimension of all matrices
   *  @param   matC Output matrix
   */
  template< typename T>
  void matrixMultNaive( const Matrix<T>&, const Matrix<T>&, int, Matrix<T>& );

  /*
   *  @fn      math::matrixMultStrassen
   *  @brief   Strausen implementation of matrix multiplication for square matrices. 
   *  @param   matA Input matrix to multiply
   *  @param   matB Input matrix to multiply
   *  @param   dim Dimension of all matrices
   *  @param   matC Output matrix
   */
  template< typename T>
  void matrixMultStrassen( const Matrix<T>&, const Matrix<T>&, int, Matrix<T>& );

  template< typename T>
  void matrixSplit( const Matrix<T>&, int dim, Matrix<T>&, Matrix<T>&, Matrix<T>&, Matrix<T>& );

  void matrixChainCost( const std::vector< int >&, math::Matrix< int >&, math::Matrix< int >& );
  void matrixChainCostRecursive(const std::vector< int >&, int, int, math::Matrix< int >&, math::Matrix< int >&);

  template< typename T>
  void print( const Matrix<T>& );

  template< typename T>
  void zero( Matrix<T>& );

  /*
   *   @fn     math::Fibonacci
   *   @brief  Calculate fibonacci number at index n
   *   @param  index Index of fibonacci number user would like to calculate
   */
  int Fibonacci( int );

  /*
   *   @fn     math::rFibonacci
   *   @brief  Calculate fibonacci number at index n recursively
   *   @param  index Index of fibonacci number user would like to calculate
   */
  int FibonacciRecursive( int );

  /*
   *   @fn     math::FibonacciGoldenRatio
   *   @brief  Calculate fibonacci number at index n using golden ration and
   *           recursive exponentation
   *   @param  index Index of fibonacci number user would like to calculate
   */
  int FibonacciGoldenRatio( int );
}

namespace search
{
  template< typename T>
  int binary( const std::vector<T>&, const T&, int, int);

  template< typename T>
  void LCS( const std::vector<T>&, const std::vector<T>&, int, int, math::Matrix<int>& );
}

namespace optimize
{
  void rodCutting( std::vector< int >&, std::vector< int >& );
}
#endif
