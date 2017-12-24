// -*- compile-command: "./../compile.sh"; -*-


#include "../include/helpers/run_simulator.h"
#include "../include/class/PhysicalUnit.h"

int main(int argc, char *argv[])
{

  Time duration = Time(1000000);

  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
