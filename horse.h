#ifndef HORSE_H
#define HORSE_H

#include "figure.h"

class Horse: public Figure
{
public:
    Horse(Team t);
    std::string getSymbol() const override;
    list<Field*> getPossibleMovements(Coords myPos, Board *board, bool protecting = false) override;
    list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withEK = false) override;
};

#endif // HORSE_H
