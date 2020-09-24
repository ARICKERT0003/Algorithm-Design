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

endif()
