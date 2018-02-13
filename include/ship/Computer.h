// Computer.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef COMPUTER_H
#define COMPUTER_H 1

#include "UpgradesManager.h"
#include "ResourcesManager.h"
#include "physics/Time.h"
#include "managment/GameState.h"

class Computer
{
 private:
  UpgradesManager* _upgrades;
  //ResourcesManager* _resources;
  GameState* _state;

 public:
  Computer(UpgradesManager* upgrades, GameState* state);
  BigNum resource_per_second(Resource_ID resource) const;
};


#endif // _H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
