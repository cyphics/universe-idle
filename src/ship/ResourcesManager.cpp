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

ResourcesManager::ResourcesManager()
{
  /**
   * Empty default constructor (necessarily empty to allow circular definition)
   */
 }

ResourcesManager::ResourcesManager(const ResourcesManager& original)
    :_stock_of_resources(original._stock_of_resources),_upgrades_manager(original._upgrades_manager)
{    /**
      * Copy constructor
      */
}

ResourcesManager::~ResourcesManager(){}

ResourcesManager& ResourcesManager::operator=(ResourcesManager& original)
{
  return original;
}

void ResourcesManager::init_manager(ResourcesList resources, UpgradesManager* upgrades_manager)
{
  /**
   * Init manager with existing members
   */

  _stock_of_resources = resources;
  _upgrades_manager = upgrades_manager;
}

void ResourcesManager::gather_resources(Physics::Time elapsed_time)
{
  /**
   * Compute new resources gathered in given time
   */

  // Gather resources one by one
  for (auto resource : _stock_of_resources.get_list_of_resources())
  {
    BigNum resource_per_second = computation::get_resource_per_second(resource.get_ID(), _upgrades_manager);
    BigNum new_amount = BigNum(resource_per_second * elapsed_time.num());

    add_resource_amount(resource.get_ID(), new_amount);
  }
}

const ResourcesList& ResourcesManager::get_resources_list() const
{
  return _stock_of_resources;
}

ResourcesList& ResourcesManager::get_resources_list()
{
  return _stock_of_resources;
}

Physics::Time ResourcesManager::get_time_until_in_stock(const Price& price) const
{
  /**
   * Take a Price as input
   * Return time to wait to have enough resources to pay price
   */
  Physics::Time time(0);

  for (auto resourceAmount : price.get_resources_to_pay())
  {
    // resource is of type ResourceAmount !
    if (get_time_until_in_stock(resourceAmount._resource_ID, resourceAmount._amount) > time)
      time = get_time_until_in_stock(resourceAmount._resource_ID, resourceAmount._amount);
  }

  return time;
}

Physics::Time ResourcesManager::get_time_until_in_stock(const Resource_ID& resource_id, BigNum required_amount) const
{
/*
 * Take resource_ID and amount as input
 * Return time to wait to have indicated amount of resource
 */

  Physics::Time time(0);

  BigNum current_amount = get_real_resource(resource_id).get_current_amount();

  BigNum needed_amount = required_amount - current_amount;

  // Compute
  if (needed_amount > 0)
  {
    BigNum resource_per_second = computation::get_resource_per_second(resource_id, _upgrades_manager);

    time = Physics::Time(needed_amount/resource_per_second);
  }

  return time;
}

Resource& ResourcesManager::get_real_resource(Resource_ID resource)
{
  /**
   * Take resource_id
     Return the Resource object corresponding to the ID
   */

  return get_resources_list().get_resource(resource);
}

const Resource& ResourcesManager::get_real_resource(Resource_ID resource) const
{
  /**
   * Take resource_id
   Return the Resource object corresponding to the ID
  */

  return get_resources_list().get_resource(resource);
}

BigNum ResourcesManager::get_resource_amount(Resource_ID resource_id) const
{
  /**
   * Take resource id
     return amount of resource in stock
   */

  return get_real_resource(resource_id).get_current_amount();
}

std::string ResourcesManager::get_resource_name(Resource_ID resource_id) const
{
  return _stock_of_resources.get_resource(resource_id).get_name();
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
    get_real_resource(resource_id).substract_resource_amount(amount_to_pay);
  }
}

void ResourcesManager::add_resource_amount(Resource_ID resource_id, BigNum amount)
{
  get_real_resource(resource_id).add_resource_amount(amount);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
