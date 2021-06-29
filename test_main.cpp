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
    cout << "\nTrying to make next few steps: " << endl << true << "|";
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::D, 7), Coords(FieldsCoordinates::D, 5));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::C, 1), Coords(FieldsCoordinates::F, 4));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::C, 8), Coords(FieldsCoordinates::F, 5));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::G, 1), Coords(FieldsCoordinates::F, 3));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::G, 8), Coords(FieldsCoordinates::F, 6));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::G, 2), Coords(FieldsCoordinates::G, 4));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::G, 7), Coords(FieldsCoordinates::G, 5));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::H, 1), Coords(FieldsCoordinates::G, 1));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::F, 5), Coords(FieldsCoordinates::G, 4));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::F, 4), Coords(FieldsCoordinates::G, 5));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::G, 4), Coords(FieldsCoordinates::F, 3));
    cout << b.moveFigureFromTo(Coords(FieldsCoordinates::G, 5), Coords(FieldsCoordinates::F, 6));
    cout << endl;
    b.display();
    return 0;
}
