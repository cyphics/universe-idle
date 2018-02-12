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
   for (auto upgrade_id : _game->manage_upgrades()->get_all_upgrades())
   {
     UpgradeBox *a_box = new UpgradeBox(upgrade_id, _game);

     if (_game->manage_upgrades()->is_unique(upgrade_id))
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
    box->update_box(_game->manage_upgrades());
  }
  for (auto &box : _increm_upgrade_boxes) {
    box->update_box(_game->manage_upgrades());
  }
}

void GameGui::update()
{
  // Increment game state
  _game->wait(Time(0.2));

  // Get new values
  _acceleration_value = toqstr(_game->state().get_acceleration().to_string());

  _cinetic_energy_value = toqstr(_game->manage_resources()->get_resource_amount(Resource_ID::cinetic_energy).to_string());
  _speed_value = toqstr(_game->state().get_speed().to_string());
  _remaining_time_value = toqstr(compute_remaining_time(Units::diameter_universe, _game->state().get_speed(), _game->state().get_acceleration()).to_string());
  _distance_value = toqstr(_game->state().get_distance().to_string());

  // Set new values in UI
  ui.acceleration_value_label->setText(_acceleration_value);
  ui.cinetic_energy_value_label->setText(_cinetic_energy_value);
  ui.time_value_label->setText(_remaining_time_value);
  ui.speed_value_label->setText(_speed_value);
  ui.distance_value_label->setText(_distance_value);

  update_upgrade_boxes();

}

void GameGui::on_click_button_clicked()
{
  _game->click();
}




void GameGui::upgrade_bought(Upgrade_ID id)
{
  _game->buy_upgrade(id, 1);
  update_ugprade_boxes_visibility();
}

void GameGui::update_ugprade_boxes_visibility()
{
  for (auto box : _unique_upgrade_boxes) {
    if (_game->manage_upgrades()->is_available(box->get_id()))
      box->set_box_visibility(true);
    else
      box->set_box_visibility(false);
  }
  for (auto box : _increm_upgrade_boxes) {
    if (_game->manage_upgrades()->is_available(box->get_id()))
      box->set_box_visibility(true);
    else
      box->set_box_visibility(false);
  }

}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
