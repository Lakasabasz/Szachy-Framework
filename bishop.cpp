#include "bishop.h"
#include "enums.h"

Bishop::Bishop(Team t) : Figure(t){}

std::string Bishop::getSymbol() const{
    return std::string(1, static_cast<char>(225));
}
