#include "king.h"

King::King(Team t) : Figure(t)
{

}

std::string King::getSymbol() const{
    return std::string(1, static_cast<char>(226));
}

list<Field*> King::getPossibleMovements(Coords myPos, Board *board, bool protecting){
    //TODO ruchy zwykłe
    // Wykluczenie szachowanych pól i tych zajętych przez własne figury
    //TODO zbijanie
    // Na podstawie poprzedniej listy
    // Wylkluczenie figur chronionych
    //TODO rozszada
    // Test ruszalności króla i wież
    // Test szachowalności pól przy rozszadzie
}

list<Field*> King::getFieldsToEnemyKing(Coords, Board*, bool, bool){
    return list<Field*>();
}
