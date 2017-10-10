#include <iostream>

#include "fou.h"

using namespace std;

Fou::Fou(bool white, bool pos) : Piece(pos?3:6,white?1:8,white)
{
}

Fou::~Fou()
{
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
 // cout << "mouvementValide Fou" << endl;
  return true;
}


char
Fou::toChar() const
{
  return m_white?'F':'f';
}

