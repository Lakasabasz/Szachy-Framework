#include "tower.h"
#include "bishop.h"
#include "queen.h"

Queen::Queen(Team t) : Figure(t), tNature(t), bNature(t){}

std::string Queen::getSymbol() const{
    return std::string(1, static_cast<char>(222));
}

list<Field*> Queen::getFieldsToEnemyKing(Coords myPos, Board *board, bool withMe, bool ignoreOneEnemy){
    auto ret = tNature.getFieldsToEnemyKing(myPos, board, withMe, ignoreOneEnemy);
    if(ret.size() != 0) return ret;
    ret = bNature.getFieldsToEnemyKing(myPos, board, withMe, ignoreOneEnemy);
    return ret;
}

list<Field*> Queen::getPossibleMovements(Coords myPos, Board *board, bool protecting){
    auto ret = tNature.getPossibleMovements(myPos, board, protecting);
    auto bishop = bNature.getPossibleMovements(myPos, board, protecting);
    ret.merge(bishop);

    ret = excludeImpossibleMovements(ret, board, myPos);
    return ret;
}
