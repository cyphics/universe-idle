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
      {DistanceUnit::yoctometer, "yoctometer"},
      {DistanceUnit::zeptometer, "zeptometer"},
      {DistanceUnit::attometer,  "attometer"},
      {DistanceUnit::femtometer, "femtometer"},
      {DistanceUnit::picometer,  "picometer"},
      {DistanceUnit::nanometer,  "nanometer"},
      {DistanceUnit::micrometer, "micrometer"},
      {DistanceUnit::millimeter, "millimeter"},
      {DistanceUnit::meter,      "meter"},
      {DistanceUnit::kilometer,  "kilometer"},
      {DistanceUnit::lightyear,  "lightyear"},
      {DistanceUnit::astro_unit, "astonomical unit"},
          }
    );

  return physics_units_name_list;
}

std::string Physics::distance_name(DistanceUnit unit)
{
  return distance_units_names().find(unit)->second;
}

// std::map<Physics::DistanceUnit, BigNum> Physics::physical_units_values()
// {
//   /**
//    * Return a static (unique) const dictionary linking distance units to their value
//    */

//   // dist_values

//   static const std::map<DistanceUnit, BigNum> physical_units_values({
//       {DistanceUnit::yoctometer, value::yoctometer},
//       {DistanceUnit::zeptometer, value::zeptometer},
//       {DistanceUnit::attometer,  value::attometer},
//       {DistanceUnit::femtometer, value::femtometer},
//       {DistanceUnit::picometer,  value::picometer},
//       {DistanceUnit::nanometer,  value::nanometer},
//       {DistanceUnit::micrometer, value::micrometer},
//       {DistanceUnit::millimeter, value::millimeter},
//       {DistanceUnit::meter,      value::meter},
//       {DistanceUnit::kilometer,  value::kilometer},
//       {DistanceUnit::lightyear,  value::light_year},
//       {DistanceUnit::astro_unit, value::astro_unit},
//           }
//     );

//   return physical_units_values;
// }


// BigNum Physics::distance_value(DistanceUnit dist)
// {
//   return Physics::distance_units_values().find(dist)->second;
// }



//////////////////////////////////////////////////////////////////////
// $Log:$
//
