#include "field.h"

Field::Field(Color c){
    this->c = c;
    this->f = nullptr;
}

Field::Field(Color c, Figure* f){
    this->c = c;
    this->f = f;
}

Field::~Field(){
    delete this->f;
}

Figure* Field::getFigure() const{
    return this->f;
}

void Field::setFigure(Figure* f){
    this->f = f;
}

Color Field::getColor() const{
    return this->c;
}

