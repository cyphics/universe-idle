// UniverseIdle.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UNIVERSEIDLE_H
#define UNIVERSEIDLE_H 1

#include "Game.h"
#include "gui/ui_UniverseIdleGUI.h"
#include "GameController.h"

class UniverseIdle
{
 private:
  Game _game;
  //sf::Time _timer;
  //sf::Clock _clock;
  Ui::UniverseIdleMainWindow _gui;
  QMainWindow _window;


 public:
  UniverseIdle();
  ~UniverseIdle();
  void run();
  void connect(GameController& controller, Ui::UniverseIdleMainWindow& ui);


};


#endif // UNIVERSEIDLE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
