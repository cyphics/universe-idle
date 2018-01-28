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
  // CLick boost

  UpgradeCostTableElement click_boost_cinetic_energy;

  click_boost_cinetic_energy.resource = GameConfig::Upgrade::click_boost_resource;
  click_boost_cinetic_energy.initial_cost = GameConfig::Upgrade::click_boost_initial_cost;
  double click_boost_increase_factor = GameConfig::Upgrade::click_boost_increase_factor;
  std::vector<UpgradeCostTableElement> cost_click_boost;
  cost_click_boost.push_back(click_boost_cinetic_energy);


  // Build object
  Upgrade click_boost = Upgrade(Upgrade_ID::click_boost, cost_click_boost, click_boost_increase_factor);
  click_boost.set_availability(GameConfig::Upgrade::click_boost_availability);
  click_boost.set_uniqueness(GameConfig::Upgrade::click_boost_uniqueness);


  // SMALL BOOST
  // Build cost table elements

  UpgradeCostTableElement boost_1_cinetic_energy;

  boost_1_cinetic_energy.resource = GameConfig::Upgrade::boost_1_resource;
  boost_1_cinetic_energy.initial_cost = GameConfig::Upgrade::boost_1_initial_cost;
  double boost_1_increase_factor = GameConfig::Upgrade::boost_1_increase_factor;
  std::vector<UpgradeCostTableElement> cost_boost_1;
  cost_boost_1.push_back(boost_1_cinetic_energy);


  // Build object
  Upgrade boost_1 = Upgrade(Upgrade_ID::boost_1, cost_boost_1, boost_1_increase_factor);
  boost_1.set_availability(GameConfig::Upgrade::boost_1_availability);

  // BIG BOOST
  // Build cost table elements
  UpgradeCostTableElement boost_2_cinetic_energy;
  boost_2_cinetic_energy.resource = GameConfig::Upgrade::boost_2_resource;
  boost_2_cinetic_energy.initial_cost = GameConfig::Upgrade::boost_2_initial_cost;
  double boost_2_increase_factor = GameConfig::Upgrade::boost_2_increase_factor;

  std::vector<UpgradeCostTableElement> cost_boost_2;
  cost_boost_2.push_back(boost_2_cinetic_energy);


  // Build object
  Upgrade boost_2 = Upgrade(Upgrade_ID::boost_2, cost_boost_2, boost_2_increase_factor);
  boost_2.set_availability(GameConfig::Upgrade::boost_2_availability);


  // MEGA BOOST
  // Build cost table elements
  UpgradeCostTableElement boost_3_cinetic_energy;
  boost_3_cinetic_energy.resource = GameConfig::Upgrade::boost_3_resource;
  boost_3_cinetic_energy.initial_cost = GameConfig::Upgrade::boost_3_initial_cost;
  double boost_3_increase_factor = GameConfig::Upgrade::boost_3_increase_factor;

  std::vector<UpgradeCostTableElement> cost_boost_3;
  cost_boost_3.push_back(boost_3_cinetic_energy);


  // Build object
  Upgrade boost_3 = Upgrade(Upgrade_ID::boost_3, cost_boost_3, boost_3_increase_factor);
  boost_3.set_availability(GameConfig::Upgrade::boost_3_availability);

  std::vector<Upgrade> vector_of_upgrades = {boost_1, boost_2, click_boost, boost_3};

  return vector_of_upgrades;
}



std::vector<Resource> Init::initiate_resources_list()
{
  Resource cinetic_energy = Resource(Resource_ID::cinetic_energy);
  Resource dark_matter = Resource(Resource_ID::dark_matter);

  std::vector<Resource> vector_of_resources = {cinetic_energy, dark_matter};
  return vector_of_resources;
}

UpgradesManager Init::initiate_upgrades_manager()
{
  UpgradesManager manager(initiate_upgrades_list());
  return manager;
}

ResourcesManager Init::initiate_resources_manager()
{
  ResourcesManager manager(initiate_resources_list());
  return manager;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
