// UniverseIdle.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UNIVERSEIDLE_H
#define UNIVERSEIDLE_H 1

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include "Game.h"
//#include "GameController.h"

class UniverseIdle
{
 private:
  Game _game;
  QMainWindow _window;


 public:
  UniverseIdle();
  ~UniverseIdle();
  void run();
  //void connect(GameController& controller, Ui::UniverseIdleMainWindow& ui);


};


#endif // UNIVERSEIDLE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
