#include "horse.h"

Horse::Horse(Team t) : Figure(t){}

std::string Horse::getSymbol() const{
    return std::string(1, static_cast<char>(21));
}
