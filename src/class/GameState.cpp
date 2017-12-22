// -*- compile-command: "./compile.sh"; -*-
// GameState.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/GameState.h"

BigNum GameState::get_distance() const{
  return _traveled_distance;
}

BigNum GameState::get_speed() const{
  return _current_speed;
}

BigNum GameState::get_acceleration() const{
  return _current_acceleration;
}

Time GameState::get_time() const{
  return _current_time;
}

// Setters
void GameState::add_distance(BigNum distance){
  _traveled_distance += distance;
}

void GameState::add_speed(BigNum speed){
  _current_speed += speed;
}

void GameState::increase_acceleration(BigNum acceleration){
  _current_acceleration += acceleration;
}

void GameState::increase_time(Time time){
  //_current_time += time;
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
