#include "tour.h"
#include "iostream"
#include "piece.h"

using namespace std;

Tour::Tour(bool white, bool pos) : Piece(pos?1:8,white?1:8,white)
{
}

Tour::~Tour(){
//cout << "Destruction Tour" << endl;
}

bool
Tour::mouvementValide(Echiquier &e, int x , int y){

}

char
Tour::toChar() const
{
  return m_white?'T':'t';
}
