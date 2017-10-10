#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "piece.h"
#include "echiquier.h"

using namespace std;

class Joueur
{
protected:
  vector<Piece*> m_pieces;

public:
    Joueur();
    ~Joueur();
    Joueur(bool white);
    void placerPieces(Echiquier &e);
    void affiche();

};

#endif // JOUEUR_H
