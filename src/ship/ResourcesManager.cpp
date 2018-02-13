// ResourcesManager.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////


#include "ship/ResourcesManager.h"
#include "ship/UpgradesManager.h"
#include "ship/resources_helper.h"
#include "ship/computations.h"

using Physics::Time;

ResourcesManager::ResourcesManager(std::vector<Resource> stock_resources)
{
  /**
   * Empty default constructor (necessarily empty to allow circular definition)
   */
  _stock_of_resources = stock_resources;
}

ResourcesManager::ResourcesManager(const ResourcesManager& original)
    :_stock_of_resources(original._stock_of_resources)
{    /**
      * Copy constructor
      */
}

ResourcesManager::~ResourcesManager(){}

ResourcesManager& ResourcesManager::operator=(ResourcesManager& original)
{
  return original;
}



void ResourcesManager::gather_resources(Time elapsed_time, Computer* computer)
{
  /**
   * Compute new resources gathered in given time
   */

  // Gather resources one by one
  for (auto resource : _stock_of_resources)
  {
    BigNum resource_per_second = computer->resource_per_second(resource.get_ID());
    BigNum new_amount = BigNum(resource_per_second * elapsed_time.num());

    add_resource_amount(resource.get_ID(), new_amount);
  }
}



// Time ResourcesManager::get_time_until_in_stock(const Price& price) const
// {
//   /**
//    * Take a Price as input
//    * Return time to wait to have enough resources to pay price
//    */
//   Time time(0);

//   for (auto resourceAmount : price.get_resources_to_pay())
//   {
//     // resource is of type ResourceAmount !

//     Time time_until_in_stock = get_time_until_in_stock(resourceAmount._resource_ID, resourceAmount._amount);

//     if (time_until_in_stock > time)
//     {
//       time = time_until_in_stock;
//     }

//   }

//   return time;
// }

// Time ResourcesManager::get_time_until_in_stock(const Resource_ID& resource_id, BigNum required_amount) const
// {
// /*
//  * Take resource_ID and amount as input
//  * Return time to wait to have indicated amount of resource
//  */

//   Time time(0);
//   BigNum current_amount = get_resource(resource_id).get_current_amount();

//   BigNum needed_amount = required_amount - current_amount;

//   // Compute
//   if (needed_amount > 0)
//   {
//     BigNum resource_per_second = computation::get_resource_per_second(resource_id, _upgrades_manager);

//     time = Time(needed_amount/resource_per_second);
//   }

//   return time;
// }

Resource& ResourcesManager::get_resource(Resource_ID resource_id)
{
  /**
   * Take resource_id
     Return the Resource object corresponding to the ID
   */
  for (auto &resource : _stock_of_resources)
  {
    if (resource.has_id(resource_id))
    {
      return resource;
    }
  }
  std::cout << "Error, resource not present"  << "\n";
}


const Resource& ResourcesManager::get_resource(Resource_ID resource_id) const
{
  /**
   * Take resource_id
   Return the Resource object corresponding to the ID
  */
  for (auto &resource : _stock_of_resources)
  {
    if (resource.has_id(resource_id))
    {
      return resource;
    }
  }
  std::cout << "Error, resource not present"  << "\n";
}


BigNum ResourcesManager::get_resource_amount(Resource_ID resource_id) const
{
  /**
   * Take resource id
     return amount of resource in stock
   */

  return get_resource(resource_id).get_current_amount();
}

std::string ResourcesManager::get_resource_name(Resource_ID resource_id) const
{
  return get_resource(resource_id).get_name();
}

void ResourcesManager::pay_price(Price price)
{
  /**
   * Take a price, and remove its amounts of resources from the
     list of resources
   */

  // For each ResourceAmount to pay
  for (auto resourceAmount : price.get_resources_to_pay())
  {
    Resource_ID resource_id = resourceAmount._resource_ID;
    BigNum amount_to_pay = price.get_resource_amount(resource_id);
    get_resource(resource_id).substract_resource_amount(amount_to_pay);
  }
}

void ResourcesManager::add_resource_amount(Resource_ID resource_id, BigNum amount)
{
  get_resource(resource_id).add_resource_amount(amount);
}

bool ResourcesManager::can_be_payed(Price price) const
{
  for (auto required_resource : price.get_resources_to_pay())
  {
    Resource_ID resource_ID = required_resource._resource_ID;
    BigNum required_amount = required_resource._amount;
    BigNum current_amount = get_resource_amount(resource_ID);

    if (current_amount < required_amount) return false;
  }

  return true;

}

std::vector<Resource> ResourcesManager::get_resources()
{
  return _stock_of_resources;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
