#ifndef TOWER_H
#define TOWER_H

#include "figure.h"

class Tower : public Figure
{
private:
    bool wasMoved;
public:
    Tower(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board, bool protecting = false, bool fullline = false) override;
    list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withEK = false) override;
};

#endif // TOWER_H
