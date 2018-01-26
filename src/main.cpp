#include <QApplication>
#include <SFML/Graphics.hpp>


#include "simulation/run_simulator.h"
#include "util/BigNum.h"
#include "ship/Upgrade.h"
#include "ship/upgrades_helper.h"
#include "physics/constants_physics.h"
#include "physics/compute_physics.h"
#include "physics/Distance.h"
//#include "gui/FenPrincipale.h"
//#include "gui/GameGui.h"
#include "main/Game.h"
#include "main/UniverseIdle.h"
#include "gui/ui_UniverseIdleGUI.h"

//#include "gui/FenPrincipale.h"

using Physics::Distance;

int main(int argc, char *argv[])
{

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
