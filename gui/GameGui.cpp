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
#include "UpgradeBox.h"
#include "ship/computations.h"
#include "main/game_configuration.h"

using Physics::Time;
using Ui::toqstr;


// Constructor
GameGui::GameGui(Game* game, QMainWindow *parent)
    : _game(game), QMainWindow(parent)
{
  ui.setupUi(this);
  _timer = new QTimer(this);

  build_upgrade_boxes_vector();
  set_upgrade_boxes();
  ui.textBrowser->append(Ui::toqstr(GameConfig::Message::greeting_message));

  // Initiate visibility
  update_ugprade_boxes_visibility();

}

void GameGui::build_upgrade_boxes_vector()
{
   for (auto upgrade_id : _game->upgrades()->get_all_upgrades())
   {
     UpgradeBox *a_box = new UpgradeBox(upgrade_id, _game);

     if (_game->upgrades()->is_unique(upgrade_id))
     {
       _unique_upgrade_boxes.push_back(a_box);
     }
     else
     {
       _increm_upgrade_boxes.push_back(a_box);
     }
   }
}


void GameGui::set_upgrade_boxes(){

  for (auto &box : _unique_upgrade_boxes)
  {
    // Add box to GUI
    ui.verticalLayout_3->addWidget(box);
    // Set connection
    connect(box, SIGNAL( button_pressed(Upgrade_ID) ),
            this, SLOT(upgrade_bought(Upgrade_ID)));
  }

  for (auto &box : _increm_upgrade_boxes)
  {
    // Add box to GUI
    ui.verticalLayout1->addWidget(box);
    // Set connection
    connect(box, SIGNAL( button_pressed(Upgrade_ID) ),
            this, SLOT(upgrade_bought(Upgrade_ID)));
  }
}

void GameGui::update_upgrade_boxes()
{
  for (auto &box : _unique_upgrade_boxes) {
    if (box->isEnabled()) {
      box->update_box(_game);
    }
  }
  for (auto &box : _increm_upgrade_boxes) {
    if (box->isEnabled()) {
      box->update_box(_game);
    }
  }
}

void GameGui::update()
{
  // Increment game state
  _game->wait(Time(0.2));

  // Get new values
  // CURRENT ACCELERATION
  _acceleration_value = toqstr(_game->state().get_acceleration().to_string());

  // CURRENT ENERGY
  _kinetic_energy_value = toqstr(_game->resources()->get_resource_amount(Resource_ID::kinetic_energy).to_string());

  // CURRENT SPEED
  _speed_value = toqstr(_game->state().get_speed().to_string());

  // Time until destination
  _remaining_time_value = toqstr(_game->compute().time_until_destination(GameConfig::final_destination).to_string());

  // Traveled distance
  _distance_value = toqstr(_game->state().get_distance().to_string());

  // Set new values in UI
  ui.acceleration_value_label->setText(_acceleration_value);
  ui.time_value_label->setText(_remaining_time_value);
  ui.speed_value_label->setText(_speed_value);
  ui.distance_value_label->setText(_distance_value);


  QString kin_energy_label = _kinetic_energy_value +\
                             " (" +\
                             Ui::toqstr( _game->compute().resource_per_second(Resource_ID::kinetic_energy).to_string()) +\
                             "/s)";
  ui.kinetic_energy_value_label->setText(kin_energy_label);

  update_upgrade_boxes();

}

void GameGui::on_click_button_clicked()
{
  _game->click();
}




void GameGui::upgrade_bought(Upgrade_ID id)
{
  if (id == Upgrade_ID::u_terminal)
  {
    ui.textBrowser->append(Ui::toqstr(GameConfig::Message::terminal_message));
  }
  else if (id == Upgrade_ID::u_quantum_magnet)
  {
    ui.textBrowser->append(Ui::toqstr(GameConfig::Message::coil_message));
  }
  else if (id == Upgrade_ID::i_quant_coil && _game->upgrades()->get_upgrade_level(Upgrade_ID::i_quant_coil) == 1)
  {
    ui.textBrowser->append(Ui::toqstr(GameConfig::Message::first_coil_message));
  }
  else if (id == Upgrade_ID::u_level_a_boost)  {
    ui.textBrowser->append(Ui::toqstr(GameConfig::Message::level_A_booster_message));
  }
  _game->buy_upgrade(id, 1);
  update_ugprade_boxes_visibility();
}

void GameGui::update_ugprade_boxes_visibility()
{
  for (auto box : _unique_upgrade_boxes) {
    if (_game->upgrades()->is_available(box->get_id()))
      box->set_box_visibility(true);
    else
      box->set_box_visibility(false);
  }
  for (auto box : _increm_upgrade_boxes) {
    if (_game->upgrades()->is_available(box->get_id()))
      box->set_box_visibility(true);
    else
      box->set_box_visibility(false);
  }

}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
