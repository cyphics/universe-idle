#include <QApplication>


#include "simulation/run_simulator.h"
#include "util/BigNum.h"
#include "ship/Upgrade.h"
#include "ship/upgrades_helper.h"
#include "physics/constants_physics.h"
#include "physics/compute_physics.h"
#include "physics/Distance.h"
//#include "gui/FenPrincipale.h"
#include "gui/GameGui.h"

//#include "gui/FenPrincipale.h"

using Physics::Distance;

int main(int argc, char *argv[])
{


  QApplication app(argc, argv);
  Ui::MainWindow main_window;
  QMainWindow a_window;

  main_window.setupUi(&a_window);
  a_window.show();
  // FenPrincipale fenetre;
  // fenetre.show();

  return app.exec();

  Time c_time = compute_remaining_time(Physics::Units::diameter_universe, Speed(BigNum(1, 0)), Acceleration(BigNum(1, 0)));
  std::cout << "c_time: " << c_time.to_string()  << "\n";
  //Physics::Time duration(1000);
  //run_simulator(duration, Strategy_ID::broken);

  return 0;
}
// 52632154.556140 galactic years
