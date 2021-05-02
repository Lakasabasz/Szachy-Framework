#ifndef KING_H
#define KING_H

#include "figure.h"

class King : public Figure
{
public:
    King(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board) override;
};

#endif // KING_H
