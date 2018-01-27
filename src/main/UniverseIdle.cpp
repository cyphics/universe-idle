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
}

UniverseIdle::~UniverseIdle(){}

void UniverseIdle::run()
{

  Game my_game;
  GameGui a_gui;
  QTimer timer;
  a_gui.set_game(&my_game);
  a_gui.show();
  QObject::connect(&timer, SIGNAL(timeout()), &a_gui, SLOT(update()));
  timer.start(200);
  //a_gui.update();
  QApplication::instance()->exec();

}

  //GameController controller(&my_game);

  // QMainWindow *window = new QMainWindow;
//   Ui::UniverseIdleMainWindow ui;
//   ui.setupUi(window);

//   //connect(controller, ui);
//   QObject::connect(ui.clickButton, &QPushButton::clicked, &controller, &GameController::click);
//   QObject::connect(&controller, &GameController::send_data, ui.acceleration_value_label, &QLabel::setText);

//   //QObject::connect(&controller, &GameController::send_data, &ui, &Ui::UniverseIdleMainWindow::acceleration_value_label);

//   window->show();
//   QApplication::instance()->exec();
// }
// }


//void UniverseIdle::connect(GameController& controller, Ui::UniverseIdleMainWindow& ui)
//{

  //QObject::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *member)

//}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
