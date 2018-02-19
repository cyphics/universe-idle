// Resource.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "ship/Resource.h"
#include "main/game_global_variables.h"


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

std::string Resource::get_name() const
{
  return global::resource_name(_resource_id);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
