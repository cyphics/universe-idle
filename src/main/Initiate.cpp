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
  Upgrade u_terminal = Upgrade(Upgrade_ID::u_terminal, \
                                                 GameConfig::Upgrade::u_terminal_price);
  // Quantum magnetism
  Upgrade u_quantum_magnet = Upgrade(Upgrade_ID::u_quantum_magnet, \
                                     GameConfig::Upgrade::u_quantum_magnet_price, \
                                     GameConfig::Upgrade::u_quantum_magnet_dep);
  // Level A Booster
  Upgrade u_level_a_boost = Upgrade(Upgrade_ID::u_level_a_boost, \
                                     GameConfig::Upgrade::u_level_a_boost_price, \
                                     GameConfig::Upgrade::u_level_a_boost_dep);

  // Radar
  Upgrade u_radar = Upgrade(Upgrade_ID::u_radar, \
                                     GameConfig::Upgrade::u_radar_price, \
                                     GameConfig::Upgrade::u_radar_dep);

  // Radar
  Upgrade u_dynamo = Upgrade(Upgrade_ID::u_dynamo, \
                            GameConfig::Upgrade::u_dynamo_price, \
                            GameConfig::Upgrade::u_dynamo_dep);

  // Cinetic push
  Upgrade u_cinetic_push = Upgrade(Upgrade_ID::u_cinetic_push, \
                             GameConfig::Upgrade::u_cinetic_push_price, \
                             GameConfig::Upgrade::u_cinetic_push_dep);



  //////////////////////////
  // Incremental Upgrades //
  //////////////////////////

  // Quantum coil
  Upgrade i_quant_coil = Upgrade(Upgrade_ID::i_quant_coil, \
                                     GameConfig::Upgrade::i_quant_coil_price, \
                                     GameConfig::Upgrade::i_quant_coil_increase_factor, \
                                     GameConfig::Upgrade::i_quant_coil_dep);

  // Level A Cells
  Upgrade i_level_a_cell = Upgrade(Upgrade_ID::i_level_a_cell, \
                                     GameConfig::Upgrade::i_level_a_cell_price, \
                                     GameConfig::Upgrade::i_level_a_cell_increase_factor, \
                                     GameConfig::Upgrade::i_level_a_cell_dep);

  // ?
  // Upgrade increm_upgrade_3 = Upgrade(Upgrade_ID::increm_upgrade_3,\
  //                                    GameConfig::Upgrade::increm_upgrade_3_price, \
  //                                    GameConfig::Upgrade::increm_upgrade_3_increase_factor, \
  //                                    GameConfig::Upgrade::increm_upgrade_3_depend);





  std::vector<Upgrade> vector_of_upgrades = {i_quant_coil,
                                             i_level_a_cell,
                                             u_terminal,
                                             u_quantum_magnet,
                                             u_dynamo,
                                             u_cinetic_push,
                                             u_level_a_boost,
                                             u_radar};

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
