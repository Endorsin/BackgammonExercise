#include <tuple>
#include <vector>
#include "Case.h"

#pragma once
class Board {
  private:
  vector <Case> cases;
  tuple <int, int> dices;
    
  public:
    Board();
    vector<Case> getCases();
    tuple <int, int> rollDice();
    bool playMove(int lane, int number);
    
    bool checkAnyPosMoves(int currentTurn, int number);

    bool checkValidEntry(int lane, int currentTurn);
    bool checkValidLane(int lane);
    bool checkValidLaneColor(int lane, int currentTurn);

    bool checkIfCapture(int lane, int currentTurn, int number);
    void doIfCapture(int lane, int currentTurn, int number);

    bool checkIfGoalMove(int lane, int currentTurn, int number);
    void doIfGoalMove(int lane, int currentTurn, int number);

    bool checkMove(int lane, int number, int currentTurn);
    void doMove(int lane, int number, int currentTurn);

    void initCases();

    void initCases2(){


  cases.at(23).setNbPieces(5);
  cases.at(23).setColor(Color::red);

    }

   void initCases3(){


  cases.at(0).setNbPieces(2);
  cases.at(0).setColor(Color::red);

  cases.at(1).setNbPieces(1);
  cases.at(1).setColor(Color::black);

  cases.at(2).setNbPieces(1);
  cases.at(2).setColor(Color::black);

  cases.at(3).setNbPieces(1);
  cases.at(3).setColor(Color::black);

  cases.at(4).setNbPieces(1);
  cases.at(4).setColor(Color::black);

  cases.at(5).setNbPieces(1);
  cases.at(5).setColor(Color::black);

   cases.at(6).setNbPieces(1);
  cases.at(6).setColor(Color::black);

  }




    //Valid lane on board
    //if(lane > 0 && lane < 25){

      //Piece of the players color in lane

};