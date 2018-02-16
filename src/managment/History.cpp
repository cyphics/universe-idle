// History.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "managment/History.h"

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

  int hist_line_length = 80;
  std::string separator;
  for (int i = 0; i < hist_line_length; i++) {
    separator += "-";
  }
  separator += "\n";


  std::string history_output = "Game history :\n";
  history_output += separator;
  for (auto purchase : _history)
  {

    // purchase is of type BoughtUpgrade
    history_output += purchase.to_string();
    history_output += "\n";
    history_output += separator;
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
