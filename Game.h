#include "Player.h"
#include "Board.h"


#pragma once
class Game{
  private:
    // enum class turn { black, red };
    int currTurn;

    bool isEndGame;
    Player playerRed;
    Player playerBlack;
    Board gameBoard;

    vector<int> currRoll;
    vector<int> rollDices();
    
    void printGame();
    void gameInit();
    void startAMove();
    bool movePiece(int startLane, int i);

  public:
    void run();
    Game();
    Player getPlayerRed();
    Player getPlayerBlack();
};

