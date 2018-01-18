// Resource.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCE_H
#define RESOURCE_H 1

#include "util/BigNum.h"
#include "ship/UpgradesManager.h"
#include "ship/resources_helper.h"

class Resource{
 private:
  Resource_ID _resource_id;
  BigNum _amount = 0;
  BigNum _max_amount;
  BigNum _amount_per_second = 0;

 public:
  Resource(Resource_ID resource_id);
  ~Resource();

  // Getters
  BigNum get_current_amount() const;
  Resource_ID get_ID() const;
  std::string get_name() const;
  bool has_id(Resource_ID) const;
  BigNum get_amount_per_second(const UpgradesManager* upgrades_manager) const;

  void set_current_amount(BigNum new_amount);
  void add_resource_amount(BigNum amount);
  void substract_resource_amount(BigNum amount);

};

#endif // RESOURCE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
