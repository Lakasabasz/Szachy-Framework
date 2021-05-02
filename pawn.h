#ifndef PAWN_H
#define PAWN_H

#include "figure.h"

class Pawn : public Figure
{
public:
    Pawn(Team t);
    virtual std::string getSymbol() const override;
    virtual list<Field*> getPossibleMovements(Coords myPos, Board* board) override;
};

#endif // PAWN_H
