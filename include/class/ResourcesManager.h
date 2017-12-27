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
#include "../helpers/resources_helper.h"

class UpgradesManager;

class ResourcesManager{
  /**
   * Class that manages the resources of the game.
     Gets a pointer to the stock of resources, and to
     the upgrades manager
   */
 private:
  ResourcesList* _stock_of_resources;
  UpgradesManager* _upgrades_manager;


 public:
  ResourcesManager(ResourcesList*, UpgradesManager*);
  ~ResourcesManager();
  void gather_resources(Time elapsed_time);
  Time get_time_until_in_stock(Price price) const;
  const ResourcesList* get_resources_list() const;
};

#endif // RESOURCESMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
