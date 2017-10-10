#ifndef CAVALIER_H
#define CAVALIER_H

#include "piece.h"

class Cavalier : public Piece
{
public:
    Cavalier(bool white, bool pos);
    ~Cavalier();
    char toChar() const;
    bool mouvementValide(Echiquier &e, int x , int y);};

#endif // CAVALIER_H
