#ifndef ENUMS_H
#define ENUMS_H

#include <utility>

enum FieldsCoordinates{
    A = 0,
    B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7
};

enum Color{
    C_BLACK,
    C_WHITE
};

enum Team{
    T_BLACK,
    T_WHITE
};

typedef std::pair<FieldsCoordinates, int> Coords;
typedef std::pair<Coords, Coords> Movement;

#endif // ENUMS_H
