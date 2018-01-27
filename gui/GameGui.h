// GameGui.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef _H
#define _H 1


#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_UniverseIdleGUI.h"
#include "main/Game.h"



class GameGui : public QMainWindow
{
  Q_OBJECT

 public:
  explicit GameGui(QMainWindow *parent = nullptr);
  void set_game(Game* game);

 private slots:
  void update();
  //void on_
  void on_clickButton_clicked();
  void on_small_boost_button_clicked();
  void on_big_boost_button_clicked();
private:
  void connect_all();
  QString _acceleration_value;
  QString _cinetic_energy_value;
  QString _speed_value;
  QString _distance_value;
  QString _remaining_time_value;

  QTimer *_timer;

  Ui::UniverseIdleMainWindow ui;
  Game* _game;
};


#endif // _H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
