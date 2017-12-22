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

#include "Time.h"
class GameState{
  Time _current_time;
  Time get_time() const;

  void increase_time(Time time);
};


#endif // GAMESTATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
