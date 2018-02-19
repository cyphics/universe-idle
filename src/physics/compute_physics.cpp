// compute_physics.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <cmath>
#include <limits>
#include <assert.h>
#include "physics/compute_physics.h"



Time Physics::remaining_time(const Distance& distance_to_travel,const  Speed& current_speed, const Acceleration& acceleration)
{
  /*
     Return time it takes to travel distance with given speed and acceleration

    d=v0t+(at^2/2)d=v0t+(at^2/2)
    =>
    t = ( -2v0 +- sqrt( pow(2v0) + 4a * 2d ) ) / 2a
  */

  if (distance_to_travel.num() < 0) {
    throw std::string("Can't compute remainng time with negative distance");
  }
  else if (current_speed.num() < 0) {
    throw std::string("Can't compute remainng time with negative speed");
  }
  else if (acceleration.num() < 0) {
    throw std::string("Can't compute remainng time with negative acceleration");
  }


  if (acceleration.num() == 0) {
    if (current_speed.num() == 0) {
      return Time(std::numeric_limits<double>::infinity());
    }
    return distance_to_travel.num() / current_speed.num();
  }

  BigNum delta =sqrt( pow(2 * current_speed.num().get_value(), 2) + 8 * acceleration.num().get_value() * distance_to_travel.num().get_value() );

  BigNum numerator_one = -2 * current_speed.num() + delta;
  BigNum numerator_two = -2 * current_speed.num() - delta;
  BigNum denominator = 2 * acceleration.num();

  BigNum answer_one = numerator_one / denominator;
  BigNum answer_two = numerator_two / denominator;


  if (answer_one > answer_two) return answer_one;
  else return answer_two;
}


Distance Physics::traveled_distance(const Speed& init_speed, const Time& duration, const Acceleration& acceleration)
{
  /**
   * Return the distance traveled at current speed, during given duration
   */

  // dist = init_speed * duration + 1/2 acceleration * duration^2

  Distance new_dist = init_speed.num() * duration.num() \
                      + 0.5 * acceleration.num() \
                      * duration.num() * duration.num();
  return new_dist;
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//
