// History.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

//#include <vector>
//#include <algorithm>
#include "../../include/class/History.h"
#include "../../include/helpers/game_global_variables.h"

using Physics::Time;

History::History()
{

}

History::~History(){}


std::string History::to_string() const
{
  /**
   * Formats the history into a printable string
   */


  std::string history_output = "Game history :\n";

  for (auto purchase : _history)
  {
    // purchase is of type BoughtUpgrade
    history_output += purchase.to_string();
    history_output += "\n";
  }
  return history_output;
}

void History::add_upgrade(Upgrade_ID upgrade_id, Price price, Time time_when_bought)
{
  /**
   * Build a BoughtUpgrade object, and store it
   */

  BoughtUpgrade bought_upgrade = BoughtUpgrade(upgrade_id, time_when_bought, price);

  _history.push_back(bought_upgrade);

}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
