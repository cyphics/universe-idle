// -*- compile-command: "./../compile.sh"; -*-


#include "../include/helpers/run_simulator.h"

int main()
{

  Time duration;


  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
