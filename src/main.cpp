// -*- compile-command: "./../compile.sh"; -*-


#include "../include/helpers/run_simulator.h"

int main()
{

  Time duration = Time(0);


  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
