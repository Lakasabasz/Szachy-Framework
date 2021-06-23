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

list <Field*> Horse::getPossibleMovements(Coords myPos, Board *board, bool protecting, bool excludeImpossible){
    list<Field*> possibleMovements;
    pair<int, int> deltaCoords[] = {
        make_pair(-1, -2),
        make_pair(-2, -1),
        make_pair(1, -2),
        make_pair(2, -1),
        make_pair(-1, 2),
        make_pair(-2, 1),
        make_pair(1, 2),
        make_pair(2, 1)
    };

    for(auto i : deltaCoords){
        if(myPos.first + i.first > -1 && myPos.first + i.first < 8 && myPos.second + i.second > -1 && myPos.second + i.second < 8){
            if(board->getFigureAt(FieldsCoordinates(myPos.first+i.first), myPos.second+i.second) == nullptr
              || board->getFigureAt(FieldsCoordinates(myPos.first+i.first), myPos.second+i.second)->getTeam() != getTeam()
              || protecting) possibleMovements.push_back(board->getField(FieldsCoordinates(myPos.first+i.first), myPos.second+i.second));
        }
    }
    possibleMovements = excludeImpossibleMovements(possibleMovements, board, myPos);

    return possibleMovements;

}
