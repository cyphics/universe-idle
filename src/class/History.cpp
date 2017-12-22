// -*- compile-command: "./../../compile.sh"; -*-
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


std::string History::to_string() const{
  /**
   * Formats the history into a printable string
   */
  std::string history_output = "Game history :\n";

  for (auto purchase : _history) {
    //history_output +=
  }


  return history_output;

}

void History::add_upgrade(Upgrade_ID upgrade_id, BigNum price, int time){

}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
// Local Variables:
// compile-command: "./../../compile.sh"; -*-
// End:
