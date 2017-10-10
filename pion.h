#ifndef PION_H
#define PION_H

#include "piece.h"

class Pion : public Piece
{
public:
    Pion(bool white, int pos);
    ~Pion();
    char toChar() const;
    bool mouvementValide(Echiquier &e, int x , int y);
};

#endif // PION_H
