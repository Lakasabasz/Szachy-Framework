#include "tower.h"

Tower::Tower(Team t) : Figure(t){}

std::string Tower::getSymbol() const{
    return std::string(1, static_cast<char>(219));
}
