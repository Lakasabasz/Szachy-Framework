#include "board.h"
#include "tower.h"
#include "pawn.h"
#include "bishop.h"
#include "horse.h"
#include "queen.h"
#include "king.h"

#include <iostream>
#include <vector>
using namespace std;

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

Field *Board::getField(Coords pos)
{
    return this->fields[pos.first][pos.second];
}

Figure* Board::getFigureAt(Coords pos)
{
    return this->fields[pos.first][pos.second]->getFigure();
}

Movement Board::getLastMovement() const
{
    return this->history.back();
}

void Board::setFigureAt(FieldsCoordinates fc, int fc2, Figure *fig)
{
    fields[fc][fc2]->setFigure(fig);
}

void Board::display()
{
    //vector<string> toDisplay;
    for(int x = 7; x > -1; x--){
        for(int y = 0; y < 8; y++){
            if(fields[y][x]->getFigure() == nullptr){
                cout << "__";
            } else cout << fields[y][x]->getFigure()->show();
        }
        cout << endl;
    }
    // Górna ramka
    //for(int i = 0; i < 20; i++){
        //string t = "╔═╗\n║ ║\n╚═╝";
    //}
}
