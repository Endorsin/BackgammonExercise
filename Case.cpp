#include "Case.h"
// Constructor
Case::Case() {
  nbOfPieces = 0;
  caseColor = Color::none;
}


//Case is empty
bool Case::isEmpty() {
  return nbOfPieces  == 0;
}

// Verify is a case is occupied by at least one piece, allowing a potential capture
bool Case::isOccupied() {
  return nbOfPieces  == 1;
}

// Verify is a case is occupied by at least two pieces, preventing a capture
bool Case::iStacked() {
  return nbOfPieces >= 2;
}

// Accessor
Color Case::getColor() {
  return caseColor;
}

// Accessor
int Case::getNbPieces() {
  return nbOfPieces;
}

// Mutator
void Case::setNbPieces(int nbInput){
  nbOfPieces = nbInput;
}

// Mutator
void Case::setColor(Color colorInput){
  caseColor = colorInput;
}
