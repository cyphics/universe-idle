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
  Physics::Acceleration _current_acceleration;
  Physics::Speed _current_speed;
  Physics::Time _current_time;
  Physics::Distance _traveled_distance;

 public:
  GameState();
  ~GameState();
  // Getters
  const Physics::Distance& get_distance() const;
  const Physics::Speed& get_speed() const;
  const Physics::Acceleration& get_acceleration() const;
  const Physics::Time& get_time() const;

  // Setters
  void set_distance(Physics::Distance distance);
  void add_distance(Physics::Distance distance);
  void set_speed(Physics::Speed speed);
  void set_unit(Physics::DistanceUnit unit);
  void add_speed(Physics::Speed speed);
  void set_acceleration(Physics::Acceleration acceleration);
  void increase_time(Physics::Time time);
};

#endif // GAMESTATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
