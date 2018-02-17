#include "QApplication"
#include "simulation/run_simulator.h"
#include "main/UniverseIdle.h"
#include "physics/Speed.h"
#include "physics/Distance.h"
#include "physics/constant_distances.h"
#include "main/game_configuration.h"

int main(int argc, char *argv[])
{


  Physics::Distance dist(BigNum(12), Physics::DistanceUnit::astro_unit);
  std::cout << dist.to_string()  << "\n";
  std::string arg = "";

  if (argc > 1) {
    arg = argv[1];
  }

    if (arg == "gui") {
    QApplication app(argc, argv);
    UniverseIdle universe;
    universe.run();
    return 0;
    }

    Physics::Time duration(1000);
  run_simulator(duration, Strategy_ID::cheapest);

  //return 0;
}
