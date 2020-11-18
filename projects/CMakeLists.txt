cmake_minimum_required(VERSION 3.9.6)
project(AlgorithmDesign
  LANGUAGES CXX
  VERSION   0.0.0
  DESCRIPTION "CSE 619: Algorithm Design Library"
)

#############################
# Set General Variables
#############################
# Release or Debug
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS 
#  PRIVATE
#  "$<$<CONFIG:Debug>:${LIBALGO_DEBUG_FLAGS}>"
#  "$<$<CONFIG:Release>:${LIBALGO_RELEASE_FLAGS}>"
#)

#############################
# Recurse into Subdirectories 
#############################
if(LIBALGO_BUILD_PROJECTS)
 
  # Insertion Sort
  if(LIBALGO_BUILD_PROJECT_INSERTION_SORT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/InsertionSort)
  endif()

  # Merge Sort
  if(LIBALGO_BUILD_PROJECT_MERGE_SORT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/MergeSort)
  endif()

  # Heap Sort
  if(LIBALGO_BUILD_PROJECT_HEAP_SORT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/HeapSort)
  endif()

  # Quick Sort
  if(LIBALGO_BUILD_PROJECT_QUICK_SORT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/QuickSort)
  endif()

  # Count Sort
  if(LIBALGO_BUILD_PROJECT_COUNT_SORT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CountSort)
  endif()

  # Radix Sort
  if(LIBALGO_BUILD_PROJECT_RADIX_SORT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/RadixSort)
  endif()

  # Exponent
  if(LIBALGO_BUILD_PROJECT_EXPONENT)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Exponent)
  endif()

  # Matrix Muliplication
  if(LIBALGO_BUILD_PROJECT_MATRIX_MULTIPLICATION)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/MatrixMultiplication)
  endif()

  # Matrix Chain
  if(LIBALGO_BUILD_PROJECT_MATRIX_CHAIN)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/MatrixChain)
  endif()

  # Fibonacci
  if(LIBALGO_BUILD_PROJECT_FIBONACCI)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Fibonacci)
  endif()

  # Rod Cutting
  if(LIBALGO_BUILD_PROJECT_RODCUTTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/RodCutting)
  endif()

  # LCS
  if(LIBALGO_BUILD_PROJECT_LCS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/LCS)
  endif()

endif()
