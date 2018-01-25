// Initiate.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef INITIATE_H
#define INITIATE_H 1

#include "ship/UpgradesList.h"
#include "ship/ResourcesList.h"
#include "ship/UpgradesManager.h"
#include "ship/ResourcesManager.h"

namespace Init{

std::vector<Resource> initiate_resources_list();
std::vector<Upgrade> initiate_upgrades_list();
UpgradesManager& initiate_upgrades_manager();
ResourcesManager& initiate_resources_manager();

}


#endif // INITIATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
