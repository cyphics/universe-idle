#include "../include/helpers/run_simulator.h"
#include "../include/class/BigNum.h"
#include "../include/class/Upgrade.h"
#include "../include/helpers/upgrades_helper.h"

int main(int argc, char *argv[])
{

  Time duration(200);
  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
