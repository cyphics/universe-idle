// -*- compile-command: "./compile.sh"; -*-
// Price.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef PRICE_H
#define PRICE_H 1

//#include "ResourcesManager.h"
#include "../helpers/resources_helper.h"

class ResourcesManager; // To avoid recursive definition

#include <vector>
class Price{
 private:
  std::vector<ResourceAmount> _resources_to_pay;

 public:
  bool can_be_payed(const ResourcesManager* resources_manager) const;
  bool has_resource_already(Resource_ID) const;
  BigNum get_resource_amount(Resource_ID) const;

  void add_resource(Resource_ID, BigNum amount);
  ResourceAmount& get_existing_resource(Resource_ID resource_id);

  const std::vector<ResourceAmount>& get_resources_to_pay() const;
};


#endif // PRICE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
