#ifndef FIGURE_H
#define FIGURE_H

#include <list>
#include <iostream>
#include "enums.h"
using namespace std;

class Field;
class Board;

class Figure
{
private:
    Team t;
public:
    Figure();
    Figure(Team t);
    virtual ~Figure();

    virtual list<Field*> getPossibleMovements(Coords myPos, Board* board);
    virtual void onMoveEvent();

    virtual Team getTeam() const;
    virtual string getSymbol() const;
    virtual string show() const;
};

#endif // FIGURE_H
