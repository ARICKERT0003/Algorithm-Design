#include "AlgorithmDesign.h"

template< typename T >
void print( const std::vector<T>& vData )
{
  for(int i=0; i<vData.size(); i++)
  {
    std::cout << vData[i] << ", ";
  }

  std::cout << "\n";
}
template void print<int>( const std::vector<int>& );


template< typename T >
void sort::insertLinear( std::vector<T>& vData )
{
  int i, j;
  T value;

  // Iterate through data
  for(i=1; i<vData.size(); i++)
  {
    
    // Save value at i
    value = vData[i];

    // j index is one less than i index
    j = i-1;

    // Loop while 
    // j index is greater than 0 AND 
    // the value at j is greater than saved value
    while( j >= 0 && vData[ j ] > value)
    {
      // Copy value at j to next index
      vData[ j+1 ] = vData[ j ];

      // Move j forward
      j--;
    }

    // Place saved value at j-1
    vData[ j+1 ] = value;
  }
}
template void sort::insertLinear<int>( std::vector<int>& );

template< typename T>
void sort::insertBinary( std::vector<T>& vData )
{
  int i, j, k;
  T value;

  // Iterate through data
  for(i=1; i<vData.size(); i++)
  {

    // Save value at i
    value = vData[i];

    // j index is one less than i index
    j = i-1;

    // Perform binary search to yield insert index
    k = search::binary( vData, value, 0, j );

    // Replace values one-by-one until k index
    while(k <= j)
    {
      vData[ j+1 ] = vData[j];
      j--;
    }

    vData[ j+1 ] = value;
  } 
}
template void sort::insertBinary<int>( std::vector<int>& );

template< typename T>
void sort::merge( std::vector<T>& vData, int l, int r)
{
  if( r <= l )
  { return; }

  int m = ceil( (l+r)/2 );

  sort::merge( vData, l, m );
  sort::merge( vData, m+1, r );
  sort::merge( vData, l, m, r);
}
template void sort::merge<int>( std::vector<int>&, int, int );

template< typename T>
void sort::merge( std::vector<T>& vData, int l, int m, int r )
{
  std::vector< T > vLeft( vData.begin()+l, vData.begin()+m+1 );
  std::vector< T > vRight( vData.begin()+m+1, vData.begin()+r+1 );

  typename std::vector<T>::iterator iData = vData.begin()+l;
  typename std::vector<T>::iterator iLeft = vLeft.begin();
  typename std::vector<T>::iterator iRight = vRight.begin();

  while( iLeft!=vLeft.end() || iRight!=vRight.end() ) 
  {

    if( (*iLeft) < (*iRight) && iLeft!=vLeft.end() )
    { 
      (*iData) = (*iLeft);
      iLeft++;
      iData++;
      continue;
    }

    if( (*iRight) < (*iLeft) && iRight!=vRight.end() )
    {
      (*iData) = (*iRight);
      iRight++;
      iData++;
      continue;
    }

    if( iLeft==vLeft.end() )
    {
      std::copy( iRight, vRight.end(), iData );
      return;
    }

    std::copy( iLeft, vLeft.end(), iData );
    return;
  }
}
template void sort::merge<int>( std::vector<int>&, int, int, int );

template< typename T>
int search::binary( const std::vector<T>& vData, const T& value, int low, int high )
{
  // Check if bounds are equal
  if(high <= low)
  { 
    if( value < vData[low] )
    { return low;}
    else
    { return low+1; }
  }

  // Check value is equal to new partition
  int part = std::floor( (low + high)/2 );
  if( value == vData[ part ] )
  { return part+1; }

  // Recurse into lower or higher partition
  if( value < vData[ part ] )
  { return binary( vData, value, low, part-1 ); }
  
  return binary( vData, value, part+1, high ); 
}
template int search::binary<int>( const std::vector<int>&, const int&, int, int );


