#ifndef BISHOP_H
#define BISHOP_H

#include "figure.h"

class Bishop : public Figure
{
public:
    Bishop(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board) override;
};

#endif // BISHOP_H
