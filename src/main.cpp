// -*- compile-command: "./../compile.sh"; -*-

// #include <libhello/french.h>
// #include <libhello/english.h>
// #include <class/a_class.h>

#include <iostream>

#include "../include/Simulate_game.h"
#include "../include/Game.h"
//#include "Strategies.cpp"

int main()
{

  int duration = 1000000;

  Game game = simulate_game("cheap", duration);


  return 0;
}
