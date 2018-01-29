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
const static Distance meter = Distance(BigNum(1, 18));
const static Distance kilometer = meter * 1000;
const static Distance astro_unit = kilometer * 14959787.07;
const static Distance light_year = astro_unit * 63241;
//static Distance parsec = kilometer * 30856775814671;
const static Distance hubble_length = light_year * 14.4;

// Some other important distances
const static Distance nanometer = meter * pow(10, -9);
const static Distance angstrom = meter * pow(10, -10);
const static Distance diameter_galaxy = light_year * 30000;
const static Distance space_between_galaxies = light_year * 3000000; // 3 million
const static Distance diameter_universe = light_year * 91000000000000.0; // 91 billion

const static Time second = Time(1);
const static Time minute = second * 60;
const static Time hour = minute * 60;
const static Time day = hour * 24;
const static Time year = day * 365;
const static Time galactical_year = year * 250000000;

}



}


#endif // CONSTANTS_PHYSICS_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
