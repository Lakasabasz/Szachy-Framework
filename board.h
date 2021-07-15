#ifndef BOARD_H
#define BOARD_H

class Field;
class Figure;

#include "enums.h"
#include "history.h"
#include <list>
#include <vector>

using namespace std;

class Board
{
private:
    Field* fields[8][8];
    History history;
    list<Figure*> deadFigures;

    bool killFigure(Figure* f);

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

    Coords getKingPosition(Team t);
    Coords getFirstAttackerPosition(Team attackerTeam);
    Coords getFigureCoords(Figure* fig);
    Coords getFieldCoords(Field* field);

    Movement getLastMovement();

    bool moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to, MovementErrorCode& erc);
    bool moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);
    void setFigurePositionFormTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);

    void setFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);
    void removeFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);

    void display();

    list<Field*> merge(list<Field*> a, list<Field*> b);

    bool contains(list<Field*> collection, Field* item);
    bool testForEndGame();
    bool isKingChecked(Team t);
    bool isPossibleToCoverKing(Team t);
    bool canEnemyMoveOnField(Team myTeam, Coords testing);
    bool canEnemyMoveOnField(Team myTeam, FieldsCoordinates x, int y);

    static std::string getVersion();
};

#endif // BOARD_H
