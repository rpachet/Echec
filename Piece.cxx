/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
 // cout << "Constructeur Piece par defaut" << endl;
}

Roi::Roi(bool white)
{
  m_x=5;
  m_y=(white)?1:8;
  m_white=white;
  cout << "Constructeur Roi" << endl;
}

Reine::Reine(bool white) : Piece(4,white?1:8,white),
                           Fou(white,true),
                           Tour(white,true)
{
//  cout << "Constructeur Reine" << endl;
}

Tour::Tour(bool white, bool pos) : Piece(pos?1:8,white?1:8,white)
{
//  cout << "Constructeur Tour" << endl;
}

Fou::Fou(bool white, bool pos) : Piece(pos?3:6,white?1:8,white)
{
//  cout << "Constructeur Fou" << endl;
}

Cavalier::Cavalier(bool white, bool pos) : Piece(pos?2:7,white?1:8,white)
{
  //cout << "Constructeur Cavalier" << endl;
}

Pion::Pion(bool white, int pos) : Piece(pos,white?2:7,white)
{
  //cout << "Constructeur Pion" << endl;
}

Piece::~Piece()
{
  // ne fait rien => objet instancie mais non valide.
//  cout << "Destructeur Piece" << endl;
}

Roi::~Roi()
{
  // ne fait rien => objet instancie mais non valide.
//  cout << "Destructeur Roi" << endl;
}

Reine::~Reine()
{
  // ne fait rien => objet instancie mais non valide.
  //cout << "Destructeur Reine" << endl;
}

Tour::~Tour()
{
  // ne fait rien => objet instancie mais non valide.
 // cout << "Destructeur Tour" << endl;
}

Fou::~Fou()
{
  // ne fait rien => objet instancie mais non valide.
 // cout << "Destructeur Fou" << endl;
}

Cavalier::~Cavalier()
{
  // ne fait rien => objet instancie mais non valide.
//  cout << "Destructeur Cavalier" << endl;
}

Pion::~Pion()
{
  // ne fait rien => objet instancie mais non valide.
 // cout << "Destructeur Pion" << endl;
}

Piece::Piece(const Piece & autre)
{
  m_x=autre.m_x;
  m_y=autre.m_y;
  m_white=autre.m_white;
//  cout << "Constructeur Piece par copie" << endl;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_x=autre.m_x;
  m_y=autre.m_y;
  m_white=autre.m_white;
//  cout << "Operateur affecation Piece" << endl;
  return *this;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
//  cout << "Constructeur Piece specialise" << endl;
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
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;

}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
 // cout << "mouvementValide Piece" << endl;
  return true;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
//  cout << "mouvementValide Roi" << endl;
  return true;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Reine" << endl;
  return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y);
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
 // cout << "mouvementValide Tour" << endl;
  return true;
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
//  cout << "mouvementValide Fou" << endl;
  return true;
}

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
 // cout << "mouvementValide Cavalier" << endl;
 bool valide = true;

  if(m_y == ((m_white)?2:7))
  {
      if(m_x != x || !(y == m_y+((m_white)?1:-1) || y == m_y+((m_white)?2:-2)))
          valide = false;
  }
  else
  {
      if(m_x != x || y != m_y+((m_white)?1:-1)){
          valide = false;
      }
  }

  return valide;
}

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
//  cout << "mouvementValide Pion" << endl;
  return true;
}

char
Piece::toChar() const
{
  return m_white?'B':'N';
}

char
Roi::toChar() const
{
  return m_white?'R':'r';
}

char
Reine::toChar() const
{
  return m_white?'Q':'q';
}

char
Tour::toChar() const
{
  return m_white?'T':'t';
}

char
Fou::toChar() const
{
  return m_white?'F':'f';
}

char
Cavalier::toChar() const
{
  return m_white?'C':'c';
}

char
Pion::toChar() const
{
  return m_white?'P':'p';
}

void
Piece::setPosition(int x, int y)
{
    m_x=x;
    m_y=y;
}
