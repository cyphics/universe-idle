// ResourcesManager.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H 1

#include "Resource.h"
#include "resources_helper.h"
#include "physics/Time.h"

class UpgradesManager;
class Price;


class ResourcesManager{
  /**
   * Class that manages the resources of the game.
     Gets a reference to the stock of resources, and to
     the upgrades manager
   */
 private:
  std::vector<Resource> _stock_of_resources;
  UpgradesManager* _upgrades_manager;

  Resource& get_resource(Resource_ID resource);
  const Resource& get_resource(Resource_ID resource) const;

 public:
  // CONSTRUCTORS
  ResourcesManager(std::vector<Resource>);
  ResourcesManager(const ResourcesManager& original);
  ~ResourcesManager();
  void set_upgrades_manager(UpgradesManager*);

  // GETTERS
  Physics::Time get_time_until_in_stock(const Price& price) const;
  Physics::Time get_time_until_in_stock(const Resource_ID& resource_id,BigNum amount) const;
  BigNum get_resource_amount(Resource_ID) const;
  std::string get_resource_name(Resource_ID) const;

  // SETTERS
  void add_resource_amount(Resource_ID, BigNum amount);

  // MISC
  ResourcesManager& operator=(ResourcesManager&);
  void gather_resources(Physics::Time elapsed_time);
  void pay_price(Price);



};

#endif // RESOURCESMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
