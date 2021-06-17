#ifndef HISTORY_H
#define HISTORY_H

#include "enums.h"

class History
{
public:
    History();

    Movement lastMovement();
    bool getPawnMovesInMovesBack(unsigned int moves);
    bool getFiguresDeadInMovesBack(unsigned int moves);
    bool add(Movement move);
};

#endif // HISTORY_H
