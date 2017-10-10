/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "piece.h"
#include "echiquier.h"
#include "iostream"

using namespace std;

Piece::Piece()
{
}

Piece::Piece(int x, int y, bool white)
{
    m_x = x;
    m_y = y;
    m_white = white;



}

Piece::~Piece()
{
}

Piece::Piece(const Piece & autre){

    m_x = autre.m_x;
    m_y = autre.m_y;
    m_white = autre.m_white;

}

Piece &
Piece::operator=(const Piece &autre){

    m_x = autre.m_x;
    m_y = autre.m_y;
    m_white = autre.m_white;

    return *this;
}





void
Piece::init( int x, int y, bool white )
{
    m_x = x;
    m_y = y;
    m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack() const
{
  return !m_white;
}

void
Piece::affiche() const
{
   // cout << "Piece: x=" << m_x << " y=" << m_y << " " << ( m_white ? "blanche" : "noire" ) << endl;

}

Piece Piece::plusForteQue(const Piece & p) const {
    if(true){
        return p;
    }else{
        return *this;
    }
}

bool
Piece::mouvementValide(Echiquier &e, int x , int y){
    return true;
}

char
Piece::toChar() const
{
  return m_white?'B':'N';
}


