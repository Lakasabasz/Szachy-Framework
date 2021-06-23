#ifndef HORSE_H
#define HORSE_H

#include "figure.h"

class Horse: public Figure
{
public:
    Horse(Team t);
    std::string getSymbol() const override;
    virtual list<Field*> getPossibleMovements(Coords myPos, Board *board, bool protecting = false, bool excludeImpossible = true) override;
    virtual list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withMe = false, bool ignoreOneEnemy = false) override;
};

#endif // HORSE_H
