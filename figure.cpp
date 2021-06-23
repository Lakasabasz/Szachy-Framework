#include "figure.h"

list<Field *> Figure::excludeImpossibleMovements(list<Field *> possibleMovements, Board* board, Coords myPos)
{
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
                Coords testPoint(FieldsCoordinates(i), (a*i)+b);
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
                if(a*i+b < 0) continue;
                Coords testPoint(FieldsCoordinates(i), (a*i)+b);
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
            Coords checkingFigurePosition = board->getFirstAttackerPosition(getTeam()==T_WHITE?T_BLACK:T_WHITE);
            auto lineToOwnKing = board->getFigureAt(checkingFigurePosition)->getFieldsToEnemyKing(checkingFigurePosition, board, true);
            // Porównanie lineToOwnKing z possibleMovements
            possibleMovements = commonPart(lineToOwnKing, possibleMovements);
        } else possibleMovements.clear();
    }
    return possibleMovements;
}

Figure::Figure(){}

Figure::Figure(Team t){
    this->t = t;
}

Figure::~Figure(){}

list<Field *> Figure::commonPart(const list<Field *> a, const list<Field *> b)
{
    list<Field*> ret;
    for(Field* i : a){
        for(Field* j : b){
            if(i == j) ret.push_back(i);
        }
    }
    return ret;
}

void Figure::onMoveEvent(){}

Team Figure::getTeam() const{
    return this->t;
}

string Figure::getSymbol() const{
    return "_";
}

string Figure::show() const{
    if(getTeam() == Team::T_BLACK) return "C" + getSymbol();
    return "B" + getSymbol();
}

