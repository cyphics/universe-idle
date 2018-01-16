// Initiate.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef INITIATE_H
#define INITIATE_H 1

#include "../class/UpgradesList.h"
#include "../class/ResourcesList.h"
#include "../class/UpgradesManager.h"
#include "../class/ResourcesManager.h"

namespace Init{

UpgradesManager& initiate_ugprades_manager(UpgradesList&, ResourcesList&);
ResourcesManager& initiate_resources_manager(UpgradesList&, ResourcesList&);
UpgradesList initiate_upgrades_list();
ResourcesList initiate_resources_list();

}


#endif // INITIATE_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
