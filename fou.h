#ifndef FOU_H
#define FOU_H

#include "piece.h"

class Fou : public Piece
{
public:
    Fou(bool white, bool pos);
    ~Fou();
    char toChar() const;
    bool mouvementValide(Echiquier &e, int x , int y);
};

#endif // FOU_H
