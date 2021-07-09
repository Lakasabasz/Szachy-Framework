#include <list>
#include <iostream>

#include "board.h"
#include "figure.h"

using namespace std;

int main(){
    Board b(true);
    b.display();
    auto lista = b.getFigureAt(G, 0)->getPossibleMovements(Coords(G, 0), &b);
    list<Coords> konwersja;
    for(auto f : lista){
        if(b.getFieldCoords(f) == WRONG_COORDS) cout << "DUPA";
    }
}
