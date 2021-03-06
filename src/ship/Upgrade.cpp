// -*- compile-command: "./../../compile.sh"; -*-
// Upgrade.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include <assert.h>

#include "main/game_global_variables.h"
#include "ship/Upgrade.h"

// Basic constructor
Upgrade::Upgrade(
    Upgrade_Type type,
    Upgrade_ID upgrade_id,
    std::string description,
    Price initial_price)
    : _type(type), _upgrade_id(upgrade_id), _description(description), _initial_cost(initial_price)
{
  _uniqueness = true;
  _increase_factor = 1;
}

// Incremental
Upgrade::Upgrade(
    Upgrade_Type type,
    Upgrade_ID upgrade_id,
    std::string description,
    Price initial_cost,
    double increase_factor)
    : Upgrade(type, upgrade_id, description, initial_cost)
{
  _increase_factor = increase_factor;
  _uniqueness = false;
}

// Incremental + dependencies
Upgrade::Upgrade(
    Upgrade_Type type,
    Upgrade_ID upgrade_id,
    std::string description,
    Price initial_price,
    double increase_factor,
    std::vector<Upgrade_ID> dependencies)
    : Upgrade(type, upgrade_id, description, initial_price, increase_factor)
{
  _dependencies = dependencies;
}

// Dependencies
Upgrade::Upgrade(
    Upgrade_Type type,
    Upgrade_ID upgrade_id,
    std::string description,
    Price init_cost,
    std::vector<Upgrade_ID> dependencies)
    : Upgrade(type, upgrade_id, description, init_cost)
{
  _uniqueness = true;
  _increase_factor = 1;
  _dependencies = dependencies;
}


Upgrade::~Upgrade(){}



Price Upgrade::get_cost_increase_level(int additional_levels) const
{
  /**
   * Get cost to buy <number_levels> new levels
     Return Price
   */
  assert(additional_levels > 0);

  return _initial_cost * pow(_increase_factor, _current_level - 1 + additional_levels);
}

Upgrade_Type Upgrade::type() const
{
  return _type;
}

int Upgrade::get_current_level() const
{
  return _current_level;
}

void Upgrade::increase_level(int number_new_levels)
{
  /**
   * Increase current level with <number_levels>
   */

  if (_uniqueness && _current_level > 0)
  {
    std::cout << "Error, upgrade already bought!"  << "\n";
    return;
  }

  _current_level += number_new_levels;
}

bool Upgrade::has_id(Upgrade_ID upgrade_id) const
{
  /**
   * Checks if upgrade has the correct ID
   */
  Upgrade_ID an = upgrade_id;
  return upgrade_id == _upgrade_id;
}


std::string Upgrade::get_name() const
{
  return global::upgrade_name(_upgrade_id);
}

std::string Upgrade::get_desc() const
{
  return _description;
}

Upgrade_ID Upgrade::get_ID() const
{
  return _upgrade_id;
}

void Upgrade::set_uniqueness(bool uniqueness)
{
  _uniqueness = uniqueness;
}

bool Upgrade::is_unique() const
{
  return _uniqueness;
}

std::vector<Upgrade_ID> Upgrade::dependencies() const
{
  return _dependencies;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
