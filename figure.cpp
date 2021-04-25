#include "figure.h"

Figure::Figure(){}

Figure::Figure(Team t){
    this->t = t;
}

Figure::~Figure(){}

ostream& operator<<(ostream& out, const Figure f){
    if(f.t == Team::T_BLACK) out << "C";
    else out << "B";
    out << f.symbol;
    return out;
}

list<Field*> getPossibleMovements(Coords myPos, Board* board){
    myPos = Coords();
    board = nullptr;
    throw "Using virtual class method";
}
