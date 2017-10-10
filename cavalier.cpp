#include <iostream>

#include "cavalier.h"

using namespace std;

Cavalier::Cavalier(bool white, bool pos) : Piece(pos?2:7,white?1:8,white)
{
//cout << "Construction Cavalier" << endl;
}

Cavalier::~Cavalier()
{
//cout << "Destruction Cavalier" << endl;
}

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
  //cout << "mouvementValide Cavalier" << endl;
  return true;
}


char
Cavalier::toChar() const
{
  return m_white?'C':'c';
}
