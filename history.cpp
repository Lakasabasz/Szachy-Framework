#include "history.h"
#include "pawn.h"

History::History()
{

}

Movement History::lastMovement()
{
    return last;
}

bool History::getPawnMovesInMovesBack(unsigned int moves)
{
    auto counter = 0u;
    for(auto i = 0u; i<moves; i++){
        counter += recorded[recorded.size()-i+1][0];
    }
    return counter;
}

bool History::getFiguresDeadInMovesBack(unsigned int moves)
{
    auto counter = 0u;
    for(auto i = 0u; i<moves; i++){
        counter += recorded[recorded.size()-i+1][1];
    }
    return counter;
}

bool History::add(Movement move, Figure *fig, bool kill)
{
    std::bitset<2> frame;
    frame[0] = 0;
    frame[1] = 0;
    if(dynamic_cast<Pawn*>(fig) == nullptr) frame[0] = 1;
    if(kill) frame[1] = 1;
    recorded.push_back(frame);
    last = move;
    return true;
}
