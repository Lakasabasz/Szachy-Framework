#include "bishop.h"
#include "enums.h"
#include <math.h>
#include "field.h"

Bishop::Bishop(Team t) : Figure(t){}

std::string Bishop::getSymbol() const{
    return std::string(1, static_cast<char>(225));
}

bool Bishop::isOnMyLine(Coords a, Coords b){
    return (b.second-a.second != 0) && abs((b.first-a.first)/(b.second-a.second)) == 1;
}

std::list<Field*> Bishop::getFieldsToEnemyKing(Coords myPos, Board *board, bool withMe, bool ignoreOneEnemy){
    list<Field*> ret;
    Coords enemyKingPosition = board->getKingPosition(getTeam()==Team::T_BLACK?(Team::T_WHITE):(Team::T_BLACK));
    if(!isOnMyLine(myPos, enemyKingPosition)){
        return ret;
    }
    if(withMe) ret.push_back(board->getField(myPos));

    // y=ax+b
    int a = (myPos.second-enemyKingPosition.second)/(myPos.first-enemyKingPosition.first);
    int b = myPos.second-a*enemyKingPosition.first;
    bool directionNormal = myPos.first < enemyKingPosition.first;

    //NOTE zmienić warunek pętli na prywatną metodę loopCondition(bool) i wywalić podwójny kod
    if(directionNormal){
        for(int i = myPos.first + 1; i < enemyKingPosition.first; i++){
            FieldsCoordinates x = FieldsCoordinates(i);
            int y = a*i+b;
            if(board->getFigureAt(x, y) == nullptr){
                ret.push_back(board->getField(x, y));
            } else if(board->getFigureAt(x, y)->getTeam() != getTeam() && ignoreOneEnemy){
                ignoreOneEnemy = false;
                ret.push_back(board->getField(x, y));
            } else{
                ret.clear();
                return ret;
            }
        }
    } else{
        for(int i = myPos.first - 1; i > enemyKingPosition.first; i--){
            FieldsCoordinates x = FieldsCoordinates(i);
            int y = a*i+b;
            if(board->getFigureAt(x, y) == nullptr){
                ret.push_back(board->getField(x, y));
            } else if(board->getFigureAt(x, y)->getTeam() != getTeam() && ignoreOneEnemy){
                ignoreOneEnemy = false;
                ret.push_back(board->getField(x, y));
            } else{
                ret.clear();
                return ret;
            }
        }
    }
    return ret;
}

std::list<Field*> Bishop::getPossibleMovements(Coords myPos, Board *board, bool protecting, bool excludeImpossible){
    // y=ax+b
    list<Field*> ret;
    // kierunek przeciwny i w dół
    for(int x = myPos.first-1, y = myPos.second-1; x > -1 && y > -1; x--, y--){
        if(board->getFigureAt(FieldsCoordinates(x), y) == nullptr) ret.push_back(board->getField(FieldsCoordinates(x), y));
        else if(board->getFigureAt(FieldsCoordinates(x), y)->getTeam() != getTeam() || protecting){
            ret.push_back(board->getField(FieldsCoordinates(x), y));
            break;
        } else break;
    }
    // kierunek przeciwny i w górę
    for(int x = myPos.first-1, y = myPos.second+1; x > -1 && y < 8; x--, y++){
        if(board->getFigureAt(FieldsCoordinates(x), y) == nullptr) ret.push_back(board->getField(FieldsCoordinates(x), y));
        else if(board->getFigureAt(FieldsCoordinates(x), y)->getTeam() != getTeam() || protecting){
            ret.push_back(board->getField(FieldsCoordinates(x), y));
            break;
        } else break;
    }
    // kierunek prawidłowy i w dół
    for(int x = myPos.first+1, y = myPos.second-1; x < 8 && y > -1; x++, y--){
        if(board->getFigureAt(FieldsCoordinates(x), y) == nullptr) ret.push_back(board->getField(FieldsCoordinates(x), y));
        else if(board->getFigureAt(FieldsCoordinates(x), y)->getTeam() != getTeam() || protecting){
            ret.push_back(board->getField(FieldsCoordinates(x), y));
            break;
        } else break;
    }
    // kierunek prawidłowy i w górę
    for(int x = myPos.first+1, y = myPos.second+1; x < 8 && y < 8; x++, y++){
        if(board->getFigureAt(FieldsCoordinates(x), y) == nullptr) ret.push_back(board->getField(FieldsCoordinates(x), y));
        else if(board->getFigureAt(FieldsCoordinates(x), y)->getTeam() != getTeam() || protecting){
            ret.push_back(board->getField(FieldsCoordinates(x), y));
            break;
        } else break;
    }

    ret = excludeImpossibleMovements(ret, board, myPos); //FIXME
    return ret;
}
