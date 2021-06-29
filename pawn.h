#ifndef PAWN_H
#define PAWN_H

#include "figure.h"

class Pawn : public Figure
{
public:
    Pawn(Team t);
    std::string getSymbol() const override;
    virtual list<Field*> getPossibleMovements(Coords myPos, Board* board, bool protecting = false, bool excludeImpossible = true) override;
    virtual list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withMe = false, bool ignoreOneEnemy = false) override;
};

#endif // PAWN_H
