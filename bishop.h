#ifndef BISHOP_H
#define BISHOP_H

#include "figure.h"

class Queen;

class Bishop : public Figure
{
private:
    bool isOnMyLine(Coords a, Coords b);
public:
    Bishop(Team t);
    std::string getSymbol() const override;
    virtual list<Field*> getPossibleMovements(Coords myPos, Board *board, bool protecting = false, bool excludeImpossible = true) override;
    virtual list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withMe = false, bool ignoreOneEnemy = false) override;

    friend Queen;
};

#endif // BISHOP_H
