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


std::string History::to_string(){
  /**
   * Formats the history into a printable string
   */
  std::string history_output = "Game history :\n";

  for (auto purchase : _history) {
    //history_output +=
  }


  return history_output;

}

//////////////////////////////////////////////////////////////////////
// $Log:$
//