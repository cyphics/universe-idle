// -*- compile-command: "./../compile.sh"; -*-
// GameState.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef GAMESTATE_H
#define GAMESTATE_H 1

//#include "BigNum.h"
#include "physics/Time.h"
#include "physics/Speed.h"
#include "physics/Distance.h"
#include "physics/Acceleration.h"


class GameState{
 private:
  Physics::Distance _traveled_distance;
  Physics::Speed _current_speed;
  Physics::Acceleration _current_acceleration;
  Physics::Time _current_time;

 public:
  GameState();
  ~GameState();
  // Getters
  Physics::Distance get_distance() const;
  Physics::Speed get_speed() const;
  Physics::Acceleration get_acceleration() const;
  Physics::Time get_time() const;

  // Setters
  void set_distance(Physics::Distance distance);
  void set_speed(Physics::Speed speed);
  void set_acceleration(Physics::Acceleration acceleration);
  void increase_time(Physics::Time time);
};

#endif // GAMESTATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
