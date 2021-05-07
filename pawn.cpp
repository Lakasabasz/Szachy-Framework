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
        next.first = static_cast<FieldsCoordinates>(static_cast<int>(next.first)-1);
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

    // TODO Filtr przypiętych i szachowanych figur przenieść do Figure
    Coords pinningFigure = Coords(FieldsCoordinates::A, -1);
    Coords myKingPos = board->getKingPosition(getTeam());
    // Test dla ataku prostego
    if(myPos.first == myKingPos.first){
        // Czyli są na 1 linii w pionie
        if(myPos.second > myKingPos.second){
            for(int i = myPos.second+1; i < 8; i++){
                Figure* tested = board->getFigureAt(myPos.first, i);
                if(tested == nullptr) continue;
                else if(tested->getTeam() == getTeam()) break;
                else{
                    auto ftek = tested->getFieldsToEnemyKing(Coords(myPos.first, i), board, false, true);
                    if(board->contains(ftek, board->getField(myPos))){
                        pinningFigure = Coords(myPos.first, i);
                    }
                    break;
                }
            }
        } else if(myPos.second < myKingPos.second){
            for(int i = myPos.second-1; i > -1; i--){
                Figure* tested = board->getFigureAt(myPos.first, i);
                if(tested == nullptr) continue;
                else if(tested->getTeam() == getTeam()) break;
                else{
                    auto ftek = tested->getFieldsToEnemyKing(Coords(myPos.first, i), board, false, true);
                    if(board->contains(ftek, board->getField(myPos))){
                        pinningFigure = Coords(myPos.first, i);
                    }
                    break;
                }
            }
        }
    } else if(myPos.second == myKingPos.second){
        // Czyli są na 1 linii w poziomie
        if(myPos.first > myKingPos.first){
            for(int i = myPos.first+1; i < 8; i++){
                Figure* tested = board->getFigureAt(FieldsCoordinates(i), myPos.second);
                if(tested == nullptr) continue;
                else if(tested->getTeam() == getTeam()) break;
                else{
                    auto ftek = tested->getFieldsToEnemyKing(Coords(FieldsCoordinates(i), myPos.second), board, false, true);
                    if(board->contains(ftek, board->getField(myPos))){
                        pinningFigure = Coords(FieldsCoordinates(i), myPos.second);
                    }
                    break;
                }
            }
        } else if(myPos.first < myKingPos.first){
            for(int i = myPos.first-1; i > -1; i--){
                Figure* tested = board->getFigureAt(FieldsCoordinates(i), myPos.second);
                if(tested == nullptr) continue;
                else if(tested->getTeam() == getTeam()) break;
                else{
                    auto ftek = tested->getFieldsToEnemyKing(Coords(FieldsCoordinates(i), myPos.second), board, false, true);
                    if(board->contains(ftek, board->getField(myPos))){
                        pinningFigure = Coords(FieldsCoordinates(i), myPos.second);
                    }
                    break;
                }
            }
        }
    } else if(abs(static_cast<int>(myPos.first) - static_cast<int>(myKingPos.first)) == abs(myPos.second - myKingPos.second)){ // Test dla ataku skośnego
        int x = myPos.first - myKingPos.first;
        int y = myPos.second - myKingPos.second;
        int a = 0;
        if(x*y > 0) a = 1;
        else if(x*y < 0) a = -1;
        int b = myPos.second - myPos.first;
        if(x > 0){
            for(int i = myPos.first+1; i<8; i++){
                Coords testPoint(FieldsCoordinates(i), i+b);
                Figure* tested = board->getFigureAt(testPoint);
                if(tested == nullptr) continue;
                else if(tested->getTeam() == getTeam()) break;
                else{
                    auto ftek = tested->getFieldsToEnemyKing(testPoint, board, false, true);
                    if(board->contains(ftek, board->getField(myPos))){
                        pinningFigure = testPoint;
                    }
                    break;
                }
            }
        } else if(x < 0){
            for(int i = myPos.first-1; i>-1; i--){
                Coords testPoint(FieldsCoordinates(i), i+b);
                Figure* tested = board->getFigureAt(testPoint);
                if(tested == nullptr) continue;
                else if(tested->getTeam() == getTeam()) break;
                else{
                    auto ftek = tested->getFieldsToEnemyKing(testPoint, board, false, true);
                    if(board->contains(ftek, board->getField(myPos))){
                        pinningFigure = testPoint;
                    }
                    break;
                }
            }
        }
        // x y   - szukamy y=x+b dla x -> 8
        // x -y  - szukamy y=-x+b dla x -> 8
        // -x -y - szukamy y=x+b dla x -> 1
        // -x y  - szukamy y=-x+b dla x -> 1
    }

    if(pinningFigure.second != -1){
        auto pinningLine = board->getFigureAt(pinningFigure)->getFieldsToEnemyKing(pinningFigure, board, false, true);
        possibleMovements = commonPart(possibleMovements, pinningLine);
    }
    // Po tym etapie wiemy, jakie mamy ruchy będąc przypiętymi lub nie
    if(board->isKingChecked(getTeam())){
        if(board->isPossibleToCoverKing(getTeam())){
            Coords checkingFigurePosition = board->getAttackerPosition(getTeam());
            auto lineToOwnKing = board->getFigureAt(checkingFigurePosition)->getFieldsToEnemyKing(checkingFigurePosition, board, true);
            // Porównanie lineToOwnKing z possibleMovements
            possibleMovements = commonPart(lineToOwnKing, possibleMovements);
        } else possibleMovements.clear();
    }

    return possibleMovements;
}

list<Field*> getFieldsToEnemyKing(Coords, Board*, bool, bool){
    return list<Field*>();
}
