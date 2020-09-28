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


//===========================
// Sort
//===========================
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

template< typename T >
void sort::insertLinearReverse( std::vector<T>& vData )
{
  int i, j;
  T value;

  for(i=vData.size()-2; 0<=i; i--)
  {

    value = vData[i];

    j = i+1;

    while( j<vData.size() && vData[j] > value)
    {
      vData[ j-1 ] = vData[j];

      j++;
    }

    vData[ j-1 ] = value;
  }
}
template void sort::insertLinearReverse( std::vector<int>& );

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
void sort::heap( std::vector<T>& vData )
{
  // Build heap by rearanging from bottom up
  for( int i=(vData.size()/2)-1; i>=0; i-- )
  { sort::heapify( vData, vData.size(), i ); }

  // Begin removing nodes, then rearange, repeat
  for( int i=vData.size()-1; 0<i; i-- )
  {
    std::swap( vData[0], vData[i] );

    sort::heapify(vData, i, 0);
  }
}
template void sort::heap<int>( std::vector<int>& );

template< typename T>
void sort::heapify( std::vector<T>& vData, int heapSize, int i )
{
  int largest = i;
  int lChild = 2*i+1;
  int rChild = 2*i+2;

  if( lChild < heapSize && vData[ largest ] < vData[ lChild ] )
  { largest = lChild; }

  if( rChild < heapSize && vData[ largest ] < vData[ rChild ] )
  { largest = rChild; }

  if( largest != i )
  {
    std::swap( vData[i], vData[largest] );
    sort::heapify( vData, heapSize, largest );
  }
}
template void sort::heapify<int>( std::vector<int>&, int, int );

template< typename T>
void sort::quick( std::vector<T>& vData, int low, int high )
{
  if( high <= low )
  { return; }


  // Find / Move forward all numbers lower than high
  int i = sort::partition( vData, low, high );

  // Recurse lower
  sort::quick( vData, low, i-1 );

  // Recurse higher
  sort::quick( vData, i+1, high);
}
template void sort::quick<int>( std::vector<int>&, int, int );

template< typename T>
int sort::partition( std::vector<T>& vData, int low, int high )
{
  // Use high index as comparator
  int pivot = vData[high]; 

  int i = low-1;

  for(int j=low; j<high; j++)
  {
    if( vData[j] < pivot )
    {
      i++;
      std::swap( vData[i], vData[j] );
    }
  }

  std::swap( vData[i+1], vData[high] );
  return i+1;
}
template int sort::partition<int>( std::vector<int>&, int, int );

template< typename T>
void sort::count( std::vector<T>& vData, T maxValue, std::vector<T>& vOutput )
{
  int i=0;

  // Create output array 
  vOutput.resize( vData.size() );

  // Create histogram array
  std::vector<T> histogram( maxValue+1, 0 );

  // Pack histogram
  for( i=0; i<vData.size(); i++ )
  { (histogram[ vData[i] ])++; }

  // Calculate cumulative histogram
  for( i=1; i<histogram.size(); i++ )
  { histogram[i] += histogram[i-1]; }

  // Histogram maps input data to output data
  for( i=0; i<vData.size(); i++ )
  { 
    vOutput[ histogram[ vData[ i ]] -1 ] = vData[i]; // Histogram mapping will be 1 off since it is count based
    (histogram[ vData[ i ]])--;                      // Account for duplicate values
  }
}
template void sort::count<int>(std::vector<int>&, int, std::vector<int>&);

template< typename T>
void sort::radix( std::vector<T>& vData )
{
  T maxValue = *std::max_element( vData.begin(), vData.end() );

  for( int i=1; (maxValue/i)>0; i*=10 )
  { 
    sort::countDigit( vData, i ); 
    print(vData);
  }
}
template void sort::radix<int>( std::vector<int>& );

template< typename T>
void sort::countDigit( std::vector<T>& vData, int digit )
{
  int i=0;

  // Create output array 
  std::vector<T> vOutput( vData.size(), 0 );

  // Create histogram array
  std::vector<T> histogram( 10, 0 ); // Since we are sorting per each base 10 digit

  // Pack histogram
  for( i=0; i<vData.size(); i++ )
  { (histogram[ (vData[i]/digit)%10 ])++; }

  // Calculate cumulative histogram
  for( i=1; i<10; i++ )
  { histogram[i] += histogram[i-1]; }

  // Histogram maps input data to output data
  //for( i=0; i<vData.size(); i++ )
  for( i=vData.size()-1; i>=0; i-- )
  { 
    vOutput[ histogram[ (vData[i]/digit)%10 ] -1 ] = vData[i]; // Histogram mapping will be 1 off since it is count based
    (histogram[ (vData[i]/digit)%10 ])--;                      // Account for duplicate values
  }

  // Swap input and output vectors
  vData.swap(vOutput);

}
template void sort::countDigit<int>(std::vector<int>&, int);

//===========================
// Search
//===========================
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

//===========================
// Math
//===========================
template< typename T>
void math::matrixMultNaive( const math::Matrix<T>& matA, const math::Matrix<T>& matB, int dim, math::Matrix<T>& matC )
{
  for( int i=0; i<dim; i++ )
  {
    for(int j=0; j<dim; j++)
    {
      matC[i][j] = 0;

      for(int k=0; k<dim; k++)
      {
        matC[i][j] += matA[i][k] * matB[k][j];
      } 
    }
  }
}
template void math::matrixMultNaive<int>( const math::Matrix<int>&, const math::Matrix<int>&, int, math::Matrix<int>& );

template< typename T>
void math::print( const math::Matrix<T>& mat )
{
  for( int i=0; i<mat.size(); i++ )
  {
    for(int j=0; j<(mat[0]).size(); j++)
    { std::cout << mat[i][j] << " "; }

    std::cout << "\n";
  }
  std::cout << "\n";
}
template void math::print<int>(const math::Matrix<int>&);
