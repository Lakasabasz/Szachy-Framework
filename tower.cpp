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
list<Field*> Tower::getPossibleMovements(Coords myPos, Board *board){
    list<Field*> ret;
    // Do góry
    if(myPos.second != 7){
        for(int i = myPos.second + 1; i<8; i++){
            if(board->getFigureAt(myPos.first, i) == nullptr){
                ret.push_back(board->getField(myPos.first, i));
            } else if(board->getFigureAt(myPos.first, i)->getTeam() != getTeam()){
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
            } else if(board->getFigureAt(myPos.first, i)->getTeam() != getTeam()){
                ret.push_back(board->getField(myPos.first, i));
                break;
            } else{
                break;
            }
        }
    }

    // TODO W lewo
    // TODO W prawo
}
