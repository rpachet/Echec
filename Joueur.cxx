#include <iostream>
#include "Joueur.h"

Joueur::Joueur()
{
 // cout << "Constructeur Joueur par defaut" << endl;
}

JoueurBlanc::JoueurBlanc()
{
  Roi* rb = new Roi(true);
  m_pieces.push_back(rb);
  Reine* qb = new Reine(true);
  m_pieces.push_back(qb);
  Fou* fbg = new Fou(true,true);
  m_pieces.push_back(fbg);
  Fou* fbd = new Fou(true,false);
  m_pieces.push_back(fbd);
  Tour* tbg = new Tour(true,true);
  m_pieces.push_back(tbg);
  Tour* tbd = new Tour(true,false);
  m_pieces.push_back(tbd);
  Cavalier* cbg = new Cavalier(true,true);
  m_pieces.push_back(cbg);
  Cavalier* cbd = new Cavalier(true,false);
  m_pieces.push_back(cbd);

  Pion* p;
  for (int i=1; i<=8; i++)
    {
      p = new Pion(true,i);
      m_pieces.push_back(p);
    }
}

JoueurBlanc::~JoueurBlanc()
{
  vector<Piece*>::iterator p=m_pieces.begin();
  while (p!=m_pieces.end())
    {
      delete *p;
      p++;
    }
 // cout << "Constructeur Joueur blanc" << endl;
}

JoueurNoir::JoueurNoir()
{
  Roi* rb = new Roi(false);
  m_pieces.push_back(rb);
  Reine* qb = new Reine(false);
  m_pieces.push_back(qb);
  Fou* fbg = new Fou(false,true);
  m_pieces.push_back(fbg);
  Fou* fbd = new Fou(false,false);
  m_pieces.push_back(fbd);
  Tour* tbg = new Tour(false,true);
  m_pieces.push_back(tbg);
  Tour* tbd = new Tour(false,false);
  m_pieces.push_back(tbd);
  Cavalier* cbg = new Cavalier(false,true);
  m_pieces.push_back(cbg);
  Cavalier* cbd = new Cavalier(false,false);
  m_pieces.push_back(cbd);

  Pion* p;
  for (int i=1; i<=8; i++)
    {
      p = new Pion(false,i);
      m_pieces.push_back(p);
    }
  cout << "Constructeur Joueur noir" << endl;
}

JoueurNoir::~JoueurNoir()
{
  vector<Piece*>::iterator p=m_pieces.begin();
  while (p!=m_pieces.end())
    {
      delete *p;
      p++;
    }
  //cout << "Constructeur Joueur noir" << endl;
}

Joueur::~Joueur()
{
  //cout << "Destructeur Joueur" << endl;
}

void
Joueur::affiche()
{
  for (int i=0; i<m_pieces.size(); i++)
    m_pieces[i]->affiche();
}

void
Joueur::placerPieces(Echiquier &e)
{
  vector<Piece*>::iterator p=m_pieces.begin();
  while (p!=m_pieces.end())
    {
      e.placer(*p);
      p++;
    }
}

void
Joueur::setTurn(bool turn)
{
    m_turn = turn;
}

bool
Joueur::getTurn()
{
    return m_turn;
}


bool
JoueurBlanc::isWhite()
{
  return true;
}

bool
JoueurNoir::isWhite()
{
  return false;
}
