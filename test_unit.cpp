#include <list>
#include <iostream>

#include "board.h"
#include "figure.h"

using namespace std;

int main(){
    Board b(true);
    b.moveFigureFromTo(Coords(G, 1), Coords(F, 3));
    b.moveFigureFromTo(Coords(F, 3), Coords(G, 5));
    b.moveFigureFromTo(Coords(G, 5), Coords(E, 6));
    b.moveFigureFromTo(Coords(E, 6), Coords(G, 7));
    MovementErrorCode mec;
    b.moveFigureFromTo(Coords(F, 8), Coords(G, 7), mec);
    b.display();
    switch(mec){
    case MEC_GAMEDONE:
        cout << "Koniec gry";
        break;
    case MEC_IMPOSSIBLE:
        cout << "Ruch poza zakresem";
        break;
    case MEC_EMPTYWHERE:
        cout << "Puste pole";
        break;
    default:
        cout << "Co innego";
    }

    cout << endl;
}
