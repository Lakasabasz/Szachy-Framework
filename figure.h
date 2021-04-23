#ifndef FIGURE_H
#define FIGURE_H

#include <list>
using namespace std;

class Field;

enum Team{
    T_BLACK,
    T_WHITE
};

class Figure
{
private:
    Team t;
    char symbol;
public:
    Figure();
    Figure(Team t);
    ~Figure();

    virtual list<Field*> getPossibleMovements();
    Team* getTeam() const;
    char getSymbol() const;
};

#endif // FIGURE_H
