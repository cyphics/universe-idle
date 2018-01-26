cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

project(universe_idle)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})

# QT
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

find_package(SFML 2 REQUIRED network audio graphics window system)

include_directories(include/)

set(
  SOURCES
  src/main/Game.cpp
  src/main/GameController.cpp
  src/main/UniverseIdle.cpp
  src/main/game_global_variables.cpp
  src/main/Initiate.cpp
  src/managment/BoughtUpgrade.cpp
  src/managment/GameState.cpp
  src/managment/History.cpp
  src/physics/Acceleration.cpp
  src/physics/compute_physics.cpp
  src/physics/Distance.cpp
  src/physics/PhysicalUnit.cpp
  src/physics/Speed.cpp
  src/physics/Time.cpp
  src/ship/computations.cpp
  src/ship/Price.cpp
  src/ship/Resource.cpp
  src/ship/ResourcesManager.cpp
  src/ship/Upgrade.cpp
  src/ship/UpgradeManager.cpp
  src/simulation/run_simulator.cpp
  src/simulation/Simulate_game.cpp
  src/simulation/Strategy.cpp
  src/util/BigNum.cpp
  )


# build app library
add_library(app_lib ${SOURCES})

# build main exec against lib

add_executable( program src/main.cpp )

#target_link_libraries(program PRIVATE app_lib)
target_link_libraries(
  program
  PRIVATE
  app_lib
  ${SFML_LIBRARIES}
  ${SFML_DEPENDENCIES}
  )
target_link_libraries(app_lib PUBLIC Qt5::Widgets)


enable_testing()
add_subdirectory(test EXCLUDE_FROM_ALL)
# Use the Widgets module from Qt 5.
# target_link_libraries(program Qt5::Widgets)
