#include "QApplication"
#include "simulation/run_simulator.h"
#include "main/UniverseIdle.h"
#include "physics/Speed.h"
#include "physics/Distance.h"
#include "physics/constant_distances.h"
#include "main/game_configuration.h"

int main(int argc, char *argv[])
{

  // Physics::Speed speed(1, Physics::DistanceUnit::meter);

  // std::cout << speed.to_string()  << "\n";

  // speed.set_unit(Physics::DistanceUnit::femtometer);

  // std::cout << speed.to_string()  << "\n";

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

    return 0;
}
