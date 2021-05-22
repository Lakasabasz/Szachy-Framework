#ifndef TOWER_H
#define TOWER_H

#include "figure.h"

class Queen;

class Tower : public Figure
{
private:
    bool moved = false;
    bool isOnMyLine(Coords my, Coords other);
public:
    Tower(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board, bool protecting = false) override;
    list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withMe = false, bool ignoreOneEnemy = false) override;
    
    bool wasMoved();

    friend Queen;
};

#endif // TOWER_H
