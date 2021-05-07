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
list<Field*> Tower::getPossibleMovements(Coords myPos, Board *board, bool protecting){
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
            if(board->getFigureAt(static_cast<FieldsCoordinates>(i), myPos.second) == nullptr){
                ret.push_back(board->getField(static_cast<FieldsCoordinates>(i), myPos.second));
            } else if(board->getFigureAt(static_cast<FieldsCoordinates>(i), myPos.second)->getTeam() != getTeam() || protecting){
                ret.push_back(board->getField(static_cast<FieldsCoordinates>(i), myPos.second));
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
            if(board->getFigureAt(static_cast<FieldsCoordinates>(i), myPos.second) == nullptr){
                ret.push_back(board->getField(static_cast<FieldsCoordinates>(i), myPos.second));
            } else if(board->getFigureAt(static_cast<FieldsCoordinates>(i), myPos.second)->getTeam() != getTeam() || protecting){
                ret.push_back(board->getField(static_cast<FieldsCoordinates>(i), myPos.second));
                break;
            } else{
                break;
            }
        }
    }

    return ret;
}
