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
#include "gui_helpers.h"

using Physics::Time;
using Ui::toqstr;

GameGui::GameGui(QMainWindow *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);
  _timer = new QTimer(this);
  _boost_1_button_name = toqstr(_game->manage_upgrades()->get_upgrade_name(Upgrade_ID::boost_1));

}

void GameGui::set_game(Game* game)
{
  _game = game;
}

void GameGui::update()
{
  // Increment game state
  _game->wait(Time(0.2));

  // Update data values
  _acceleration_value = toqstr(_game->state().get_acceleration().to_string());
  _cinetic_energy_value = toqstr(_game->manage_resources()->get_resource_amount(Resource_ID::cinetic_energy).to_string());
  _speed_value = toqstr(_game->state().get_speed().to_string());
  //_remaining_time_value = toqstr(_game->state().get_time().to_string());
  _remaining_time_value = toqstr(compute_remaining_time(Units::diameter_universe, _game->state().get_speed(), _game->state().get_acceleration()).to_string());

  _distance_value = toqstr(_game->state().get_distance().to_string());


  // Set new values in UI
  ui.acceleration_value_label->setText(_acceleration_value);
  ui.cinetic_energy_value_label->setText(_cinetic_energy_value);
  ui.time_value_label->setText(_remaining_time_value);
  ui.speed_value_label->setText(_speed_value);
  ui.distance_value_label->setText(_distance_value);

  // Adapt button's names
  update_button(ui.boost_1_button, Upgrade_ID::boost_1);
  ui.boost_1_price->setText(toqstr(_game->manage_upgrades()->get_price_increase_level(Upgrade_ID::boost_1, 1).to_string()));
  ui.boost_1_remaining_time->setText(toqstr(_game->manage_upgrades()->time_until_affordable(Upgrade_ID::boost_1, 1).to_string()));

  update_button(ui.boost_2_button, Upgrade_ID::boost_2);
  ui.boost_2_price->setText(toqstr(_game->manage_upgrades()->get_price_increase_level(Upgrade_ID::boost_2, 1).to_string()));
  ui.boost_2_remaining_time->setText(toqstr(_game->manage_upgrades()->time_until_affordable(Upgrade_ID::boost_2, 1).to_string()));

}

void GameGui::on_clickButton_clicked()
{
  _game->click();
}

void GameGui::on_boost_1_button_clicked()
{
  _game->buy_upgrade(Upgrade_ID::boost_1, 1);
}

void GameGui::on_boost_2_button_clicked()
{
  _game->buy_upgrade(Upgrade_ID::boost_2, 1);
}


void GameGui::update_button(QPushButton* button, Upgrade_ID upgrade_id)
{

  // Set name
  QString new_name = toqstr(_game->manage_upgrades()->get_upgrade_name(upgrade_id));
  int level = _game->manage_upgrades()->get_upgrade_level(upgrade_id);

  if (level > 0) {
    new_name += " (";
    new_name += QString::number(level);
    new_name += ")";
  }

  button->setText(new_name);

  // Set availability

  if (_game->manage_upgrades()->is_affordable(upgrade_id, 1))
  {
    button->setEnabled(true);
  }
  else button->setDisabled(true);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
