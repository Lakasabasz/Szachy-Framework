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
    char symbol;
public:
    Figure();
    Figure(Team t);
    virtual ~Figure();

    virtual list<Field*> getPossibleMovements(Coords myPos, Board* board);
    virtual void onMoveEvent();

    virtual Team getTeam() const;
    virtual char getSymbol() const;

    friend ostream& operator<<(ostream& out, const Figure f);
};

#endif // FIGURE_H
