// -*- compile-command: "./compile.sh"; -*-
// upgrades_helper.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADES_HELPER_H
#define UPGRADES_HELPER_H 1

#include "ship/resources_helper.h"

enum class Upgrade_ID { click_boost, boost_1, boost_2, boost_3 };

struct UpgradeCostTableElement{
  Resource_ID resource;
  BigNum initial_cost;
};


#endif // UPGRADES_HELPER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
