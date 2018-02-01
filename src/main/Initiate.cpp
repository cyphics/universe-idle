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

  /////////////////////
  // Unique upgrades //
  /////////////////////

  // Terminal upgrade
  UniqueUpgrade unique_upgrade_1 = UniqueUpgrade(Upgrade_ID::unique_upgrade_1, \
                                                 GameConfig::Upgrade::unique_upgrade_1_price);
  // Quantum magnetism
  UniqueUpgrade unique_upgrade_2 = UniqueUpgrade(Upgrade_ID::unique_upgrade_2, \
                                                 GameConfig::Upgrade::unique_upgrade_2_price);
  // Level A Booster
  UniqueUpgrade unique_upgrade_3 = UniqueUpgrade(Upgrade_ID::unique_upgrade_3, \
                                                 GameConfig::Upgrade::unique_upgrade_3_price);



  //////////////////////////
  // Incremental Upgrades //
  //////////////////////////

  // Quantum coil
  IncrementalUpgrade increm_upgrade_1 = IncrementalUpgrade(Upgrade_ID::increm_upgrade_1, \
                                                           GameConfig::Upgrade::increm_upgrade_1_price, \
                                                           GameConfig::Upgrade::increm_upgrade_1_increase_factor);

  // Level A Cells
  IncrementalUpgrade increm_upgrade_2 = IncrementalUpgrade(Upgrade_ID::increm_upgrade_2, \
                                                           GameConfig::Upgrade::increm_upgrade_2_price, \
                                                           GameConfig::Upgrade::increm_upgrade_2_increase_factor);

  // ?
  IncrementalUpgrade increm_upgrade_3 = IncrementalUpgrade(Upgrade_ID::increm_upgrade_3,\
                                                           GameConfig::Upgrade::increm_upgrade_3_price, \
                                                           GameConfig::Upgrade::increm_upgrade_3_increase_factor);





  std::vector<Upgrade> vector_of_upgrades = {increm_upgrade_1, \
                                             increm_upgrade_2, \
                                             increm_upgrade_3, \
                                             unique_upgrade_1, \
                                             unique_upgrade_2, \
                                             unique_upgrade_3};

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
