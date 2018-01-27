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

GameController::~GameController(){

}

void GameController::update()
{
  QString output = QString::fromStdString(_my_game->state().get_acceleration().to_string());
  emit send_data(output);
}
void GameController::wait(Time time)
{
  _my_game->wait(time);
  //emit updateUI(_my_game->ui_data());
}

void GameController::click()
{
  _my_game->click();
}

void GameController::receive_data(std::string data)
{
  emit send_data(QString::fromStdString(data));
}

void GameController::send_data(QString data)
{
  send_data(data);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
