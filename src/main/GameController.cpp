// GameController.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "main/GameController.h"

GameController::GameController(Game* game)
    : _my_game(game)
{}

GameController::~GameController(){}


void GameController::wait(Time time)
{
  _my_game->wait(time);
  //emit updateUI(_my_game->ui_data());
}

void GameController::click()
{
  _my_game->click();
}


//////////////////////////////////////////////////////////////////////
// $Log:$
//
