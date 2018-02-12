// GameController.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H 1

#include <QApplication>
#include "Game.h"
#include "physics/Time.h"

using Physics::Time;

class GameController : public QObject
{
  Q_OBJECT
 private:
  Game *_my_game;

public:
  GameController(Game *game);
  ~GameController();
  void receive_data(std::string);
  void update();
 public slots:
  void wait(Time time);
  void click();

 signals:
  void send_data(QString);

  const Game& get_game() const;

  void acceleration(std::string value);

};


#endif // _H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
