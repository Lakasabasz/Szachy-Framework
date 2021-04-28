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

char Figure::getSymbol() const{
    return this->symbol;
}

ostream& operator<<(ostream& out, const Figure f){
    if(f.t == Team::T_BLACK) out << "C";
    else out << "B";
    out << f.symbol;
    return out;
}

