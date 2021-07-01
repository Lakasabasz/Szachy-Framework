#include "king.h"
#include "tower.h"

King::King(Team t) : Figure(t)
{

}

std::string King::getSymbol() const{
    return std::string(1, static_cast<char>(226));
}

list<Field*> King::getPossibleMovements(Coords myPos, Board *board, bool protecting, bool excludeImpossible){
    //Ruchy zwykłe
    list<Field*> ret;
    for(int x = myPos.first-1; x<myPos.first+2; x++){
        if(x < 0 || x > 7) continue;
        for(int y = myPos.second-1; y<myPos.second+2; y++){
            if(x < 0 || x > 7 || y > 7 || y < 0) continue;
            if(x == myPos.first && y == myPos.second) continue;
            Coords test(FieldsCoordinates(x), y);
            if((board->getFigureAt(test) != nullptr && board->getFigureAt(test)->getTeam() == getTeam()) || protecting) continue;
            if(!excludeImpossible || board->canEnemyMoveOnField(getTeam(), test)) continue; // BUG pętla króli
            ret.push_back(board->getField(test));
        }
    }
    //TODO rozszada
    if(this->moved || board->isKingChecked(getTeam())) return ret;
    if(getTeam() == T_WHITE){
        Coords lewa = Coords(FieldsCoordinates::A, 0);
        if(board->getFigureAt(lewa) != nullptr &&
                dynamic_cast<Tower*>(board->getFigureAt(lewa)) != nullptr &&
                !dynamic_cast<Tower*>(board->getFigureAt(lewa))->wasMoved()){
            if(!(board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::D, 0) ||
                    board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::C, 0))){
                if(board->getFigureAt(FieldsCoordinates::B, 0) == board->getFigureAt(FieldsCoordinates::C, 0) &&
                        board->getFigureAt(FieldsCoordinates::D, 0) == nullptr) ret.push_back(board->getField(FieldsCoordinates::C, 0));
            }
        }
        Coords prawa = Coords(FieldsCoordinates::H, 0);
        if(board->getFigureAt(prawa) != nullptr &&
                dynamic_cast<Tower*>(board->getFigureAt(prawa)) != nullptr &&
                !dynamic_cast<Tower*>(board->getFigureAt(prawa))->wasMoved()){
            if(!(board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::F, 0) ||
                    board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::G, 0))){
                if(board->getFigureAt(FieldsCoordinates::F, 0) == board->getFigureAt(FieldsCoordinates::G, 0))
                    ret.push_back(board->getField(FieldsCoordinates::G, 0));
            }
        }
    } else{
        Coords lewa = Coords(FieldsCoordinates::A, 7);
        if(board->getFigureAt(lewa) != nullptr &&
                dynamic_cast<Tower*>(board->getFigureAt(lewa)) != nullptr &&
                !dynamic_cast<Tower*>(board->getFigureAt(lewa))->wasMoved()){
            if(!(board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::D, 7) ||
                    board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::C, 7))){
                if(board->getFigureAt(FieldsCoordinates::B, 7) == board->getFigureAt(FieldsCoordinates::C, 7) &&
                        board->getFigureAt(FieldsCoordinates::D, 7) == nullptr) ret.push_back(board->getField(FieldsCoordinates::C, 7));
            }
        }
        Coords prawa = Coords(FieldsCoordinates::H, 7);
        if(board->getFigureAt(prawa) != nullptr &&
                dynamic_cast<Tower*>(board->getFigureAt(prawa)) != nullptr &&
                !dynamic_cast<Tower*>(board->getFigureAt(prawa))->wasMoved()){
            if(!(board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::F, 7) ||
                    board->canEnemyMoveOnField(getTeam(), FieldsCoordinates::G, 7))){
                if(board->getFigureAt(FieldsCoordinates::F, 7) == board->getFigureAt(FieldsCoordinates::G, 7))
                    ret.push_back(board->getField(FieldsCoordinates::G, 7));
            }
        }
    }
    return ret;
}

list<Field*> King::getFieldsToEnemyKing(Coords, Board*, bool, bool){
    return list<Field*>();
}
