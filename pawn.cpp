#include "pawn.h"
#include "board.h"
#include <math.h>

Pawn::Pawn(Team t)
    : Figure(t)
{

}

std::string Pawn::getSymbol() const{
    return std::string(1, static_cast<char>(6));
}

list<Field*> Pawn::getPossibleMovements(Coords myPos, Board* board, bool protecting){
    list<Field*> possibleMovements;
    // Ruch o 1
    Coords next = myPos;
    if(getTeam() == Team::T_WHITE) next.second++;
    else next.second--;
    if(next.second == 8 || next.second == -1) return possibleMovements;

    if(board->getFigureAt(next) == nullptr) possibleMovements.push_back(board->getField(next));

    // Ruch o 2
    if(myPos.second == 1 && getTeam() == Team::T_WHITE) {
        next = myPos;
        next.second = 3;
        Coords requirement = myPos;
        requirement.second = 2;
        if(board->getFigureAt(next) == nullptr && board->getFigureAt(requirement) == nullptr) possibleMovements.push_back(board->getField(next));
    } else if(myPos.second == 6 && getTeam() == Team::T_BLACK){
        next = myPos;
        next.second = 4;
        Coords requirement = myPos;
        requirement.second = 5;
        if(board->getFigureAt(next) == nullptr && board->getFigureAt(requirement) == nullptr) possibleMovements.push_back(board->getField(next));
    }

    // Bicie skos lewy
    if(myPos.first != FieldsCoordinates::A){
        next = myPos;
        next.first = FieldsCoordinates(next.first-1);
        if(getTeam() == Team::T_WHITE){
            next.second++;
            if(board->getFigureAt(next) != nullptr &&
                    (board->getFigureAt(next)->getTeam() == Team::T_BLACK || protecting)) possibleMovements.push_back(board->getField(next));
        } else{
            next.second--;
            if(board->getFigureAt(next) != nullptr &&
                    (board->getFigureAt(next)->getTeam() == Team::T_WHITE || protecting)) possibleMovements.push_back(board->getField(next));
        }
    }

    // Bicie skos prawy
    if(myPos.first != FieldsCoordinates::H){
        next = myPos;
        next.first = static_cast<FieldsCoordinates>(static_cast<int>(next.first)+1);
        if(getTeam() == Team::T_WHITE){
            next.second++;
            if(board->getFigureAt(next) != nullptr &&
                    (board->getFigureAt(next)->getTeam() == Team::T_BLACK || protecting)) possibleMovements.push_back(board->getField(next));
        } else{
            next.second--;
            if(board->getFigureAt(next) != nullptr &&
                    (board->getFigureAt(next)->getTeam() == Team::T_WHITE || protecting)) possibleMovements.push_back(board->getField(next));
        }
    }

    // Bicie w przelocie lewy
    if(myPos.first != FieldsCoordinates::A){
        next = myPos;
        next.first = static_cast<FieldsCoordinates>(static_cast<int>(next.first)-1);
        if(getTeam() == Team::T_WHITE && myPos.second == 4){
            if(dynamic_cast<Pawn*>(board->getFigureAt(next)) != nullptr){
                Movement m = board->getLastMovement();
                if(m.second == next && m.first.second == 6){
                    next.second = 5;
                    possibleMovements.push_back(board->getField(next));
                }
            }
        } else if(getTeam() == Team::T_BLACK && myPos.second == 3){
            if(dynamic_cast<Pawn*>(board->getFigureAt(next)) != nullptr){
                Movement m = board->getLastMovement();
                if(m.second == next && m.first.second == 1){
                    next.second = 2;
                    possibleMovements.push_back(board->getField(next));
                }
            }
        }
    }

    // Bicie w przelocie prawy
    if(myPos.first != FieldsCoordinates::H){
        next = myPos;
        next.first = static_cast<FieldsCoordinates>(static_cast<int>(next.first)+1);
        if(getTeam() == Team::T_WHITE && myPos.second == 4){
            if(dynamic_cast<Pawn*>(board->getFigureAt(next)) != nullptr){
                Movement m = board->getLastMovement();
                if(m.second == next && m.first.second == 6){
                    next.second = 5;
                    possibleMovements.push_back(board->getField(next));
                }
            }
        } else if(getTeam() == Team::T_BLACK && myPos.second == 3){
            if(dynamic_cast<Pawn*>(board->getFigureAt(next)) != nullptr){
                Movement m = board->getLastMovement();
                if(m.second == next && m.first.second == 1){
                    next.second = 2;
                    possibleMovements.push_back(board->getField(next));
                }
            }
        }
    }

    possibleMovements = excludeImpossibleMovements(possibleMovements, board, myPos);

    return possibleMovements;
}

list<Field *> Pawn::getFieldsToEnemyKing(Coords myPos, Board *board, bool withMe, bool)
{
    list<Field*> ret;
    // Sprawdzić czy na bicie działa
    if(withMe){
        ret.push_back(board->getField(myPos));
    }
    return ret;
}
