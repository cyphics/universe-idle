// -*- compile-command: "./../compile.sh"; -*-


#include "../include/helpers/run_simulator.h"

int main()
{

  int duration = 100000;

  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
