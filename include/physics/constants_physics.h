// constants_physics.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef CONSTANTS_PHYSICS_H
#define CONSTANTS_PHYSICS_H 1

#include <map>
#include "Distance.h"
#include "Time.h"

namespace Physics
{

namespace UnitsName
{

enum class Distance{meter, kilometer, lightyear, astro_unit};
enum class Time{second, minute, hour, day, year};

}


namespace Units{

// Distance unit definitions
static Distance meter = Distance(BigNum(1, 18));
static Distance kilometer = meter * 1000;
//static Distance astro_unit = meter * 149597870700;
static Distance astro_unit = kilometer * 14959787.07;
//static Distance light_year = kilometer * 9460730472580;
static Distance light_year = astro_unit * 63241;
//static Distance parsec = kilometer * 30856775814671;
//static Distance parsec = kilometer * 30856775814671;
static Distance hubble_length = light_year * 14.4;

// Some other important distances
static Distance diameter_galaxy = light_year * 30000;
static Distance space_between_galaxies = light_year * 3000000; // 3 million
static Distance diameter_universe = light_year * 91000000000000.0; // 91 billion

static Time second = Time(1);
static Time minute = second * 60;
static Time hour = minute * 60;
static Time day = hour * 24;
static Time year = day * 365;
static Time galactical_year = year * 250000000;

}


//std::map<Units::DistanceUnit, Distance> DistanceConstants({ {Units::DistanceUnit::meter, meter}, {Units::Distance::kilometer, kilometer} });


//static const std::map<Upgrade_ID, std::string> output({ {Upgrade_ID::small_boost, "Small boost"}, {Upgrade_ID::big_boost, "Big boost"}, {Upgrade_ID::empty_upgrade, "Empty upgrade"} });
}


#endif // CONSTANTS_PHYSICS_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
