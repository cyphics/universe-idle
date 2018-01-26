// UniverseIdle.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "main/UniverseIdle.h"
#include "gui/ui_UniverseIdleGUI.h"
#include "main/GameController.h"

UniverseIdle::UniverseIdle(){
  _gui.setupUi(&_window);
}

UniverseIdle::~UniverseIdle(){}

void UniverseIdle::run()
{

  Game my_game;

  GameController controller(&my_game);

  QMainWindow *window = new QMainWindow;
  Ui::UniverseIdleMainWindow ui;
  ui.setupUi(window);

  connect(controller, ui);

  window->show();
  QApplication::instance()->exec();
}

void UniverseIdle::connect(GameController& controller, Ui::UniverseIdleMainWindow& ui)
{
  QObject::connect(ui.clickButton, &QPushButton::clicked, &controller, &GameController::click);
  // QObject::connect(controller, &GameController::updateStuff, ui, &Ui::UniverseIdleMainWindow::update);
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
