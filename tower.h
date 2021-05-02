#ifndef TOWER_H
#define TOWER_H

#include "figure.h"

class Tower : public Figure
{
public:
    Tower(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board) override;
};

#endif // TOWER_H
