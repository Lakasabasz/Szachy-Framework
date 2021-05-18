#include "king.h"

King::King(Team t) : Figure(t)
{

}

std::string King::getSymbol() const{
    return std::string(1, static_cast<char>(226));
}

list<Field*> King::getPossibleMovements(Coords myPos, Board *board, bool protecting){
    //TODO ruchy zwykłe
    //TODO zbijanie
    //TODO ro
}

list<Field*> King::getFieldsToEnemyKing(Coords, Board*, bool, bool){
    return list<Field*>();
}
