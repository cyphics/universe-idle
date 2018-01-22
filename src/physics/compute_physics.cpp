// compute_physics.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <cmath>
#include "physics/compute_physics.h"



Time compute_remaining_time(Distance distance_to_travel, Speed current_speed, Acceleration acceleration)
{

  /*
    d=v0t+(at2/2)d=v0t+(at2/2)
    =>
    t = ( -2v0 +- sqrt( pow(2v0) + 4a * 2d ) ) / 2a
  */

  BigNum delta =sqrt( pow(2 * current_speed.num().get_value(), 2) + 8 * acceleration.num().get_value() * distance_to_travel.num().get_value() );

  BigNum numerator_one = -2 * current_speed.num() + delta;
  BigNum numerator_two = -2 * current_speed.num() - delta;
  BigNum denominator = 2 * acceleration.num();

  BigNum answer_one = numerator_one / denominator;
  BigNum answer_two = numerator_two / denominator;

  if (answer_one > answer_two) return answer_one;
  else return answer_two;
}

Distance compute_distance_traveled(Speed initial_speed, Time duration, Acceleration acceleration)
{
  return Distance(initial_speed.num() * duration.num() + ( acceleration.num() * pow(duration.num().get_value(), 2) ) / 2);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
