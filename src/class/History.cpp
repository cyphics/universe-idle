// History.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include "../../include/class/History.h"

History::History(){

}

History::~History(){}


std::string History::to_string(const ResourcesManager* resources_manager) const{
  /**
   * Formats the history into a printable string
   */

  std::string history_output = "Game history :\n";

  for (auto purchase : _history) {
    history_output += purchase.to_string(resources_manager);
  }

  return history_output;
}

void History::add_upgrade(Upgrade_ID upgrade_id, Price price, Time time_when_bought){
  /**
   * Build a BoughtUpgrade object, and store it
   */

  BoughtUpgrade bought_upgrade = BoughtUpgrade(upgrade_id, time_when_bought, price);

  _history.push_back(bought_upgrade);

}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
