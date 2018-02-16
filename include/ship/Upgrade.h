// Upgrade.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADE_H
#define UPGRADE_H 1

#include <vector>
#include "ship/Price.h"
#include "ship/resources_helper.h"
#include "ship/upgrades_helper.h"


class Upgrade{
 private:
  Upgrade_Type _type;
  Upgrade_ID _upgrade_id;
  Price _initial_cost;
  double _increase_factor;
  int _current_level = 0; // Equals number bought
  bool _uniqueness = false;
  std::vector<Upgrade_ID> _dependencies;
  std::string _description;

 public:
  // Basic constructor
  Upgrade(
      Upgrade_Type type,
      Upgrade_ID upgrade_id,
      std::string description,
      Price init_price);

  // With increase factor (for increm)
  Upgrade(
      Upgrade_Type type,
      Upgrade_ID upgrade_id,
      std::string description,
      Price initial_price,
      double increase_factor);

  // Construtor with dependencies
  Upgrade(
      Upgrade_Type type,
      Upgrade_ID upgrade_id,
      std::string description,
      Price initial_price,
      std::vector<Upgrade_ID> dependencies);

  // Increm construct with dependencies
  Upgrade(
      Upgrade_Type type,
      Upgrade_ID upgrade_id,
      std::string description,
      Price initial_price,
      double increase_factor,
      std::vector<Upgrade_ID> dependencies);


~Upgrade();

  // Getters
  Price get_cost_increase_level(int level) const;
  int get_current_level() const;
  std::string get_name() const;
  std::string get_desc() const;
  bool is_unique() const;
  bool has_id(Upgrade_ID) const;
  Upgrade_ID get_ID() const;
  std::vector<Upgrade_ID> dependencies() const;
  Upgrade_Type type() const;
  void increase_level(int number_levels);
  void set_uniqueness(bool availability);
};


#endif // UPGRADE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
