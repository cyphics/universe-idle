#include "simulation/run_simulator.h"
#include "util/BigNum.h"
#include "ship/Upgrade.h"
#include "ship/upgrades_helper.h"
int main(int argc, char *argv[])
{

  Physics::Time a(0.1);

  std::cout << a.to_string()  << "\n";

  std::cout << BigNum(0.1)  << "\n";

  // BigNum a(100);
  // BigNum b(1000);
  // BigNum c(10000);
  // BigNum d(30.5912);
  // std::cout << a  << "\n";
  // std::cout << b  << "\n";
  // std::cout << c  << "\n";
  // std::cout << d  << "\n";
  // //
  Physics::Time duration(1000);
  //run_simulator(duration, Strategy_ID::broken);

  std::string aa;

  //  std::cin >> aa;

  return 0;
}
