// UniverseIdle.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "main/UniverseIdle.h"
#include "gui/ui_UniverseIdleGUI.h"

UniverseIdle::UniverseIdle(){
  _gui.setupUi(&_window);
}

UniverseIdle::~UniverseIdle(){}

int UniverseIdle::run()
{
  _game.buy_upgrade(Upgrade_ID::small_boost, 1);
  Game my_game;
  my_game.buy_upgrade(Upgrade_ID::small_boost, 1);
  sf::Time tick = sf::seconds(0.2);
  sf::Time elapsed;

  // Run GUI
  QMainWindow *window = new QMainWindow;
  Ui::UniverseIdleMainWindow ui;
  ui.setupUi(window);

  window->show();

  return QApplication::instance()->exec();

}



//////////////////////////////////////////////////////////////////////
// $Log:$
//
