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
#include "ship/upgrades_configuration.h"

std::vector<Upgrade> Init::initiate_upgrades_list()
{

  // SMALL BOOST
  // Build cost table elements

  UpgradeCostTableElement small_boost_cinetic_energy;

  small_boost_cinetic_energy.resource = Congif::Upgrade::small_boost_resource;
  small_boost_cinetic_energy.initial_cost = Congif::Upgrade::small_boost_initial_cost;
  double small_boost_increase_factor = Congif::Upgrade::small_boost_increase_factor;
  std::vector<UpgradeCostTableElement> cost_small_boost;
  cost_small_boost.push_back(small_boost_cinetic_energy);


  // Build object
  Upgrade small_boost = Upgrade(Upgrade_ID::small_boost, cost_small_boost, small_boost_increase_factor);
  small_boost.set_availability(Congif::Upgrade::small_boost_availability);

  // BIG BOOST
  // Build cost table elements
  UpgradeCostTableElement big_boost_cinetic_energy;
  big_boost_cinetic_energy.resource = Congif::Upgrade::big_boost_resource;
  big_boost_cinetic_energy.initial_cost = Congif::Upgrade::big_boost_initial_cost;
  double big_boost_increase_factor = Congif::Upgrade::big_boost_increase_factor;

  std::vector<UpgradeCostTableElement> cost_big_boost;
  cost_big_boost.push_back(big_boost_cinetic_energy);


  // Build object
  Upgrade big_boost = Upgrade(Upgrade_ID::big_boost, cost_big_boost, big_boost_increase_factor);
  big_boost.set_availability(Congif::Upgrade::big_boost_availability);

  std::vector<Upgrade> vector_of_upgrades = {small_boost, big_boost};

  return vector_of_upgrades;
}



std::vector<Resource> Init::initiate_resources_list()
{
  Resource cinetic_energy = Resource(Resource_ID::cinetic_energy);
  Resource dark_matter = Resource(Resource_ID::dark_matter);

  std::vector<Resource> vector_of_resources = {cinetic_energy, dark_matter};
  return vector_of_resources;
}

UpgradesManager& Init::initiate_upgrades_manager()
{
  UpgradesManager manager(initiate_upgrades_list());
  return manager;
}

ResourcesManager& Init::initiate_resources_manager()
{
  ResourcesManager manager(initiate_resources_list());
  return manager;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
