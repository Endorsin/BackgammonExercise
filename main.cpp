#include <iostream>
#include "Game.h"

using namespace std;

// Launcher for the game
int main() {
  cout << "Main started" << endl;

  Game backgammon;

  backgammon.run();

  //backgammon.printGame();
  
  return 0;
}