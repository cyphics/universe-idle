// resources_computation.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/helpers/resources_computation.h"


BigNum compute_cinetic_energy(Time elapsed_time, const UpgradesList& list_of_upgrades){
  int small_boost_level = list_of_upgrades.get_upgrade_level(Upgrade_ID::small_boost);
  BigNum time = elapsed_time.get_numerical_value();

  return BigNum(time * small_boost_level);
}

BigNum compute_dark_matter(Time elapsed_time, const UpgradesList& list_of_upgrades){
  return BigNum(1);
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
