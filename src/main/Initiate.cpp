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
#include "main/game_configuration.h"

std::vector<Upgrade> Init::initiate_upgrades_list()
{

  /////////////////////
  // Unique upgrades //
  /////////////////////

  // Terminal upgrade
  Upgrade unique_upgrade_1 = Upgrade(Upgrade_ID::unique_upgrade_1, \
                                                 GameConfig::Upgrade::unique_upgrade_1_price);
  // Quantum magnetism
  Upgrade unique_upgrade_2 = Upgrade(Upgrade_ID::unique_upgrade_2, \
                                     GameConfig::Upgrade::unique_upgrade_2_price, \
                                     GameConfig::Upgrade::unique_upgrade_2_dep);
  // Level A Booster
  Upgrade unique_upgrade_3 = Upgrade(Upgrade_ID::unique_upgrade_3, \
                                     GameConfig::Upgrade::unique_upgrade_3_price, \
                                     GameConfig::Upgrade::unique_upgrade_3_dep);

  // Radar
  Upgrade unique_upgrade_4 = Upgrade(Upgrade_ID::unique_upgrade_4, \
                                     GameConfig::Upgrade::unique_upgrade_4_price, \
                                     GameConfig::Upgrade::unique_upgrade_4_dep);



  //////////////////////////
  // Incremental Upgrades //
  //////////////////////////

  // Quantum coil
  Upgrade increm_upgrade_1 = Upgrade(Upgrade_ID::increm_upgrade_1, \
                                     GameConfig::Upgrade::increm_upgrade_1_price, \
                                     GameConfig::Upgrade::increm_upgrade_1_increase_factor, \
                                     GameConfig::Upgrade::increm_upgrade_1_dep);

  // Level A Cells
  Upgrade increm_upgrade_2 = Upgrade(Upgrade_ID::increm_upgrade_2, \
                                     GameConfig::Upgrade::increm_upgrade_2_price, \
                                     GameConfig::Upgrade::increm_upgrade_2_increase_factor, \
                                     GameConfig::Upgrade::increm_upgrade_2_dep);

  // ?
  Upgrade increm_upgrade_3 = Upgrade(Upgrade_ID::increm_upgrade_3,\
                                     GameConfig::Upgrade::increm_upgrade_3_price, \
                                     GameConfig::Upgrade::increm_upgrade_3_increase_factor, \
                                     GameConfig::Upgrade::increm_upgrade_3_depend);





  std::vector<Upgrade> vector_of_upgrades = {increm_upgrade_1, \
                                             increm_upgrade_2, \
                                             increm_upgrade_3, \
                                             unique_upgrade_1, \
                                             unique_upgrade_2, \
                                             unique_upgrade_3, \
                                             unique_upgrade_4};

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
