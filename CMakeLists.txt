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

include_directories(include/)

set(
  SOURCES
  src/main/Game.cpp
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
  src/ship/ResourcesList.cpp
  src/ship/ResourcesManager.cpp
  src/ship/Upgrade.cpp
  src/ship/UpgradeManager.cpp
  src/ship/UpgradesList.cpp
  src/simulation/run_simulator.cpp
  src/simulation/Simulate_game.cpp
  src/simulation/Strategy.cpp
  src/util/BigNum.cpp
  src/gui/FenCodeGenere.cpp
  src/gui/FenPrincipale.cpp
  )

set(
  HEADERS
  include/main/Game.h
  include/main/game_global_variables.h
  include/main/initiate.h
  include/managment/BoughtUpgrade.h
  include/managment/GameState.h
  include/managment/History.h
  include/physics/Acceleration.h
  include/physics/compute_physics.h
  include/physics/constants_physics.h
  include/physics/Distance.h
  include/physics/PhysicalUnit.h
  include/physics/Speed.h
  include/physics/Time.h
  include/ship/computations.h
  include/ship/Price.h
  include/ship/Resource.h
  include/ship/ResourcesList.h
  include/ship/ResourcesManager.h
  include/ship/resources_helper.h
  include/ship/Upgrade.h
  include/ship/UpgradesManager.h
  include/ship/UpgradesList.h
  include/ship/upgrades_helper
  include/simulation/run_simulator.h
  include/simulation/Simulate_game.h
  include/simulation/Strategy.h
  include/util/BigNum.h
  include/gui/FenCodeGenere.h
  include/gui/FenPrincipale.h
  )

file( GLOB_RECURSE
  TEST_SOURCES
  test/*
)

# build app library
add_library(app_lib ${SOURCES} ${HEADERS})

# build main exec against lib

add_executable( program src/main.cpp )
#target_link_libraries(program PRIVATE app_lib)
target_link_libraries(program PRIVATE app_lib Qt5::Widgets)
target_link_libraries(app_lib Qt5::Widgets)


# build test exec against lib
add_executable(test_app ${TEST_SOURCES})
target_link_libraries(test_app PRIVATE app_lib)

# Use the Widgets module from Qt 5.
# target_link_libraries(program Qt5::Widgets)