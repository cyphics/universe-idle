// game_global_variables.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef GAME_GLOBAL_VARIABLES_H
#define GAME_GLOBAL_VARIABLES_H 1

// game_global_variables.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <map>

#include "../../include/helpers/upgrades_helper.h"
#include "../../include/helpers/resources_helper.h"

namespace global{


std::map<Upgrade_ID, std::string> upgrades_name_list();

std::map<Resource_ID, std::string> resources_name_list();

std::string upgrade_name(Upgrade_ID upgrade_id);

std::string resource_name(Resource_ID resource_id);


}
//////////////////////////////////////////////////////////////////////
// $Log:$
//


#endif // GAME_GLOBAL_VARIABLES_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
