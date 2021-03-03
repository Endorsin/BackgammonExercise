#include "Game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;


// Constructor
Game::Game() {
  currTurn = 0;    // red = 0, black = 1
  isEndGame = true;    // FIXME

  srand(time(0));    // inital seed for random generator

}



// The main method acting as an "engine" that will manage all of the functionalities
void Game::run() {
  cout << "Game is running" << endl;
  bool win;

  gameInit();

  do {
    startAMove();
  } while(isEndGame);
}

// Serves as a UI to the players
void Game::printGame(){
  char piece;

  if (currTurn == 0){
    cout << "Player red [o] to make a move: " << endl;
  }else{
    cout << "Player black [x] to make a move: " << endl;
  }
  cout << endl;

  for (int i = 0; i < this->gameBoard.getCases().size(); i++){
    cout << i + 1 << " ";

    if(this->gameBoard.getCases().at(i).getColor() == Color::none){
      piece = ' ';
    }else if(this->gameBoard.getCases().at(i).getColor() == Color::red){
      piece = 'o';
    }else{
      piece = 'x';
    }
    for(int y = 0; y < this->gameBoard.getCases().at(i).getNbPieces(); y++){
      //something here
        cout << piece;
      
    }
    cout << endl;
  }
  cout << endl;
}

// Called once, initializes the starting variables and objects of the game
void Game::gameInit(){
  cout << "Game is initializing" << endl;
  int choiceColor;

  //cout << "Enter player 1 name's"
  Player player1("Player1", Color::red);
  Player player2("Player2", Color::black);

  do{
  cout << "Player 1 choose color (red = 0 or black = 1): ";
  cin >> choiceColor;
  cout << endl;

  } while(choiceColor != 0 && choiceColor != 1);

  if(choiceColor == 0){

    Player player1("Player1", Color::red);
    Player player2("Player2", Color::black);
    this->playerRed = player1;
    this->playerBlack = player2;
  }else{
    Player player1("Player1", Color::black);
    Player player2("Player2", Color::red);
    this->playerRed = player2;
    this->playerBlack = player1;
  }
  
  Board newBoard;

  this->gameBoard = newBoard;

  this->gameBoard.initCases();

  

}
/*
Traditionally, the starting position is as follows:Red (who moves from low to high numbers):  Two stones on point #1, five on #12, three on #17, five on #19.  Black (who moves from high to low numbers):  Two stones on point #24, five on #13, three on #8, five on #6. 
*/

// Manages the logic behind making a move
void Game::startAMove() {
  int startLane;
  bool validMove = true;
  
  currRoll = rollDices();
  cout << "You rolled a "  << currRoll.at(0) << " and a " << currRoll.at(1) << endl;

  // loop two moves
  for (int i = 0; i < 2; i++){
    do {
      printGame();
      // check any valid move is possible at all
      if (gameBoard.checkAnyPosMoves(currTurn, currRoll.at(i)) == false) {
        cout << "Sorry, no moves are possible with your dice rolls. Next Turn!" << endl << endl;
        break;
      }


      cout << "Choose a lane: ";
      cin >> startLane;

      validMove = movePiece(startLane, i);

      if (!validMove) {
        cout << "Sorry, not a valid move" << endl;
      }
    } while (!validMove);
    
  }

  currTurn = (currTurn + 1)%2;
}

// Roll two dices
vector<int> Game::rollDices() {
  vector<int> newRoll;
  newRoll.push_back((rand()%6)+1);
  newRoll.push_back((rand()%6)+1);

  return newRoll;
}


bool Game::movePiece(int startLane, int diceNb) {
  bool validMove = false;

  // check bounds
  if(gameBoard.checkValidEntry(startLane, currTurn)){
    
    // check if move to safe zone
    if(currTurn == 0 && (startLane + currRoll.at(diceNb)) > 24){
      
      if (gameBoard.checkIfGoalMove(startLane, currRoll.at(diceNb), currTurn)){
        gameBoard.doIfGoalMove(startLane, currRoll.at(diceNb), currTurn);
        cout << "#1 if" << endl;
        validMove = true;
      }
    }

    // capture movement
    if (gameBoard.checkIfCapture(startLane, currRoll.at(diceNb), currTurn)) {
      gameBoard.doIfCapture(startLane, currRoll.at(diceNb), currTurn);
      cout << "#2 if" << endl;
      validMove = true;
    } 


    if(gameBoard.checkMove(startLane, currRoll.at(diceNb), currTurn)){
      gameBoard.doMove(startLane, currRoll.at(diceNb), currTurn);
      cout << "#3 if" << endl;
      validMove = true;
    }
  }

  return validMove;
}


// Accessor
Player Game::getPlayerRed() {
  return this->playerRed;
}

// Accessor
Player Game::getPlayerBlack() {
  return this->playerBlack;
}