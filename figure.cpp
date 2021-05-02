#include "figure.h"

Figure::Figure(){}

Figure::Figure(Team t){
    this->t = t;
}

Figure::~Figure(){}

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

