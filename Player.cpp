#include "Player.h"

// Constructor
Player::Player() {}

// Constructor
Player::Player(string username, Color color) {
  this->name = username;
  this->playerColor = color;
}

// FIXME
// Accessor
bool Player::checkFinalZone() {
  return false;
}

// FIXME
// Accessor
bool Player::canPlay(Board board) {
  return false;
}

// Accessor
string Player::getName() {
 return name;
}

// Accessor
int Player::getNbCapturedP() {
  return numCaptured;
}

// Accessor
int Player::getNbPassedP() {
  return numPassed;
}