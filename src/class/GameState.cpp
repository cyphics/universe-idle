// -*- compile-command: "./compile.sh"; -*-
// GameState.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/GameState.h"

using Physics::Time;
using Physics::Distance;
using Physics::Speed;
using Physics::Acceleration;

GameState::GameState()
    :_current_acceleration(0), _current_speed(0), _current_time(0), _traveled_distance(0)
{}

GameState::~GameState(){}

Distance GameState::get_distance() const
{
  return _traveled_distance;
}

Speed GameState::get_speed() const
{
  return _current_speed;
}

Acceleration GameState::get_acceleration() const
{
  return _current_acceleration;
}

Time GameState::get_time() const
{
  return _current_time;
}

// Setters
void GameState::set_distance(Distance distance)
{
  _traveled_distance = distance;
}

void GameState::set_speed(Speed speed)
{
  _current_speed = speed;
}

void GameState::set_acceleration(Acceleration acceleration)
{
  _current_acceleration = acceleration;
}

void GameState::increase_time(Time time)
{
  _current_time += time;
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
