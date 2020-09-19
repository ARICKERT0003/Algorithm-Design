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
int search::binary( const std::vector<T>& vData, T value, int low, int high )
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
template int search::binary<int>( const std::vector<int>&, int, int, int );


