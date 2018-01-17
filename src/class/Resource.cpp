// Resource.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Resource.h"
#include "../../include/helpers/computations.h"
#include "../../include/helpers/game_global_variables.h"


Resource::Resource(Resource_ID resource_id)
    :_resource_id(resource_id)
{}

Resource::~Resource(){}

BigNum Resource::get_current_amount() const
{
  return _amount;
}

bool Resource::has_id(Resource_ID resource_id) const
{
  return resource_id == _resource_id;
}

Resource_ID Resource::get_ID() const
{
  return _resource_id;
}

void Resource::add_resource_amount(BigNum amount)
{
  _amount +=  amount;
}

void Resource::substract_resource_amount(BigNum amount)
{
  _amount -=  amount;
}

BigNum Resource::get_amount_per_second(const UpgradesManager* upgradesManager) const
{
  return computation::get_resource_per_second(_resource_id, upgradesManager);
}

std::string Resource::get_name() const
{
  return global::resource_name(_resource_id);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
