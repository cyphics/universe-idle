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

file(
  GLOB
  src_physics
  ${PROJECT_SOURCE_DIR}/physics/*
  ${PROJECT_INCLUDE_DIR}/physics/*
  )


file(   GLOB_RECURSE
  src_classes
  ${PROJECT_SOURCE_DIR}/class/*
  ${PROJECT_INCLUDE_DIR}/class/*
)

file(   GLOB_RECURSE
  src_helpers
  ${PROJECT_SOURCE_DIR}/helpers/*
  ${PROJECT_INCLUDE_DIR}/helpers/*
)

add_library(
    physics
    SHARED
    ${src_physics}
)

add_library(
    bignum
    SHARED
    ${src_classes}
    ${src_helpers}
  )

add_executable(
  program
  ${main}
  ${src_classes}
  ${src_helpers}
  ${src_physics}
)
