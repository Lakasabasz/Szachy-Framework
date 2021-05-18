#include "horse.h"

Horse::Horse(Team t) : Figure(t){}

std::string Horse::getSymbol() const{
    return std::string(1, static_cast<char>(21));
}

list <Field*> Horse::getFieldsToEnemyKing(Coords myPos, Board *board, bool withMe, bool){
    list<Field*> ret;
    if(!withMe) return ret;

    auto movementsToTest = getPossibleMovements(myPos, board);
    if(board->contains(movementsToTest, board->getField(board->getKingPosition(getTeam()==Team::T_BLACK?Team::T_WHITE:Team::T_BLACK)))){
        ret.push_back(board->getField(myPos));
    }
    return ret;
}
