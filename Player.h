#include <string>
#include "Board.h"
#pragma once

using namespace std;

class Player {
  private:
    string name;
    int numCaptured;
    int numPassed;
    bool isFinalZone; 
    Color playerColor;

  public:
    Player();
    Player(string name, Color color);
    bool checkFinalZone();
    bool canPlay(Board board);  // board comes from Game
    string getName();
    int getNbCapturedP();
    int getNbPassedP();
};

