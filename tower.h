#ifndef TOWER_H
#define TOWER_H

#include "figure.h"

class Tower : public Figure
{
public:
    Tower(Team t);
    std::string getSymbol() const;
};

#endif // TOWER_H
