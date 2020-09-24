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

template< typename T>
void print( const std::vector<T>& vData );

namespace sort
{
  template< typename T>
  void insertLinear( std::vector<T>& );

  template< typename T>
  void insertBinary( std::vector<T>& );

  template< typename T>
  void merge( std::vector<T>&, int, int);

  template< typename T>
  void merge( std::vector<T>&, int, int, int );
}

namespace search
{
  template< typename T>
  int binary( const std::vector<T>&, const T&, int, int);
}

#endif
