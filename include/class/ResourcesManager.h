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
#include "Resource.h"
#include "UpgradesList.h"

class ResourcesManager{
 private:
  UpgradesList* _list_of_upgrades;
  ResourcesList* _stock_of_resources;
 public:
  ResourcesManager(UpgradesList*, ResourcesList*);
  ~ResourcesManager();
  void gather_resources(Time elapsed_time);
};

#endif // RESOURCESMANAGER_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
