// -*- compile-command: "./../../compile.sh"; -*-
// Game.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "../../include/class/Game.h"

Game::Game(){}
Game::~Game(){}

std::string Game::to_string() const{
  /**
   * Return human readable string
   */
  std::string output = "";
  return output;
}

BigNum Game::get_distance() const{
  /**
   * Return traveled distance from beginning
   */
  return _traveled_distance;
}

BigNum Game::get_speed() const{
  /**
   * Return current speed
   */
  return _current_speed;
}

BigNum Game::get_acceleration() const{
  /**
   * Return current acceleration
   */
  return _current_acceleration;
}

unsigned int Game::get_time() const{
  /**
   * Return current time;
   */
  return _current_time;
}



GameState Game::get_gamestate() const{

}

BigNum Game::get_resource(std::string resource_name) const{
  /**
   * Get current level of energy
   */
  //return _current_;
}

unsigned int Game::time_until(Upgrade next_upgrade) const{
  /**
   * return time before you can afford given upgrade
   */

}

unsigned int Game::time_until(std::string next_upgrade_name) const{
  /**
   * return time before you can afford given upgrade
   */

}


void Game::set_distance(){
  /**
   * Set current traveled distance
   */
}

void Game::set_speed(){
  /**
   * set current speed
   */
}

void Game::set_acceleration(){
  /**
   * Set current acceleration
   */
}

void Game::set_time(){
  /**
   * Set current time
   */
}

BigNum Game::compute_new_acceleration(unsigned int time) const{
  BigNum new_acceleration;
  return new_acceleration;
}

BigNum Game::compute_new_speed(unsigned int time) const{
  BigNum new_speed;
  return new_speed;
}

BigNum Game::compute_new_distance(unsigned int time) const{
  BigNum new_distance;
  return new_distance;
}


void Game::wait(unsigned int time){
  /**
   * Postpone game state to given time and update game
   */
}

void Game::buy_upgrade(Upgrade upgrade){
  /**
   * Add ugprade if possible
     If not, do nothing
   */
}

void Game::buy_upgrade(std::string upgrade_name){
  /**
   * Add ugprade if possible
   If not, do nothing
  */
}

void Game::click(){
  /**
   *
   */
}

void update_game_state(){

}



//////////////////////////////////////////////////////////////////////
// $Log:$
//
