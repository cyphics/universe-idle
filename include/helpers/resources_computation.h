// resources_computation.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCES_COMPUTATION_H
#define RESOURCES_COMPUTATION_H 1

//#include "../class/BigNum.h"
//#include "../class/Resource.h"
//#include "../class/UpgradesList.h"
//#include "../class/Time.h"

class BigNum;
class Time;
class UpgradesList;

BigNum compute_cinetic_energy(Time elapsed_time, const UpgradesList& list_of_upgrades);
BigNum compute_dark_matter(Time elapsed_time, const UpgradesList& list_of_upgrades);


#endif // RESOURCES_COMPUTATION_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
