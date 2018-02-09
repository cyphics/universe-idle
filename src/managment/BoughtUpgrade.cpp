// BoughtUpgrade.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "managment/BoughtUpgrade.h"
#include "ship/UpgradesList.h"
#include "main/game_global_variables.h"

using Physics::Time;

BoughtUpgrade::BoughtUpgrade(Upgrade_ID upgrade_id, Time time_when_bought, Price cost, int amount_bought)
    : _upgrade_type(upgrade_id), _time(time_when_bought), _cost(cost), _number_bought(amount_bought)
{}

BoughtUpgrade::BoughtUpgrade(Upgrade_ID upgrade_id, Time time_when_bought, Price cost)
    : _upgrade_type(upgrade_id), _time(time_when_bought), _cost(cost), _number_bought(1)
{}

BoughtUpgrade::~BoughtUpgrade(){}


std::string BoughtUpgrade::to_string() const
{
  std::string output = "";

  int time_box_size = 26;
  int upgrade_box_size = 25;
  int price_box_size = 25;
  int offset = 0;
  std::string time_string = _time.to_string();
  std::string cost_string = _cost.to_string();
  std::string upgrade_string = global::upgrade_name(_upgrade_type);

  // Print time
  output += "|" + time_string;
  offset = time_box_size - time_string.size();
  for (int i = 0; i < offset; i++)
  {
    output += " ";
  }

  // print upgrade
  output += "|" + upgrade_string;
  offset = upgrade_box_size - upgrade_string.size();
  for (int i = 0; i < offset; i++)
  {
    output += " ";
  }

  // Print price
  output += "|" + cost_string;
  offset = price_box_size - cost_string.size();
  for (int i = 0; i < offset; i++)
  {
    output += " ";
  }
  output += "|";



  return output;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
