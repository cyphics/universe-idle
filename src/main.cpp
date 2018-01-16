#include "../include/helpers/run_simulator.h"
#include "../include/class/BigNum.h"
#include "../include/class/Upgrade.h"
#include "../include/helpers/upgrades_helper.h"

int main(int argc, char *argv[])
{

  UpgradeCostTableElement a_cost;
  a_cost.initial_cost = BigNum(10);
  a_cost.resource = Resource_ID::cinetic_energy;

  std::vector<UpgradeCostTableElement> list_of_cost;
  list_of_cost.push_back(a_cost);
  Upgrade an_upgrade = Upgrade(Upgrade_ID::small_boost, list_of_cost, 1.2);

  std::cout << an_upgrade.get_cost_given_level(1).to_string()  << "\n";
  Time duration(40);
  run_simulator(duration, Strategy_ID::broken);

  return 0;
}
