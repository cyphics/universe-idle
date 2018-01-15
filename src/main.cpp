// -*- compile-command: "./../compile.sh"; -*-


#include "../include/helpers/run_simulator.h"
#include "../include/class/BigNum.h"

int main(int argc, char *argv[])
{

  BigNum a = BigNum(1);
  BigNum b(200.2242434951);
  a += b;

  std::cout << a  << "\n";

  //  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
