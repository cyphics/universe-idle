// GameGui.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef GAME_GUI_H
#define GAME_GUI_H 1


#include <QApplication>
#include <QtWidgets>
#include <QTimer>
#include "ui_UniverseIdleGUI.h"
#include "main/Game.h"
#include "UpgradeBox.h"



class GameGui : public QMainWindow
{
  Q_OBJECT

 private:
  std::vector<UpgradeBox*> _science_boxes;
  std::vector<UpgradeBox*> _upgrade_boxes;
  std::vector<UpgradeBox*> _structure_boxes;
  std::vector<UpgradeBox*> _incremental_boxes;

 public:
  explicit GameGui(Game* game, QMainWindow *parent = nullptr);
  void set_game(Game* game);
  void update_upgrade_boxes();
  void build_upgrade_boxes_vector();
  void set_upgrade_boxes();

 private slots:
  void update();
  //void on_
  void upgrade_bought(Upgrade_ID id);
  void on_click_button_clicked();
  //void change_speed_unit(Physics::DistanceUnit unit);
  void change_speed_unit(QString string);

private:
  void update_ugprade_boxes_visibility();
  void update_update_box(QWidget* widget, Upgrade_ID upgrade_id);
  void update_button(QPushButton* button, Upgrade_ID upgrade_id);
  QString _boost_1_button_name;
  QString _kinetic_button_name;
  QString _acceleration_value;
  QString _kinetic_energy_value;
  QString _speed_value;
  QString _distance_value;
  QString _remaining_time_value;
  void fill_combo_box(QComboBox* box);

  QTimer *_timer;

  Ui::UniverseIdleMainWindow ui;
  Game* _game;
};


#endif // _H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
