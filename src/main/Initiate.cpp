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

  /////////////
  // Science //
  /////////////
  // Quantum magnetism
  Upgrade_Type a_type = Upgrade_Type::science;
  Upgrade u_quantum_magnet = Upgrade(Upgrade_Type::science,
                                     Upgrade_ID::u_quantum_magnet,
                                     GameConfig::Upgrade::u_quantum_magnet_desc,
                                     GameConfig::Upgrade::u_quantum_magnet_price,
                                     GameConfig::Upgrade::u_quantum_magnet_dep);

  Upgrade u_kinetic_power = Upgrade(Upgrade_Type::science,
                                    Upgrade_ID::u_kinetic_power,
                                    GameConfig::Upgrade::u_kinetic_power_desc,
                                    GameConfig::Upgrade::u_kinetic_power_price,
                                    GameConfig::Upgrade::u_kinetic_power_dep);


  Upgrade u_quanta_expulsor = Upgrade(Upgrade_Type::science,
                                      Upgrade_ID::u_quanta_expuls,
                                      GameConfig::Upgrade::u_quanta_expulsor_desc,
                                      GameConfig::Upgrade::u_quanta_expulsor_price,
                                      GameConfig::Upgrade::u_quanta_expulsor_dep);
  ///////////////
  // Structure //
  ///////////////
  Upgrade u_terminal = Upgrade(Upgrade_Type::structure,
                               Upgrade_ID::u_terminal,
                               GameConfig::Upgrade::u_terminal_desc,
                               GameConfig::Upgrade::u_terminal_price);


  Upgrade u_radar = Upgrade(Upgrade_Type::structure,
                            Upgrade_ID::u_radar,
                            GameConfig::Upgrade::u_radar_desc,
                            GameConfig::Upgrade::u_radar_price,
                            GameConfig::Upgrade::u_radar_dep);

  Upgrade u_quantum_generator = Upgrade(Upgrade_Type::structure,
                                        Upgrade_ID::u_quantum_generator,
                                        GameConfig::Upgrade::u_quantum_generator_desc,
                                        GameConfig::Upgrade::u_quantum_generator_price,
                                        GameConfig::Upgrade::u_quantum_generator_dep);

  Upgrade u_quantum_throttle = Upgrade(Upgrade_Type::structure,
                                       Upgrade_ID::u_quantum_throttle,
                                       GameConfig::Upgrade::u_quantum_throttle_desc,
                                       GameConfig::Upgrade::u_quantum_throttle_price,
                                       GameConfig::Upgrade::u_quantum_throttle_dep);

  Upgrade u_compass = Upgrade(Upgrade_Type::structure,
                              Upgrade_ID::u_compass,
                              GameConfig::Upgrade::u_compass_desc,
                              GameConfig::Upgrade::u_compass_price,
                              GameConfig::Upgrade::u_compass_dep);
  /////////////////////
  //     Upgrades    //
  /////////////////////


  // Dynamo
  Upgrade u_dynamo = Upgrade(Upgrade_Type::upgrade,
                             Upgrade_ID::u_dynamo,
                             GameConfig::Upgrade::u_dynamo_desc,
                             GameConfig::Upgrade::u_dynamo_price,
                             GameConfig::Upgrade::u_dynamo_dep);

  // Kinetic impulsor
  Upgrade u_kinetic_impulsor = Upgrade(Upgrade_Type::upgrade,
                                       Upgrade_ID::u_kinetic_impulsor,
                                       GameConfig::Upgrade::u_kinetic_impulsor_desc,
                                       GameConfig::Upgrade::u_kinetic_impulsor_price,
                                       GameConfig::Upgrade::u_kinetic_impulsor_dep);

  Upgrade u_quantum_conductor = Upgrade(Upgrade_Type::upgrade,
                                        Upgrade_ID::u_quantum_conductor,
                                        GameConfig::Upgrade::u_quantum_conductor_desc,
                                        GameConfig::Upgrade::u_quantum_conductor_price,
                                        GameConfig::Upgrade::u_quantum_conductor_dep);

  Upgrade u_superconductor = Upgrade(Upgrade_Type::upgrade,
                                     Upgrade_ID::u_superconductor,
                                     GameConfig::Upgrade::u_superconductor_desc,
                                     GameConfig::Upgrade::u_superconductor_price,
                                     GameConfig::Upgrade::u_superconductor_dep);

  Upgrade u_quantum_synergy = Upgrade(Upgrade_Type::upgrade,
                                     Upgrade_ID::u_quantum_synergy,
                                     GameConfig::Upgrade::u_quantum_synergy_desc,
                                     GameConfig::Upgrade::u_quantum_synergy_price,
                                     GameConfig::Upgrade::u_quantum_synergy_dep);

  //////////////////////////
  // Incremental Upgrades //
  //////////////////////////

  // Quantum coil
  Upgrade i_quant_coil = Upgrade(Upgrade_Type::incremental,
                                 Upgrade_ID::i_quant_coil,
                                 GameConfig::Upgrade::i_quant_coil_desc,
                                 GameConfig::Upgrade::i_quant_coil_price,
                                 GameConfig::Upgrade::i_quant_coil_increase_factor,
                                 GameConfig::Upgrade::i_quant_coil_dep);

  // Level A Cells
  Upgrade i_level_a_cell = Upgrade(Upgrade_Type::incremental,
                                   Upgrade_ID::i_level_a_cell,
                                   GameConfig::Upgrade::i_level_a_cell_desc,
                                   GameConfig::Upgrade::i_level_a_cell_price,
                                   GameConfig::Upgrade::i_level_a_cell_increase_factor,
                                   GameConfig::Upgrade::i_level_a_cell_dep);






  std::vector<Upgrade> vector_of_upgrades = {u_quantum_magnet,
                                             u_kinetic_power,
                                             u_quanta_expulsor,
                                             u_terminal,
                                             u_quantum_generator,
                                             u_compass,
                                             u_radar,
                                             u_quantum_throttle,
                                             u_kinetic_impulsor,
                                             u_quantum_conductor,
                                             u_dynamo,
                                             u_quantum_synergy,
                                             u_superconductor,
                                             i_quant_coil,
                                             i_level_a_cell,
                                             };

  return vector_of_upgrades;
}



std::vector<Resource> Init::initiate_resources_list()
{
  Resource kinetic_energy = Resource(Resource_ID::kinetic_energy);
  Resource dark_matter = Resource(Resource_ID::dark_matter);

  std::vector<Resource> vector_of_resources = {kinetic_energy, dark_matter};
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
