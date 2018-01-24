cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

project(universe_idle)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})

# Find the QtWidgets library
find_package(Qt5Widgets)

include_directories(include/)

file( GLOB_RECURSE
  SOURCES
  src/*
  include/*
)

file( GLOB_RECURSE
  TEST_SOURCES
  test/*
)

# build app library
add_library(app_lib ${SOURCES})

# build main exec against lib
set(MAIN src/main.cpp)
add_executable( program ${MAIN} )
target_link_libraries(program PRIVATE app_lib Qt5::Widgets)

# build test exec against lib
add_executable(test_app ${TEST_SOURCES})
target_link_libraries(test_app PRIVATE app_lib)

# Use the Widgets module from Qt 5.
# target_link_libraries(program Qt5::Widgets)