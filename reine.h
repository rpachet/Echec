#ifndef REINE_H
#define REINE_H

#include "piece.h"

class Reine : public Piece
{
public:
    Reine(bool white);
    ~Reine();
    char toChar() const;
    bool mouvementValide(Echiquier &e, int x , int y);
};

#endif // REINE_H
