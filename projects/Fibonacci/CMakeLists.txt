cmake_minimum_required(VERSION 3.9.6)
project(AlgorithmDesign
  LANGUAGES CXX
  VERSION   0.0.0
  DESCRIPTION "CSE 619: Algorithm Design Library"
)

#############################
# Variables for all Exe
#############################
link_directories( ${LIBALGO_LIBRARY_OUTPUT_DIR} )

#############################
# Brute Force
#############################
set( SAMPLE_NAME project-fibonacci )
add_executable( ${SAMPLE_NAME} project-fibonacci.cpp )

set_target_properties(${SAMPLE_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories( ${SAMPLE_NAME} PUBLIC ${LIBALGO_INC_DIRS} )
target_link_libraries( ${SAMPLE_NAME} PUBLIC algorithm-design ${LIBALGO_LIBS} )
