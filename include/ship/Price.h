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


#include <vector>
#include "ship/resources_helper.h"
class Price{
 private:
  std::vector<ResourceAmount> _resources_to_pay;

 public:
  Price(Resource_ID resource_id, BigNum amount);
  bool has_resource_already(Resource_ID) const;
  BigNum get_resource_amount(Resource_ID) const;
  const std::vector<ResourceAmount>& get_resources_to_pay() const;

  ResourceAmount get_existing_resource(Resource_ID resource_id);
  void add_resource(Resource_ID, BigNum amount);
  Price& operator*=(const double& rhs);

  std::string to_string() const;
};

inline Price operator*(const Price& lhs, const double& rhs ){
  Price mul = lhs;
  mul *= rhs;
  return mul;
}


#endif // PRICE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
