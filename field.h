#ifndef FIELD_H
#define FIELD_H

class Field;

#include "figure.h"

enum Color{
    C_BLACK,
    C_WHITE
};

class Field
{
private:
    Color c;
    Figure* f;
public:
    Field(Color c);
    Field(Color c, Figure* f);
    ~Field();

    Figure* getFigure() const;
    void setFigure(Figure* f);

    Color getColor() const;
};

#endif // FIELD_H
