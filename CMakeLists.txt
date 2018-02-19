cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

project(universe_idle)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})

# QT
# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

include_directories(include/)
include_directories(gui/)
include_directories(build/gui_lib_autogen/include)

set(
  APP_SRC
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
  src/physics/constant_distances.cpp
  src/ship/Price.cpp
  src/ship/Resource.cpp
  src/ship/ResourcesManager.cpp
  src/ship/Upgrade.cpp
  src/ship/Computer.cpp
  src/ship/UpgradeManager.cpp
  src/simulation/run_simulator.cpp
  src/simulation/Simulate_game.cpp
  src/simulation/Strategy.cpp
  src/util/BigNum.cpp
  )


# build app library
add_library(app_lib ${APP_SRC}
  )

set(
  GUI_SRC
  gui/GameGui.cpp
  gui/UpgradeBox.cpp
  gui/gui_helpers.cpp
  src/physics/compute_physics.cpp
  )

add_library(gui_lib ${GUI_SRC})

# build main exec against lib
add_executable( program src/main.cpp   src/main/UniverseIdle.cpp
)

#target_link_libraries(program PRIVATE app_lib)
target_link_libraries(
  program
  PRIVATE
  app_lib
  gui_lib
  )

target_link_libraries(gui_lib PUBLIC Qt5::Widgets)

enable_testing()
add_subdirectory(test EXCLUDE_FROM_ALL)
