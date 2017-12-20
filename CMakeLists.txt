# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

# Project's name

project(universe_idle)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})

# Set location of sources
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# The following folder will be included
include_directories(${PROJECT_INCLUDE_DIR})


file(
  GLOB
  main
  ${PROJECT_SOURCE_DIR}/main.cpp
  )

# BigNum class
file(   GLOB_RECURSE
  src_bignum
  ${PROJECT_SOURCE_DIR}/*
  ${PROJECT_INCLUDE_DIR}/*
)


add_library(
    bignum
    SHARED
    ${src_bignum}
  )

add_executable(
  program
  ${main}
  ${src_bignum}
)
