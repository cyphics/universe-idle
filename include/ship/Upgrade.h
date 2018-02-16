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

 public:
  Upgrade(Upgrade_Type type, Upgrade_ID upgrade_id, Price initial_price, double increase_factor);
  Upgrade(Upgrade_Type type, Upgrade_ID upgrade_id, Price initial_price);
  Upgrade(Upgrade_Type type, Upgrade_ID upgrade_id, Price initial_price, double increase_factor, std::vector<Upgrade_ID> dependencies);
  Upgrade(Upgrade_Type type, Upgrade_ID upgrade_id, Price initial_price, std::vector<Upgrade_ID> dependencies);
  ~Upgrade();

  // Getters
  Price get_cost_increase_level(int level) const;
  int get_current_level() const;
  std::string get_name() const;
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
