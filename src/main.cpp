// -*- compile-command: "./../compile.sh"; -*-

#include "../include/helpers/Simulate_game.h"
#include "../include/class/Game.h"
//#include "../include/helpers/Strategy.h"
int main()
{

  int duration = 1000000;

  Game game = simulate_game(Strategy_ID::broken, duration);


  return 0;
}
