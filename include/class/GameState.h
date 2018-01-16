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
#include "Time.h"
#include "Speed.h"
#include "Distance.h"
#include "Acceleration.h"

class GameState{
 private:
  Distance _traveled_distance;
  Speed _current_speed;
  Acceleration _current_acceleration;
  Time _current_time;

 public:
  GameState();
  ~GameState();
  // Getters
  Distance get_distance() const;
  Speed get_speed() const;
  Acceleration get_acceleration() const;
  Time get_time() const;

  // Setters
  void set_distance(Distance distance);
  void set_speed(Speed speed);
  void set_acceleration(Acceleration acceleration);
  void increase_time(Time time);
};

#endif // GAMESTATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
