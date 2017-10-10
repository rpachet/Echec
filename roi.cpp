#include "roi.h"
#include "iostream"
#include "piece.h"

using namespace std;



Roi::Roi(bool white) : Piece(5,white?1:8,white)
{

}

Roi::~Roi()
{
cout << "Destruction Roi" << endl;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Roi" << endl;
  return true;
}

char
Roi::toChar() const
{
  return m_white?'R':'r';
}

