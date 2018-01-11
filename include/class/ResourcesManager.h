// ResourcesManager.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H 1

#include "Time.h"
#include "ResourcesList.h"
#include "UpgradesManager.h"
#include "Price.h"
#include "../helpers/resources_helper.h"

class UpgradesManager;

class ResourcesManager{
  /**
   * Class that manages the resources of the game.
     Gets a reference to the stock of resources, and to
     the upgrades manager
   */
 private:
  ResourcesList _stock_of_resources;
  UpgradesManager* _upgrades_manager;

  // Private methods
  Resource& get_real_resource(Resource_ID resource);
  const Resource& get_real_resource(Resource_ID resource) const;

 public:
  ResourcesManager();
  ResourcesManager(const ResourcesManager& original);
  ~ResourcesManager();

  void init_manager(ResourcesList, UpgradesManager*);

  // Getters
  Time get_time_until_in_stock(const Price& price) const;
  Time get_time_until_in_stock(const Resource_ID& resource_id,BigNum amount) const;
  const ResourcesList& get_resources_list() const;
  ResourcesList& get_resources_list();
  BigNum get_resource_amount(Resource_ID) const;

  ResourcesManager& operator=(ResourcesManager&);

  void gather_resources(Time elapsed_time);



};

#endif // RESOURCESMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
