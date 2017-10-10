#include <iostream>
#include "pion.h"

Pion::Pion(bool white, int pos) : Piece(pos,white?2:7,white)
{
}

Pion::~Pion(){
//cout << "Destruction Tour" << endl;
}

bool
Pion::mouvementValide(Echiquier &e, int x , int y){

}

char
Pion::toChar() const
{
  return m_white?'P':'p';
}
