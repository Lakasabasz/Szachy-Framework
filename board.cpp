#include "board.h"
#include "tower.h"
#include "pawn.h"
#include "bishop.h"
#include "horse.h"
#include "queen.h"
#include "king.h"
#include "field.h"
#include "figure.h"

#include "exceptions/usagewrongmovementexception.h"
#include "exceptions/coordsoutofboardexception.h"

#include <iostream>
#include <vector>
using namespace std;

bool Board::killFigure(Figure *f)
{
    if(f == nullptr) return false;
    this->deadFigures.push_back(f);
    return true;
}

Board::Board(bool defaultPositions){
    for(int a = 0; a < 8; a++){
        for(int i = 0; i < 8; i++){
            if(a+i % 2 == 0) fields[a][i] = new Field(Color::C_WHITE);
            else fields[a][i] = new Field(Color::C_BLACK);
        }
    }

    if(defaultPositions){
        // Białe
        for(FieldsCoordinates fc : allFC){
            setFigureAt(fc, 1, new Pawn(Team::T_WHITE));
        }
        setFigureAt(FieldsCoordinates::A, 0, new Tower(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::H, 0, new Tower(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::B, 0, new Horse(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::G, 0, new Horse(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::C, 0, new Bishop(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::F, 0, new Bishop(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::D, 0, new Queen(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::E, 0, new King(Team::T_WHITE));

        // Czarne
        for(FieldsCoordinates fc : allFC){
            setFigureAt(fc, 6, new Pawn(Team::T_BLACK));
        }

        setFigureAt(FieldsCoordinates::A, 7, new Tower(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::H, 7, new Tower(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::B, 7, new Horse(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::G, 7, new Horse(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::C, 7, new Bishop(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::F, 7, new Bishop(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::D, 7, new Queen(Team::T_BLACK));
        setFigureAt(FieldsCoordinates::E, 7, new King(Team::T_BLACK));
    }
}

Board::~Board()
{
    for(int i = 0; i<8; i++){
        for(int x = 0; x<8; x++){
            delete fields[i][x];
        }
    }
}

Field *Board::getField(FieldsCoordinates fc, int fc2)
{
    return this->fields[fc][fc2];
}

Field *Board::getField(Coords pos)
{
    return this->fields[pos.first][pos.second];
}

Figure *Board::getFigureAt(FieldsCoordinates fc, int fc2)
{
    return this->fields[fc][fc2]->getFigure();
}

Figure* Board::getFigureAt(Coords pos)
{
    if(pos.second < 0){
        throw CoordsOutOfBoardException();
    }
    return this->fields[pos.first][pos.second]->getFigure();
}

list<Figure *> Board::getAllFiguresByTeam(Team t)
{
    list<Figure*> list;
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            if(getFigureAt(FieldsCoordinates(x), y) != nullptr
                    && getFigureAt(FieldsCoordinates(x), y)->getTeam() == t)
                list.push_back(getFigureAt(FieldsCoordinates(x), y));
        }
    }
    return list;
}

Coords Board::getKingPosition(Team t)
{
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            if(fields[x][y]->getFigure() != nullptr &&
               fields[x][y]->getFigure()->getTeam() == t &&
               dynamic_cast<King*>(fields[x][y]->getFigure()) != nullptr) return Coords(FieldsCoordinates(x), y);
        }
    }
    return Coords(FieldsCoordinates::A, -1);
}

Coords Board::getFirstAttackerPosition(Team attackerTeam)
{
    list<Figure*> figuresList;
    if(attackerTeam == T_WHITE){
        figuresList = getAllFiguresByTeam(T_BLACK);
    } else{
        figuresList = getAllFiguresByTeam(T_WHITE);
    }
    Figure* first = nullptr;
    for(auto fig : figuresList){
        auto fielToEnem = fig->getFieldsToEnemyKing(getFigureCoords(fig), this, true);
        if(fielToEnem.size() != 0) {
            first = fig;
            break;
        }
    }
    return getFigureCoords(first);
}

Coords Board::getFigureCoords(Figure *fig)
{
    int x, y;
    for(x = 0; x < 7; x++){
        for(y = 0; y < 7; y++){
            if(getFigureAt(FieldsCoordinates(x), y) == fig) break;
        }
    }
    return Coords(FieldsCoordinates(x), y);
}

Movement Board::getLastMovement()
{
    return this->history.lastMovement();
}

bool Board::contains(list<Field*> collection, Field* item){
    for(auto i = collection.begin(); i != collection.end(); i++){
        if(*i == item) return true;
    }
    return false;
}

bool Board::testForEndGame()
{
    auto lastMovement = getLastMovement();
    if(lastMovement == WRONG_MOVEMENT && history.movesDone() == 0) return false;
    else if(lastMovement == WRONG_MOVEMENT) throw UsageWrongMovementException();
    Team move = getFigureAt(getLastMovement().second)->getTeam()==T_WHITE?T_BLACK:T_WHITE;
    // Test mata i pata
    bool end = true;
    auto figures = getAllFiguresByTeam(move);
    for(auto fig : figures){
        if(fig->getPossibleMovements(getFigureCoords(fig), this).size() != 0){
            end = false;
            break;
        }
    }
    if(end) return true;

    // Test ilości figur (min. 1 pionek/2 gońce/2 konie/koń+goniec/1 wieża/1 królówka
    int goniec = 0, horse = 0;
    end = true;
    for(auto fig : figures){
        if(dynamic_cast<Bishop*>(fig) != nullptr) goniec += 1;
        else if(dynamic_cast<Horse*>(fig) != nullptr) horse += 1;
        else if(dynamic_cast<King*>(fig) != nullptr) continue;
        else{
            end = false;
            break;
        }
    }
    if(goniec > 1 || horse > 1 || (goniec == 1 && horse == 1)) end = false;
    if(end){
        goniec = 0;
        horse = 0;
        auto secFigures = getAllFiguresByTeam(getFigureAt(getLastMovement().second)->getTeam());
        for(auto fig : secFigures){
            if(dynamic_cast<Bishop*>(fig) != nullptr) goniec += 1;
            else if(dynamic_cast<Horse*>(fig) != nullptr) horse += 1;
            else if(dynamic_cast<King*>(fig) != nullptr) continue;
            else{
                end = false;
                break;
            }
        }
    }
    if(end && (goniec > 1 || horse > 1 || (goniec == 1 && horse == 1))) return true;

    // Test 50 ruchów bez ruchu pionkiem ani zbicia jakiejś figury
    if(history.getPawnMovesInMovesBack(50) == 0 && history.getFiguresDeadInMovesBack(50) == 0) return true;
    return false;
}

bool Board::isKingChecked(Team t)
{
    list<Figure*> figuresList;
    if(t == T_WHITE){
        figuresList = getAllFiguresByTeam(T_BLACK);
    } else{
        figuresList = getAllFiguresByTeam(T_WHITE);
    }
    for(auto fig : figuresList){
        auto fielToEnem = fig->getFieldsToEnemyKing(getFigureCoords(fig), this, true);
        if(fielToEnem.size() != 0) return true;
    }
    return false;
}

bool Board::isPossibleToCoverKing(Team t)
{
    list<Figure*> figuresList;
    if(t == T_WHITE){
        figuresList = getAllFiguresByTeam(T_BLACK);
    } else{
        figuresList = getAllFiguresByTeam(T_WHITE);
    }
    bool rangeFigureCheck = false;
    for(auto fig : figuresList){
        auto fielToEnem = fig->getFieldsToEnemyKing(getFigureCoords(fig), this, true);
        if(fielToEnem.size() == 1) return false;
        else if(fielToEnem.size() > 1){
            if(rangeFigureCheck) return false;
            else rangeFigureCheck = true;
        }
    }
    return rangeFigureCheck;
}

bool Board::canEnemyMoveOnField(Team myTeam, Coords testing)
{
    list<Figure*> figuresList;
    if(myTeam == T_WHITE){
        figuresList = getAllFiguresByTeam(T_BLACK);
    } else{
        figuresList = getAllFiguresByTeam(T_WHITE);
    }
    for(auto fig : figuresList){
        auto possMov = fig->getPossibleMovements(getFigureCoords(fig), this);
        if(contains(possMov, getField(testing))) return true;
    }
    return false;
}

bool Board::canEnemyMoveOnField(Team myTeam, FieldsCoordinates x, int y)
{
    return canEnemyMoveOnField(myTeam, Coords(x, y));
}

bool Board::moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to)
{
#warning "Sprawdzic zachowanie dla zbicia i rozszady"
    if(testForEndGame()) return false;

    where.second = where.second-1;
    to.second = to.second - 1;
    Figure* f = getFigureAt(where);
    if(f == nullptr){
        return false;
    }

    list<Field*> possibleMovements = f->getPossibleMovements(where, this);
    Field* target = getField(to);
    if(contains(possibleMovements, target)){
        bool dead = killFigure(getFigureAt(where.first, where.second));
        setFigureAt(where.first, where.second, nullptr);
        setFigureAt(to.first, to.second, f);
        f->onMoveEvent();
        history.add(Movement(where, to), f, dead);
        return true;
    }
    return false;
}

void Board::setFigureAt(FieldsCoordinates fc, int fc2, Figure *fig)
{
    fields[fc][fc2]->setFigure(fig);
}

void Board::display()
{
    //vector<string> toDisplay;
    cout << "  ";
    for(int y = 0; y < 8; y++){
        cout << FCNames[y];
    }
    cout << "\n";
    for(int x = 7; x > -1; x--){
        cout << x+1 << " ";
        for(int y = 0; y < 8; y++){
            if(fields[y][x]->getFigure() == nullptr){
                cout << "[]";
            } else cout << fields[y][x]->getFigure()->show();
        }
        cout << endl;
    }
    // Górna ramka
    //for(int i = 0; i < 20; i++){
        //string t = "╔═╗\n║ ║\n╚═╝";
    //}
}
