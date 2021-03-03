#include<string>

using namespace std;

#pragma once

enum class Color { black, red, none };

class Case {
  private:
    int nbOfPieces;
    Color caseColor;

  public:
    Case();
    bool isEmpty();
    bool isOccupied();             // 1 at least
    bool iStacked();		// 2 or more
    Color getColor();
    int getNbPieces();
    void setNbPieces(int nbInput);
    void setColor(Color colorInput);

};