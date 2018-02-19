// UniverseIdle.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "main/UniverseIdle.h"
#include "../../gui/GameGui.h"
//#include "gui/ui_UniverseIdleGUI.h"
//#include "main/GameController.h"

UniverseIdle::UniverseIdle(){
  std::cout << "Init UniverseIdle"  << "\n";
}

UniverseIdle::~UniverseIdle(){}

void UniverseIdle::run()
{

  GameGui a_gui(&_game);
  QTimer timer;
  a_gui.show();
  QObject::connect(&timer, SIGNAL(timeout()), &a_gui, SLOT(update()));
  timer.start(200);
  QApplication::instance()->exec();

}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
