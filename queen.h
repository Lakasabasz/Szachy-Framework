#ifndef QUEEN_H
#define QUEEN_H

#include "figure.h"

class Queen : public Figure
{
private:
    Tower tNature;
    Bishop bNature;
public:
    Queen(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board, bool protecting = false) override;
    list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withMe = false, bool ignoreOneEnemy = false) override;
};

#endif // QUEEN_H
