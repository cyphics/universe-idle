#include "QApplication"
#include "simulation/run_simulator.h"
#include "main/UniverseIdle.h"


int main(int argc, char *argv[])
{

  std::string arg = "";

  if (argc > 1) {
    arg = argv[1];
  }

  //  if (arg == "gui") {
    QApplication app(argc, argv);
    UniverseIdle universe;
    universe.run();
    return 0;
    //}

  Physics::Time duration(1000);
  run_simulator(duration, Strategy_ID::cheapest);

  //return 0;
}
