// constant_distances.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef CONSTANT_DISTANCES_H
#define CONSTANT_DISTANCES_H 1

#include <map>
#include "util/BigNum.h"
//#include "Distance.h"

namespace Physics
{

enum class DistanceUnit
{
  yoctometer,
  zeptometer,
  attometer,
  femtometer,
  picometer,
  nanometer,
  micrometer,
  millimeter,
  meter,
  kilometer,
  lightyear,
  astro_unit,
  radius_proton,
  radius_gold_nucleus,
  radius_hydrogen,
  radius_carbon,
  red_lightwave,
  diameter_adn_helix,
  diameter_hair,
  diameter_galaxy,
  space_between_galaxies,
  diameter_universe
};

static const std::vector<DistanceUnit> distance_units
{
  DistanceUnit::yoctometer,
      DistanceUnit::zeptometer,
      DistanceUnit::attometer,
      DistanceUnit::femtometer,
      DistanceUnit::picometer,
      DistanceUnit::nanometer,
      DistanceUnit::micrometer,
      DistanceUnit::millimeter,
      DistanceUnit::meter,
      DistanceUnit::kilometer,
      DistanceUnit::lightyear,
      DistanceUnit::astro_unit,
      DistanceUnit::radius_proton,
      DistanceUnit::radius_gold_nucleus,
      DistanceUnit::radius_hydrogen,
      DistanceUnit::radius_carbon,
      DistanceUnit::diameter_adn_helix,
      DistanceUnit::diameter_hair,
      DistanceUnit::diameter_galaxy,
      DistanceUnit::space_between_galaxies,
      DistanceUnit::diameter_universe
      };

namespace value
{
const static BigNum yoctometer = BigNum(1);
const static BigNum zeptometer = yoctometer * pow(10,3);
const static BigNum attometer = yoctometer * pow(10,6);
const static BigNum femtometer = yoctometer * pow(10,9);
const static BigNum picometer = yoctometer * pow(10,12);
const static BigNum nanometer = yoctometer * pow(10,15);
const static BigNum micrometer = yoctometer * pow(10,18);
const static BigNum millimeter = yoctometer * pow(10,21);
const static BigNum meter = yoctometer * pow(10,24);
const static BigNum kilometer = meter * 1000;
const static BigNum astro_unit = kilometer * 14959787.07;
const static BigNum light_year = astro_unit * 63241;

// Some other important distances
const static BigNum radius_proton = femtometer * 0.8;
const static BigNum radius_gold_nucleus = femtometer * 8.45;
const static BigNum radius_hydrogen = picometer * 25;
const static BigNum radius_carbon = picometer * 60;
const static BigNum angstrom = meter * pow(10, -10);
const static BigNum red_lightwave = nanometer * 700;
const static BigNum diameter_adn_helix = nanometer * 2;
const static BigNum diameter_hair = micrometer * 75;
const static BigNum diameter_galaxy = light_year * 30000;
const static BigNum space_between_galaxies = light_year * 3000000; // 3 million
const static BigNum diameter_universe = light_year * 91000000000000.0; // 91 billion
}

std::map<DistanceUnit, std::string> distance_units_names();
std::string distance_name(DistanceUnit dist);
std::map<DistanceUnit, BigNum> distance_units_values();
BigNum distance_value(DistanceUnit dist);
DistanceUnit distance_unit_from_string(std::string);

} // End of Physics namespace


#endif // CONSTANT_DISTANCES_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
