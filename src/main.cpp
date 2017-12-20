// -*- compile-command: "./../compile.sh"; -*-

#include "../include/helpers/Simulate_game.h"
#include "../include/class/Game.h"

int main()
{

  int duration = 1000000;

  Game game = simulate_game("cheap", duration);


  return 0;
}
