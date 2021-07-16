// iss5

#include <iostream>
#include "..\board.h"
#include "..\figure.h"

using namespace std;

int main(){
    Board b(true);
    b.moveFigureFromTo(Coords(F, 7), Coords(F, 6));
    b.moveFigureFromTo(Coords(E, 8), Coords(F, 7));
    b.moveFigureFromTo(Coords(E, 2), Coords(E, 3));
    b.moveFigureFromTo(Coords(D, 1), Coords(H, 5));
    b.display();
    Figure* f = b.getFigureAt(G, 6);
    auto possMov = f->getPossibleMovements(Coords(G, 6), &b);
    if(possMov.size() == 1) cout << "1";
    else cout << "0";
    return 0;
}
