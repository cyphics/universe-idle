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


file( GLOB_RECURSE
  src_main
  ${PROJECT_SOURCE_DIR}/main/*
  ${PROJECT_INCLUDE_DIR}/main/*
  )

file( GLOB_RECURSE
  src_physics
  ${PROJECT_SOURCE_DIR}/physics/*
  ${PROJECT_INCLUDE_DIR}/physics/*
  )


file( GLOB_RECURSE
  src_managment
  ${PROJECT_SOURCE_DIR}/managment/*
  ${PROJECT_INCLUDE_DIR}/managment/*
)

file( GLOB_RECURSE
  src_ship
  ${PROJECT_SOURCE_DIR}/ship/*
  ${PROJECT_INCLUDE_DIR}/ship/*
)

file( GLOB_RECURSE
  src_simulation
  ${PROJECT_SOURCE_DIR}/simulation/*
  ${PROJECT_INCLUDE_DIR}/simulation/*
)

file( GLOB_RECURSE
  src_util
  ${PROJECT_SOURCE_DIR}/util/*
  ${PROJECT_INCLUDE_DIR}/util/*
)

add_library(
    physics
    SHARED
    ${src_physics}
)

add_library(
    main
    SHARED
    ${src_main}
  )

add_library(
    managment
    SHARED
    ${src_managment}
  )

add_library(
    ship
    SHARED
    ${src_ship}
  )

add_library(
    simulation
    SHARED
    ${src_simulation}
  )

add_library(
    util
    SHARED
    ${src_util}
  )

add_executable(
  program
  ${src_main}
  ${src_managment}
  ${src_ship}
  ${src_physics}
  ${src_simulation}
  ${src_util}
)
