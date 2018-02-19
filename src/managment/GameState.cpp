// -*- compile-command: "./compile.sh"; -*-
// GameState.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "managment/GameState.h"

using Physics::Time;
using Physics::Distance;
using Physics::Speed;
using Physics::Acceleration;

GameState::GameState()
    :_current_acceleration(0), _current_speed(0), _current_time(0), _traveled_distance(0)
{
  std::cout << "Build game state!"  << "\n";
}

GameState::~GameState(){}

const Distance& GameState::get_distance() const
{
  return _traveled_distance;
}

const Speed& GameState::get_speed() const
{
  return _current_speed;
}

const Acceleration& GameState::get_acceleration() const
{
  return _current_acceleration;
}

const Time& GameState::get_time() const
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

void GameState::add_speed(Speed speed)
{
  _current_speed += speed;
}

void GameState::set_acceleration(Acceleration acceleration)
{
  _current_acceleration = acceleration;
}

void GameState::increase_time(Time time)
{
  _current_time += time;
}

void GameState::add_distance(Physics::Distance dist)
{
  _traveled_distance += dist;
}

void GameState::set_speed_unit(Physics::DistanceUnit unit)
{
  _current_speed.set_unit(unit);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
