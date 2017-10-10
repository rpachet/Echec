#ifndef TOUR_H
#define TOUR_H

#include "piece.h"

class Tour : public Piece
{
public:
    Tour(bool white, bool pos);
    ~Tour();
    char toChar() const;
    bool mouvementValide(Echiquier &e, int x , int y);
};

#endif // TOUR_H
