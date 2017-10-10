#include "reine.h"
#include "iostream"
#include "piece.h"

using namespace std;

Reine::Reine(bool white) : Piece(4,white?1:8,white)
{
//cout << "Construction Reine" << endl;
}

Reine::~Reine()
{
//cout << "Destruction Reine" << endl;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
//  cout << "mouvementValide Reine" << endl;
  return true;
}


char
Reine::toChar() const
{
  return m_white?'Q':'q';
}


