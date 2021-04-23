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
            setFigureAt(fc, 6, new Pawn(Team::T_WHITE));
        }

        setFigureAt(FieldsCoordinates::A, 7, new Tower(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::H, 7, new Tower(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::B, 7, new Horse(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::G, 7, new Horse(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::C, 7, new Bishop(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::F, 7, new Bishop(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::D, 7, new Queen(Team::T_WHITE));
        setFigureAt(FieldsCoordinates::E, 7, new King(Team::T_WHITE));
    }
}

void Board::display()
{
    vector<string> toDisplay;
    // Górna ramka
    for(int i = 0; i < 20; i++){
        string t = "╔═╗\n║ ║\n╚═╝";
    }
}
