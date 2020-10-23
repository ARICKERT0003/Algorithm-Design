cmake_minimum_required(VERSION 3.9.6)
project(AlgorithmDesign
  LANGUAGES CXX
  VERSION   0.0.0
  DESCRIPTION "CSE 619: Algorithm Design Library"
)

#############################
# Options
#############################
option(LIBALGO_STATIC_BUILD                         "Build static library" OFF)
option(LIBALGO_BUILD_PROJECTS                       "Build samples" OFF)
option(LIBALGO_BUILD_PROJECT_INSERTION_SORT         "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_MERGE_SORT             "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_HEAP_SORT              "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_QUICK_SORT             "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_COUNT_SORT             "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_RADIX_SORT             "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_EXPONENT               "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_MATRIX_MULTIPLICATION  "Build sample" ON)
option(LIBALGO_BUILD_PROJECT_FIBONACCI              "Build sample" ON)

# Static or Dynamic Link
if(LIBALGO_STATIC_BUILD)
  set(LINK_TYPE STATIC)
else()
  set(LINK_TYPE SHARED)
endif()

#############################
# Set General Variables 
#############################
# Library Variables
set(LIBRARY_NAME algorithm-design)
set(SH_VER 0)

# Library Output Dir
if(NOT LIBALGO_LIBRARY_OUTPUT_DIR)
  set( LIBALGO_LIBRARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
endif()

# Library Install Dir
if(NOT LIBALGO_LIBRARY_INSTALL_DIR)
  set( LIBALGO_LIBRARY_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/lib)
endif()

# Header Install Dir
if(NOT LIBALGO_HEADER_INSTALL_DIR)
  set( LIBALGO_HEADER_INSTALL_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/install/inc)
endif()

# Extern Library Output
if(NOT LIBALGO_EXTERN_LIBRARY_OUTPUT_DIR)
  set( LIBALGO_EXTERN_LIBRARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/lib)
endif()

# Extern Library Install
if(NOT LIBALGO_EXTERN_LIBRARY_INSTALL_DIR)
  set( LIBALGO_EXTERN_LIBRARY_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/lib)
endif()

# Extern Header Install
if(NOT LIBALGO_EXTERN_HEADER_INSTALL_DIR)
  set( LIBALGO_EXTERN_HEADER_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/inc)
endif()

#############################
# Set Compiler Flags Variable
#############################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Base Compiler Flags
set(LIBALGO_DEBUG_FLAGS 
  -Wall 
  -Wextra
  -Werror
  -W
  -DDEBUG
  -g
)

set(LIBALGO_RELEASE_FLAGS
  -pedantic
  -03
)

#############################
# Set Files and Directories
#############################
# Source Files
set(SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/AlgorithmDesign.cpp
)

# Header Files
set(HEADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/inc/AlgorithmDesign.h
)

# Include Directory
set(LIBALGO_INC_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

#############################
# Set External Files and Directories
#############################
# QT
#find_package( Qt5 COMPONENTS Core Widgets REQUIRED )
#set( CMAKE_AUTOMOC ON )
#set( CMAKE_AUTORCC ON )
#set( CMAKE_AUTOUIC ON )

# Boost
#find_package( Boost 1.73.0 REQUIRED )

list( APPEND LIBALGO_INC_DIRS
  #${Boost_INCLUDE_DIRS}
)

set(LIBALGO_LIBS 
  pthread
  stdc++fs
  #Qt5::Core
  #Qt5::Widgets
)

#############################
# Recurse into Directories
#############################
#if(LIBALGO_BUILD_EXTERN)
#  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern)
#  list(APPEND PROJECT_INC_DIRS
#)
#endif()
#
## Set all Directories which contain libraries
#link_directories(${LIBALGO_LIB_DIRS})

#############################
# Make Target and Set Props
#############################
# Make Library Binary
add_library( ${LIBRARY_NAME} ${LINK_TYPE} ${SRC_FILES} )

# Set Library Properties
set_target_properties( ${LIBRARY_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER "${HEADER_FILES}"
  ARCHIVE_OUTPUT_DIRECTORY "${LIBALGO_LIBRARY_OUTPUT_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${LIBALGO_LIBRARY_OUTPUT_DIR}"
)

# Target Compiler Flags
target_compile_options( ${LIBRARY_NAME}
  PRIVATE
  "$<$<CONFIG:Debug>:${LIBALGO_DEBUG_FLAGS}>"
  "$<$<CONFIG:Release>:${LIBALGO_RELEASE_FLAGS}>"
)

#############################
# Find and Link Libraries
#############################
# Target Include Directories
target_include_directories( ${LIBRARY_NAME}
  PUBLIC
  ${LIBALGO_INC_DIRS}
)

# Link External Libraries
target_link_libraries( ${LIBRARY_NAME}
  PUBLIC
  ${LIBALGO_LIBS}
)

#############################
# Set Install Options
#############################
# Install 
install(
  TARGETS ${LIBRARY_NAME}
  ARCHIVE DESTINATION ${LIBALGO_LIBRARY_INSTALL_DIR}
  LIBRARY DESTINATION ${LIBALGO_LIBRARY_INSTALL_DIR}
  PUBLIC_HEADER DESTINATION ${LIBALGO_HEADER_INSTALL_DIR}
)

#############################
# Samples
#############################
if(LIBALGO_BUILD_PROJECTS)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects)
endif()
