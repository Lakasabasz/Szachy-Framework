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
    const uint8_t PAWNS = 0;
    const uint8_t KILLS = 1;
    std::deque<std::bitset<2>> recorded;
public:
    History();

    Movement lastMovement();
    int getPawnMovesInMovesBack(unsigned int moves);
    int getFiguresDeadInMovesBack(unsigned int moves);
    bool add(Movement move, Figure* fig, bool kill);

    int movesDone();
};

#endif // HISTORY_H
