// GameGui.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "GameGui.h"
#include "physics/Time.h"
#include "physics/compute_physics.h"
#include "physics/constants_physics.h"
using Physics::Time;

GameGui::GameGui(QMainWindow *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);
  _timer = new QTimer(this);

}

void GameGui::set_game(Game* game)
{
  _game = game;
}

void GameGui::update()
{
  _game->wait(Time(0.2));

  _acceleration_value = QString::fromStdString(_game->state().get_acceleration().to_string());
  _cinetic_energy_value = QString::fromStdString(_game->manage_resources()->get_resource_amount(Resource_ID::cinetic_energy).to_string());
  _speed_value = QString::fromStdString(_game->state().get_speed().to_string());
  //_remaining_time_value = QString::fromStdString(_game->state().get_time().to_string());
  _remaining_time_value = QString::fromStdString(compute_remaining_time(Units::diameter_universe, _game->state().get_speed(), _game->state().get_acceleration()).to_string());

  _distance_value = QString::fromStdString(_game->state().get_distance().to_string());

  ui.acceleration_value_label->setText(_acceleration_value);
  ui.cinetic_energy_value_label->setText(_cinetic_energy_value);
  ui.time_value_label->setText(_remaining_time_value);
  ui.speed_value_label->setText(_speed_value);
  ui.distance_value_label->setText(_distance_value);
}

void GameGui::on_clickButton_clicked()
{
  _game->click();
}

void GameGui::on_small_boost_button_clicked()
{
  _game->buy_upgrade(Upgrade_ID::small_boost, 1);
}

void GameGui::on_big_boost_button_clicked()
{
  _game->buy_upgrade(Upgrade_ID::big_boost, 1);
}
void GameGui::connect_all()
{

}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
