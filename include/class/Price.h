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

#include "ResourcesList.h"
#include "../helpers/resources_helper.h"

#include <vector>
class Price{
 private:
  std::vector<ResourceAmount> _resources_to_pay;

 public:
  bool can_be_payed(const ResourcesList* stock_of_resources) const;
  bool has_resource_already(Resource_ID) const;
  BigNum get_resource_amount(Resource_ID) const;

  void add_resource(Resource_ID, BigNum amount);
  ResourceAmount& get_existing_resource(Resource_ID resource_id);

};


#endif // PRICE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
