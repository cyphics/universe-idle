// GameController.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef _H
#define _H 1

#include <QApplication>
#include "Game.h"
#include "physics/Time.h"

using Physics::Time;

class GameController : public QObject
{
 private:
  Game *_my_game;

public:
  GameController(Game *game);
  ~GameController();

 public slots:
  void wait(Time time);
  void click();

 signals:

  void updateUI(std::vector<std::string> data);
  const Game& get_game() const;



};


#endif // _H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
