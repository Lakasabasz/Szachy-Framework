#ifndef FIGURE_H
#define FIGURE_H

#include <list>
#include <iostream>
#include "enums.h"
#include "board.h"
using namespace std;

class Figure
{
private:
    Team t;
public:
    Figure();
    Figure(Team t);
    virtual ~Figure();

    virtual list<Field*> getPossibleMovements(Coords myPos, Board* board, bool protecting = false, bool fullline = false) = 0;
    virtual list<Field*> getFieldsToEnemyKing(Coords myPos, Board* board, bool withEK = false, bool ignoreOne = false) = 0;
    virtual void onMoveEvent();

    virtual Team getTeam() const;
    virtual string getSymbol() const = 0;
    virtual string show() const;
};

#endif // FIGURE_H
