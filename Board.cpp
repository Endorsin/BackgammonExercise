#include "Board.h"
#include <iostream>

using namespace std;

// Constructor
Board::Board() {
  Case caseFill;
  for (int i = 0; i < 24; i++){
    cases.push_back(caseFill);
  }
}

// Accessor
vector<Case> Board::getCases(){
  return cases;
}

 //Valid lane on board
bool Board::checkValidLane(int lane){
  return (lane > 0 && lane < 25);
}

//Valid if the lane contains the piece of the player color
bool Board::checkValidLaneColor(int lane, int currentTurn){
  return ((currentTurn == 0 && cases.at(lane-1).getColor() == Color::red && !(cases.at(lane-1).isEmpty()))
         || (currentTurn == 1 && cases.at(lane-1).getColor() == Color::black && !(cases.at(lane-1).isEmpty())));
}

//Valid if the lane chosen is ok
bool Board::checkValidEntry(int lane, int currentTurn){
  //Valid move
    bool ok = false;
    //Valid lane on board
    if(checkValidLane(lane)){
      //Piece of the players color in lane
      if(checkValidLaneColor(lane, currentTurn)){                 
      }
    }
    return  (checkValidLane(lane)) && (checkValidLaneColor(lane, currentTurn));
}

//Check if a piece was captured from the other player
bool Board::checkIfCapture(int lane, int currentTurn, int number){
  bool ok = false;

  if(currentTurn == 0 && cases.at(lane + number - 1).getColor() == Color::black
      && cases.at(lane + number - 1).isOccupied()){

    ok = true;

  }else if(currentTurn == 1 && cases.at(lane + number - 1).getColor() == Color::red
      && cases.at(lane + number - 1).isOccupied()){

    ok = true;
  }
  return ok;
}

// Execute order 66
void Board::doIfCapture(int lane, int currentTurn, int number){
  if(currentTurn == 0){ // red
    cases.at(lane + number - 1).setColor(Color::black);
  }else{    // black
    cases.at(lane + number - 1).setColor(Color::red);
  }
}


//Check if move is on stack of the other player
bool Board::checkMove(int lane, int number, int currentTurn){
  bool ok = true;

  if (currentTurn == 0 && cases.at(lane + number - 1).getColor() == Color::black 
      && cases.at(lane + number - 1).iStacked()){
    ok = false;

  }else if (currentTurn == 1 && cases.at(lane + number - 1).getColor() == Color::red 
      && cases.at(lane + number - 1).iStacked()){
    ok = false;
  }
  return ok;
}

void Board::doMove(int lane, int number, int currentTurn){
  cases.at(lane - 1).setNbPieces(cases.at(lane -1 ).getNbPieces() - 1);
  cases.at(lane - 1 + number).setNbPieces(cases.at(lane - 1 + number).getNbPieces() + 1);
  if (currentTurn == 0){
      cases.at(lane - 1 + number).setColor(Color::red);
  }else{
      cases.at(lane - 1 + number).setColor(Color::black);
  }
}

//Check if valid goal move (doesnt look if the move reach goal)
bool Board::checkIfGoalMove(int lane, int currentTurn, int number){
  bool ok= true;
  if(currentTurn == 0){
    for(int i = 0; i < 18; i++){
      if(cases.at(i).getColor() == Color::red && !cases.at(i).isEmpty()){
        ok = false;
        break;
      }
    }
  }else{
    for(int i = 23; i > 5; i--){
      if(cases.at(i).getColor() == Color::black && !cases.at(i).isEmpty()){
        ok = false;
        break;
      }
    }
  } 
  return ok;
}

void Board::doIfGoalMove(int lane, int currentTurn, int number){
  cases.at(lane-1).setNbPieces(cases.at(lane-1).getNbPieces() - 1);
}

bool Board::checkAnyPosMoves(int currentTurn, int number) {
  bool ok = false;
  int i = 0;
  
  while( i < 24 && !ok){
  
    if(checkValidEntry(i, currentTurn)){
      // check if move to safe zone
      if(currentTurn == 0 && (i + number > 24)) {
        cout << "#2 if" << endl;
        ok = (checkIfGoalMove(i, number, currentTurn));
      }

      // capture movement
      if (checkIfCapture(i, number, currentTurn)) {
        cout << "#3 if" << endl;
        ok = true;
      } 
      if(checkMove(i, number, currentTurn)){
        ok = true;
      } 
      
    }
    i++;
  }

  return ok;
}




// Initializer for the starting cases in the game, called once per game
/*
Traditionally, the starting position is as follows:Red (who moves from low to high numbers):  Two stones on point #1, five on #12, three on #17, five on #19.  Black (who moves from high to low numbers):  Two stones on point #24, five on #13, three on #8, five on #6. 
*/

void Board::initCases() {
  cout << "Board is initializing" << endl;
  // cases.push_back(    )
  // cases.at(1)

  cases.at(0).setNbPieces(2);
  cases.at(0).setColor(Color::red);

  cases.at(11).setNbPieces(5);
  cases.at(11).setColor(Color::red);

  cases.at(16).setNbPieces(3);
  cases.at(16).setColor(Color::red);

  cases.at(18).setNbPieces(5);
  cases.at(18).setColor(Color::red);

  cases.at(23).setNbPieces(2);
  cases.at(23).setColor(Color::black);

  cases.at(12).setNbPieces(5);
  cases.at(12).setColor(Color::black);

  cases.at(7).setNbPieces(3);
  cases.at(7).setColor(Color::black);

  cases.at(5).setNbPieces(5);
  cases.at(5).setColor(Color::black);

}







