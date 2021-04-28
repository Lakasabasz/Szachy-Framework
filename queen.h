#ifndef QUEEN_H
#define QUEEN_H

#include "figure.h"

class Queen : public Figure
{
public:
    Queen(Team t);
    std::string getSymbol() const;
};

#endif // QUEEN_H
