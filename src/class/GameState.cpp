// -*- compile-command: "./compile.sh"; -*-
// GameState.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/GameState.h"

GameState::GameState()
    :_current_acceleration(0), _current_speed(0), _current_time(0), _traveled_distance(0)
{
  std::cout << "Create game state" << "\n";
}

GameState::~GameState(){}

Distance GameState::get_distance() const{
  return _traveled_distance;
}

Speed GameState::get_speed() const{
  return _current_speed;
}

Acceleration GameState::get_acceleration() const{
  return _current_acceleration;
}

Time GameState::get_time() const{
  return _current_time;
}

// Setters
void GameState::add_distance(Distance distance){
  _traveled_distance += distance;
}

void GameState::add_speed(Speed speed){
  _current_speed += speed;
}

void GameState::increase_acceleration(Acceleration acceleration){
  _current_acceleration += acceleration;
}

void GameState::increase_time(Time time){
  std::cout << "Increase time by " << time.get_numerical_value()  << "\n";
  _current_time += time;

  std::cout << "Time is now " << _current_time.get_numerical_value()  << "\n";
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
