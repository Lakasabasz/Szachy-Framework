#ifndef HISTORY_H
#define HISTORY_H

#include "enums.h"

#include <bitset>
#include <deque>

class Figure;

class History
{
private:
    Movement last;
    /*
     * Znaczenie bitów:
     * [0] ruch pionka (1 tak, 0 nie)
     * [1] zbicie figury (1 tak, 0 nie)
     */
    std::deque<std::bitset<2>> recorded;
public:
    History();

    Movement lastMovement();
    bool getPawnMovesInMovesBack(unsigned int moves);
    bool getFiguresDeadInMovesBack(unsigned int moves);
    bool add(Movement move, Figure* fig, bool kill);
};

#endif // HISTORY_H
