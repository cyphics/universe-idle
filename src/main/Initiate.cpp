// Initiate.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////


#include <vector>
#include "main/initiate.h"
#include "ship/Upgrade.h"

UpgradesList Init::initiate_upgrades_list()
{

  // SMALL BOOST

  // Build cost table elements
  UpgradeCostTableElement small_boost_cinetic_energy;
  small_boost_cinetic_energy.resource = Resource_ID::cinetic_energy;
  small_boost_cinetic_energy.initial_cost = 10;
  double small_boost_increase_factor = 1.15;

  std::vector<UpgradeCostTableElement> cost_small_boost;
  cost_small_boost.push_back(small_boost_cinetic_energy);


  // Build object
  Upgrade small_boost = Upgrade(Upgrade_ID::small_boost, cost_small_boost, small_boost_increase_factor);

  // BIG BOOST

  // Build cost table elements
  UpgradeCostTableElement big_boost_cinetic_energy;
  big_boost_cinetic_energy.resource = Resource_ID::cinetic_energy;
  big_boost_cinetic_energy.initial_cost = 10;
  double big_boost_increase_factor = 1.15;

  std::vector<UpgradeCostTableElement> cost_big_boost;
  cost_big_boost.push_back(big_boost_cinetic_energy);


  // Build object
  Upgrade big_boost = Upgrade(Upgrade_ID::big_boost, cost_big_boost, big_boost_increase_factor);




  std::vector<Upgrade> vector_of_upgrades = {small_boost, big_boost};

  UpgradesList upgrades_list;
  upgrades_list.set_list_upgrades(vector_of_upgrades);
  return upgrades_list;
}



ResourcesList Init::initiate_resources_list()
{
  // FAKE ENERGY
  //Resource fake_energy = Resource(Resource_ID::fake_energy);
  // CINETIC ENERGY
  Resource cinetic_energy = Resource(Resource_ID::cinetic_energy);
  Resource dark_matter = Resource(Resource_ID::dark_matter);

  std::vector<Resource> vector_of_resources = {cinetic_energy, dark_matter};
  ResourcesList resources_list = ResourcesList(vector_of_resources);

  return resources_list;
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
