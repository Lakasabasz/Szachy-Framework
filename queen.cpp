#include "queen.h"

Queen::Queen(Team t) : Figure(t)
{

}

std::string Queen::getSymbol() const{
    return std::string(1, static_cast<char>(222));
}
