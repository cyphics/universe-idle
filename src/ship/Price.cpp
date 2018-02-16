// Price.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////
#include "ship/Price.h"
#include "ship/ResourcesManager.h"
#include "main/game_global_variables.h"

Price::Price(Resource_ID upgrade_id, BigNum amount)
{
  _resources_to_pay.push_back(ResourceAmount(upgrade_id, amount));
}

bool Price::has_resource_already(Resource_ID resource_id) const
{
  /**
   * Check if a given resource is already stored in the Price object
   */
  for (auto existing_resource : _resources_to_pay)
  {
    if (existing_resource._resource_ID == resource_id) return true;
  }
  return false;
}

void Price::add_resource(Resource_ID resource_id, BigNum amount)
{
  /**
   * Add a resource to the price object
   */

  // If Price object already contains the given resource, just add the amount
  if (has_resource_already(resource_id))
  {
    get_existing_resource(resource_id)._amount += amount;
  }
  // Else, push_back the resource in the Price object
  else
  {
    _resources_to_pay.push_back(ResourceAmount(resource_id, amount));
  }
}



ResourceAmount Price::get_existing_resource(Resource_ID resource_id)
{
  for (auto resourceAmount : _resources_to_pay)
  {
    if (resourceAmount._resource_ID == resource_id) return resourceAmount;
  }
  std::cout << "Resource not present"  << "\n";

}

BigNum Price::get_resource_amount(Resource_ID resource_id) const
{
  for (auto resourceAmount : _resources_to_pay)
  {
    if (resourceAmount._resource_ID == resource_id) return resourceAmount._amount;
  }
  std::cout << "Resource not present"  << "\n";
  return BigNum(0);
}

const std::vector<ResourceAmount>& Price::get_resources_to_pay() const
{
  return _resources_to_pay;
}

std::string Price::to_string() const
{
  std::string output = "";

  for (auto resourceAmount: _resources_to_pay)
  {
    //output += " :";
    output += resourceAmount._amount.to_string() + " ";
    output += global::resource_name(resourceAmount._resource_ID);
  }


  return output;
}

Price& Price::operator*=(const double& rhs)
{
  for (auto &resource : _resources_to_pay ){
    resource._amount *= rhs;
  }
  return *this;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
