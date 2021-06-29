#include "history.h"
#include "pawn.h"

History::History()
{
    last = WRONG_MOVEMENT;
}

Movement History::lastMovement()
{
    return last;
}

int History::getPawnMovesInMovesBack(unsigned int moves)
{
    auto counter = 0u;
    if(recorded.size() == 0) return -1;
    for(auto i = 0u; i<recorded.size() && i<moves; i++){
        counter += recorded[recorded.size()-i+1][PAWNS];
    }
    return counter;
}

int History::getFiguresDeadInMovesBack(unsigned int moves)
{
    auto counter = 0u;
    if(recorded.size() == 0) return -1;
    for(auto i = 0u; i<recorded.size()-1 && i<moves; i++){
        counter += recorded[recorded.size()-i+1][KILLS];
    }
    return counter;
}

bool History::add(Movement move, Figure *fig, bool kill)
{
    std::bitset<2> frame;
    frame[PAWNS] = 0;
    frame[KILLS] = 0;
    if(dynamic_cast<Pawn*>(fig) != nullptr) frame[PAWNS] = 1;
    if(kill) frame[KILLS] = 1;
    recorded.push_back(frame);
    last = move;
    return true;
}

int History::movesDone()
{
    return recorded.size();
}
