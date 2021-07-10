#include <list>
#include <iostream>

#include "board.h"
#include "figure.h"

using namespace std;

int main(){
    Board b(true);
    b.moveFigureFromTo(Coords(G, 1), Coords(F, 3));
    MovementErrorCode mec;
    b.moveFigureFromTo(Coords(F, 3), Coords(E, 5), mec);
    b.display();
    cout << (mec == MEC_GAMEDONE?"Koniec gry":"Co innego");
}
