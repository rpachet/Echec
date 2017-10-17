#if !defined Joueur_h
#define Joueur_h

#include <vector>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

class Joueur {
 protected:
  //Piece m_pieces[16];
  vector<Piece*> m_pieces;
      bool m_turn = false;

 public:
  Joueur();
  ~Joueur();
  Joueur(bool white);
  void placerPieces(Echiquier &e);
  void setTurn(bool turn);
  bool getTurn();
  void affiche();
  virtual bool isWhite()=0; // methode virtuelle pure, classe abstraite
};

class JoueurBlanc : public Joueur {
 public:
  JoueurBlanc();
  ~JoueurBlanc();
  bool isWhite();
};

class JoueurNoir : public Joueur {
 public:
  JoueurNoir();
  ~JoueurNoir();
  bool isWhite();
};

#endif
