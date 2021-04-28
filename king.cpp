#include "king.h"

King::King(Team t) : Figure(t)
{

}

std::string King::getSymbol() const{
    return std::string(1, static_cast<char>(226));
}
