#include "tower.h"
#include "board.h"

Tower::Tower(Team t) : Figure(t){}

std::string Tower::getSymbol() const{
    return std::string(1, static_cast<char>(219));
}

/*!
 * \brief Tower::getPossibleMovements
 * \param myPos number counted form 0 to 7
 * \param board
 * \return
 */
list<Field*> Tower::getPossibleMovements(Coords myPos, Board *board, bool protecting, bool excludeImpossible){
    list<Field*> ret;
    // Do góry
    if(myPos.second != 7){
        for(int i = myPos.second + 1; i<8; i++){
            if(board->getFigureAt(myPos.first, i) == nullptr){
                ret.push_back(board->getField(myPos.first, i));
            } else if(board->getFigureAt(myPos.first, i)->getTeam() != getTeam() || protecting){
                ret.push_back(board->getField(myPos.first, i));
                break;
            } else{
                break;
            }
        }
    }

    // Na dół
    if(myPos.second != 0){
        for(int i = myPos.second - 1; i>-1; i--){
            if(board->getFigureAt(myPos.first, i) == nullptr){
                ret.push_back(board->getField(myPos.first, i));
            } else if(board->getFigureAt(myPos.first, i)->getTeam() != getTeam() || protecting){
                ret.push_back(board->getField(myPos.first, i));
                break;
            } else{
                break;
            }
        }
    }

    // W lewo
    if(myPos.first != FieldsCoordinates::A){
        auto mpF = static_cast<int>(myPos.first);
        for(auto i = mpF-1; i > -1; i--){
            if(board->getFigureAt(FieldsCoordinates(i), myPos.second) == nullptr){
                ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
            } else if(board->getFigureAt(FieldsCoordinates(i), myPos.second)->getTeam() != getTeam() || protecting){
                ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
                break;
            } else{
                break;
            }
        }
    }

    // W prawo
    if(myPos.first != FieldsCoordinates::H){
        auto mpF = static_cast<int>(myPos.first);
        for(auto i = mpF+1; i < 8; i++){
            if(board->getFigureAt(FieldsCoordinates(i), myPos.second) == nullptr){
                ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
            } else if(board->getFigureAt(FieldsCoordinates(i), myPos.second)->getTeam() != getTeam() || protecting){
                ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
                break;
            } else{
                break;
            }
        }
    }

    ret = excludeImpossibleMovements(ret, board, myPos);

    return ret;
}

list<Field *> Tower::getFieldsToEnemyKing(Coords myPos, Board *board, bool withMe, bool ignoreOneEnemy)
{
    list<Field*> ret;
    Coords enemyKingPosition = board->getKingPosition(getTeam()==Team::T_BLACK?(Team::T_WHITE):(Team::T_BLACK));
    if(!isOnMyLine(myPos, enemyKingPosition)){
        return ret;
    }
    if(withMe) ret.push_back(board->getField(myPos));
    if(myPos.first == enemyKingPosition.first){
        if(myPos.second > enemyKingPosition.second){
            for(int i = myPos.second - 1; i > enemyKingPosition.second; i--){
                if(board->getFigureAt(myPos.first, i) == nullptr) ret.push_back(board->getField(myPos.first, i));
                else if(board->getFigureAt(myPos.first, i)->getTeam() != getTeam() && ignoreOneEnemy){
                    ignoreOneEnemy = false;
                    ret.push_back(board->getField(myPos.first, i));
                } else{
                    ret.clear();
                    return ret;
                }
            }
        } else{
            for(int i = myPos.second + 1; i < enemyKingPosition.second; i++){
                if(board->getFigureAt(myPos.first, i) == nullptr) ret.push_back(board->getField(myPos.first, i));
                else if(board->getFigureAt(myPos.first, i)->getTeam() != getTeam() && ignoreOneEnemy){
                    ignoreOneEnemy = false;
                    ret.push_back(board->getField(myPos.first, i));
                } else{
                    ret.clear();
                    return ret;
                }
            }
        }
    } else{
        if(myPos.first > enemyKingPosition.first){
            for(int i = myPos.first - 1; i > enemyKingPosition.first; i--){
                if(board->getFigureAt(FieldsCoordinates(i), myPos.second) == nullptr) ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
                else if(board->getFigureAt(FieldsCoordinates(i), myPos.second)->getTeam() != getTeam() && ignoreOneEnemy){
                    ignoreOneEnemy = false;
                    ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
                } else{
                    ret.clear();
                    return ret;
                }
            }
        } else{
            for(int i = myPos.first + 1; i < enemyKingPosition.first; i++){
                if(board->getFigureAt(FieldsCoordinates(i), myPos.second) == nullptr) ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
                else if(board->getFigureAt(FieldsCoordinates(i), myPos.second)->getTeam() != getTeam() && ignoreOneEnemy){
                    ignoreOneEnemy = false;
                    ret.push_back(board->getField(FieldsCoordinates(i), myPos.second));
                } else{
                    ret.clear();
                    return ret;
                }
            }
        }
    }
    return ret;
}

bool Tower::wasMoved()
{
    return this->moved;
}

bool Tower::isOnMyLine(Coords my, Coords other){
    return my.first == other.first || my.second == other.second;
}
