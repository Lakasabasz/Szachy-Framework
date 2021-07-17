// iss6

#include <iostream>
#include "..\board.h"
#include "..\figure.h"

using namespace std;

int main(){
    Board b(true);
    b.moveFigureFromTo(Coords(E, 2), Coords(E, 3));
    b.moveFigureFromTo(Coords(F, 1), Coords(E, 2));
    b.moveFigureFromTo(Coords(G, 1), Coords(F, 3));
    b.moveFigureFromTo(Coords(E, 1), Coords(G, 1));
    b.display();
    Figure* f = b.getFigureAt(F, 0);
    if(f != nullptr) cout << "1";
    else cout << "0";
    return 0;
}

/*
E 2
E 3
F 1
E 2
G 1
F 3
E 1
G 1*/
