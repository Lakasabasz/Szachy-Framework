#ifndef BOARD_H
#define BOARD_H

#include "field.h"
#include <list>

using namespace std;

enum FieldsCoordinates{
    A = 0,
    B, C, D, E, F, G, H
};

const list<FieldsCoordinates> allFC = {FieldsCoordinates::A, FieldsCoordinates::B, FieldsCoordinates::C, FieldsCoordinates::D,
                                      FieldsCoordinates::E, FieldsCoordinates::F, FieldsCoordinates::G, FieldsCoordinates::H};

class Board
{
private:
    Field* fields[8][8];

public:
    Board(bool defaultPositions);
    Board(Board& other);
    ~Board();

    Field* getField(FieldsCoordinates fc, int fc2);
    Figure* getFigureAt(FieldsCoordinates fc, int fc2);

    list<Figure*> getAllFiguresByTeam(Team t);
    list<Figure*> whichFigureCanMoveOn(FieldsCoordinates fc, int fc2);

    void moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);
    void setFigurePositionFormTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);

    void setFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);
    void removeFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);

    void display();
};

#endif // BOARD_H
