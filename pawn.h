#ifndef PAWN_H
#define PAWN_H

#include "figure.h"

class Pawn : public Figure
{
public:
    Pawn(Team t);
    virtual list<Field*> getPossibleMovements(Coords myPos, Board* board);
};

#endif // PAWN_H
