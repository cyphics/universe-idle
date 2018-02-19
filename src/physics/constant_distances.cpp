// constants_physics.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "physics/constant_distances.h"
#include <map>


std::map<Physics::DistanceUnit, std::string> Physics::distance_units_names()
{
  /**
   * Return a static (unique) const dictionary linking distance units to the name of the unit name
   */

  // dist_names

  static const std::map<DistanceUnit, std::string> physics_units_name_list({
      {DistanceUnit::yoctometer,          "yoctometer"},
      {DistanceUnit::zeptometer,          "zeptometer"},
      {DistanceUnit::attometer,           "attometer"},
      {DistanceUnit::femtometer,          "femtometer"},
      {DistanceUnit::picometer,           "picometer"},
      {DistanceUnit::nanometer,           "nanometer"},
      {DistanceUnit::micrometer,          "micrometer"},
      {DistanceUnit::millimeter,          "millimeter"},
      {DistanceUnit::meter,               "meter"},
      {DistanceUnit::kilometer,           "kilometer"},
      {DistanceUnit::lightyear,           "lightyear"},
      {DistanceUnit::astro_unit,          "astonomical unit"},
      {DistanceUnit::radius_proton,       "Proton radius"},
      {DistanceUnit::radius_gold_nucleus, "Gold nucleus radius"},
      {DistanceUnit::radius_hydrogen,     "Hydrogen radius"},
      {DistanceUnit::radius_carbon,       "Carbon radius"},
      {DistanceUnit::red_lightwave,       "Red lightwave"},

          }
    );

  return physics_units_name_list;
}

std::string Physics::distance_name(DistanceUnit unit)
{
  std::map<Physics::DistanceUnit, std::string>::iterator name_map = distance_units_names().find(unit);
  std::string output;
  if (name_map != distance_units_names().end()) {
    return distance_units_names().find(unit)->second;
  }
  else
    return "unknown unit";

}

std::map<Physics::DistanceUnit, BigNum> Physics::distance_units_values()
{
  /**
   * Return a static (unique) const dictionary linking distance units to their value
   */

  // dist_values

  static const std::map<DistanceUnit, BigNum> physical_units_values({
      {DistanceUnit::yoctometer, value::yoctometer},
      {DistanceUnit::zeptometer, value::zeptometer},
      {DistanceUnit::attometer,  value::attometer},
      {DistanceUnit::femtometer, value::femtometer},
      {DistanceUnit::picometer,  value::picometer},
      {DistanceUnit::nanometer,  value::nanometer},
      {DistanceUnit::micrometer, value::micrometer},
      {DistanceUnit::millimeter, value::millimeter},
      {DistanceUnit::meter,      value::meter},
      {DistanceUnit::kilometer,  value::kilometer},
      {DistanceUnit::lightyear,  value::light_year},
      {DistanceUnit::astro_unit, value::astro_unit},
      {DistanceUnit::radius_proton, value::radius_proton},
      {DistanceUnit::radius_gold_nucleus, value::radius_gold_nucleus},
      {DistanceUnit::radius_hydrogen, value::radius_hydrogen},
      {DistanceUnit::radius_carbon, value::radius_carbon},
      {DistanceUnit::red_lightwave, value::red_lightwave},
          }
    );

  return physical_units_values;
}


BigNum Physics::distance_value(DistanceUnit dist)
{
  return Physics::distance_units_values().find(dist)->second;
}

Physics::DistanceUnit Physics::distance_unit_from_string(std::string name)
{
  std::map<DistanceUnit, std::string>::iterator it;

  for (auto const& elem : Physics::distance_units_names()) {
    if (elem.second == name)
      return elem.first;
  }


std::cout << "Error, DistanceUnit key not found from value " << name  << "\n";
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
