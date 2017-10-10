#ifndef ROI_H
#define ROI_H

#include "piece.h"

class Roi : public Piece
{
public:
    Roi(bool white);
    ~Roi();
    char toChar() const;
    bool mouvementValide(Echiquier &e, int x , int y);
};

#endif // ROI_H
