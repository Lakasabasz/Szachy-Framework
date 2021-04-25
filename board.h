#ifndef BOARD_H
#define BOARD_H

#include "enums.h"
#include "field.h"
#include <list>
#include <vector>

using namespace std;

const list<FieldsCoordinates> allFC = {FieldsCoordinates::A, FieldsCoordinates::B, FieldsCoordinates::C, FieldsCoordinates::D,
                                      FieldsCoordinates::E, FieldsCoordinates::F, FieldsCoordinates::G, FieldsCoordinates::H};

class Board
{
private:
    Field* fields[8][8];
    vector<Movement> history;

public:
    Board(bool defaultPositions);
    Board(Board& other);
    ~Board();

    Field* getField(FieldsCoordinates fc, int fc2);
    Field* getField(Coords pos);
    Figure* getFigureAt(FieldsCoordinates fc, int fc2);
    Figure* getFigureAt(Coords pos);

    list<Figure*> getAllFiguresByTeam(Team t);
    list<Figure*> whichFigureCanMoveOn(FieldsCoordinates fc, int fc2);

    Movement getLastMovement() const;

    void moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);
    void setFigurePositionFormTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);

    void setFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);
    void removeFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);

    void display();
};

#endif // BOARD_H
