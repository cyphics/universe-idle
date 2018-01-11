// -*- compile-command: "./../../compile.sh"; -*-
// Resource.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Resource.h"

Resource::Resource(Resource_ID resource_id, std::string resource_name)
    :_resource_id(resource_id), _resource_name(resource_name)
{}

Resource::~Resource(){}

BigNum Resource::get_current_amount() const{
  return _amount;
}

bool Resource::has_id(Resource_ID resource_id) const{
  return resource_id == _resource_id;
}

Resource_ID Resource::get_ID() const{
  return _resource_id;
}

void Resource::add_resource_amount(BigNum amount){
  _amount +=  amount;
}

void Resource::substract_resource_amount(BigNum amount){
  _amount -=  amount;
}

BigNum Resource::get_amount_per_second() const{
  return _amount_per_second;
}

std::string Resource::get_name() const{
  return _resource_name;
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
