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

#include "BigNum.h"
#include "Time.h"

class GameState{
 private:
  BigNum _traveled_distance;
  BigNum _current_speed;
  BigNum _current_acceleration;
  Time _current_time;

 public:
  // Getters
  BigNum get_distance() const;
  BigNum get_speed() const;
  BigNum get_acceleration() const;
  Time get_time() const;

  // Setters
  void add_distance(BigNum distance);
  void add_speed(BigNum speed);
  void increase_acceleration(BigNum acceleration);
  void increase_time(Time time);
};

#endif // GAMESTATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
