#include "QApplication"
#include "simulation/run_simulator.h"
#include "util/BigNum.h"
#include "ship/Upgrade.h"
#include "ship/upgrades_helper.h"
#include "physics/constants_physics.h"
#include "physics/compute_physics.h"
#include "main/Game.h"
#include "main/UniverseIdle.h"



int main(int argc, char *argv[])
{

  Time time = compute_remaining_time(Units::diameter_universe, Speed(1), Acceleration(1));


  std::cout << time.to_string()  << "\n";

  if (std::string(argv[1]) == "gui") {
    QApplication app(argc, argv);
    UniverseIdle universe;
    universe.run();
    return 0;
  }

  Physics::Time duration(1000);
  run_simulator(duration, Strategy_ID::cheapest);

  return 0;
}
