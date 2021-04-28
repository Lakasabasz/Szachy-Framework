#include "figure.h"

Figure::Figure(){}

Figure::Figure(Team t){
    this->t = t;
}

Figure::~Figure(){}

list<Field*> Figure::getPossibleMovements(Coords myPos, Board* board){
    myPos = Coords();
    board = nullptr;
    throw "Using virtual class method";
}

void Figure::onMoveEvent(){}

Team Figure::getTeam() const{
    return this->t;
}

string Figure::getSymbol() const{
    return "_";
}

string Figure::show() const{
    if(getTeam() == Team::T_BLACK) return "B" + getSymbol();
    return "C" + getSymbol();
}

