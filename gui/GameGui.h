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
#include <QtWidgets>
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
  void on_click_button_clicked();
  void on_boost_1_button_clicked();
  void on_boost_2_button_clicked();
  void on_boost_3_button_clicked();
  void on_boost_4_button_clicked();
private:
  void update_update_box(QWidget* widget, Upgrade_ID upgrade_id);
  void update_button(QPushButton* button, Upgrade_ID upgrade_id);
  QString _boost_1_button_name;
  QString _cinetic_button_name;
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
