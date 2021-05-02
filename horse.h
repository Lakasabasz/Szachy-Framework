#ifndef HORSE_H
#define HORSE_H

#include "figure.h"

class Horse: public Figure
{
public:
    Horse(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board) override;
};

#endif // HORSE_H
