#ifndef FIELD_H
#define FIELD_H

class Field;

#include "enums.h"
#include "figure.h"

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
