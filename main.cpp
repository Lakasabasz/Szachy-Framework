#include <iostream>

#include "board.h"
#include "bishop.h"

using namespace std;

int main()
{
    cout << "Setup board:" << endl;
    Board b(true);
    cout << "Setup complete, trying to display: " << endl;
    b.display();
    cout << "\nTrying to make first move: " << endl;
    bool done = b.moveFigureFromTo(Coords(FieldsCoordinates::D, 2), Coords(FieldsCoordinates::D, 4));
    if(done) b.display();
    else{
        cout << "Move are undone";
        return 0;
    }
    cout << "\nTrying to make next few steps: " << endl;
    b.moveFigureFromTo(Coords(FieldsCoordinates::D, 7), Coords(FieldsCoordinates::D, 5));
    b.moveFigureFromTo(Coords(FieldsCoordinates::C, 1), Coords(FieldsCoordinates::F, 4));
    b.moveFigureFromTo(Coords(FieldsCoordinates::C, 8), Coords(FieldsCoordinates::F, 5));
    b.moveFigureFromTo(Coords(FieldsCoordinates::G, 1), Coords(FieldsCoordinates::F, 3));
    b.moveFigureFromTo(Coords(FieldsCoordinates::G, 8), Coords(FieldsCoordinates::F, 6));
    b.moveFigureFromTo(Coords(FieldsCoordinates::G, 2), Coords(FieldsCoordinates::G, 4));
    b.moveFigureFromTo(Coords(FieldsCoordinates::G, 7), Coords(FieldsCoordinates::G, 5));
    b.moveFigureFromTo(Coords(FieldsCoordinates::H, 1), Coords(FieldsCoordinates::G, 1));
    b.moveFigureFromTo(Coords(FieldsCoordinates::F, 5), Coords(FieldsCoordinates::G, 4));
    b.moveFigureFromTo(Coords(FieldsCoordinates::F, 4), Coords(FieldsCoordinates::G, 5));
    b.moveFigureFromTo(Coords(FieldsCoordinates::G, 4), Coords(FieldsCoordinates::F, 3));
    b.moveFigureFromTo(Coords(FieldsCoordinates::G, 5), Coords(FieldsCoordinates::F, 6));
    b.display();
    return 0;
}
