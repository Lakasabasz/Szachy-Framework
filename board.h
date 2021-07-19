#ifndef BOARD_H
#define BOARD_H

class Field;
class Figure;

#include "enums.h"
#include "history.h"
#include <list>
#include <vector>

using namespace std;

class Board
{
private:
    Field* fields[8][8];
    History history;
    list<Figure*> deadFigures;

    bool killFigure(Figure* f);

public:
    /**
     * @brief Konstruktor główny
     * @param defaultPositions przyjmuje wartość true lub false. Dla true na szachownicy są ustawiane figury zgodnie z zasadami szachowymi. Dla false plansza jest pusta
     */
    Board(bool defaultPositions);
    Board(Board& other);

    /**
     * @brief Destruktor kasujący wszystkie pola
     */
    ~Board();

    /**
     * @brief Board::getField
     * @see Board::getField(Coords pos)
     * @param fc przyjmuje wartość FieldsCoordinates
     * @param fc2 przyjmuje wartość liczbową w zakresie <0; 7>
     * @return wskaźnik na obiekt Field
     * @throw CoordsOutOfBoardException jeśli fc2 nie należy do przedziału <0; 7>
     */
    Field* getField(FieldsCoordinates fc, int fc2);
    /**
     * @brief Selektor wskaźnika Field* na podstawie koordynatów
     * @param pos przyjmuje instancję Coords w zakresie liczbowym <0; 7>
     * @return wskaźnik na obiekt Field
     * @throw CoordsOutOfBoardException jeśli pos.second nie należy do przedziału <0; 7>
     */
    Field* getField(Coords pos);
    /**
     * @brief Selektor wskaźnika Figure* na podstawie koordynatów
     * @param fc przyjmuje wartość FieldsCoordinates
     * @param fc2 przyjmuje wartość liczbową w zakresie <0; 7>
     * @return wskaźnik na obiekt Figure lub nullptr jeśli pole jest puste
     * @throw CoordsOutOfBoardException jeśli fc2 nie należy do przedziału <0; 7>
     */
    Figure* getFigureAt(FieldsCoordinates fc, int fc2);
    /**
     * @brief Selektor wskaźnika Figure* na podstawie koordynatów
     * @param pos przyjmuje instancję Coords w zakresie liczbowym <0; 7>
     * @return wskaźnik na obiekt Field
     * @throw CoordsOutOfBoardException jeśli pos.second nie należy do przedziału <0; 7>
     */
    Figure* getFigureAt(Coords pos);

    /**
     * @brief Lista wszystkich figur na podstawie koloru
     * @param t Team
     * @return Lista wskaźników na Figure
     */
    list<Figure*> getAllFiguresByTeam(Team t);
    list<Figure*> whichFigureCanMoveOn(FieldsCoordinates fc, int fc2);

    /**
     * @brief Pozycja króla konkretnego koloru
     * @param t Team
     * @return Koordynaty króla w zależności od teamu lub WRONG_COORDS jeśli nie został znaleziony
     */
    Coords getKingPosition(Team t);
    /**
     * @brief Koordynaty pierwszej znalezionej figury szachującej króla
     * @param attackerTeam wskazuje na kolor przeciwny do atakowanego króla. Jeśli szukamy pierwszego atakującego króla białego attackerTeam ustawiamy T_BLACK
     * @return Coords pierwszego atakującego
     */
    Coords getFirstAttackerPosition(Team attackerTeam);
    /**
     * @brief Koordynaty wskazanej figury
     * @param fig wskaźnik na figurę
     * @return WRONG_COORDS jeśli nie znaleziono, Coords jeśli znaleziono
     */
    Coords getFigureCoords(Figure* fig);
    /**
     * @brief Koordynaty wskazanego pola
     * @param field wskaźnik na pole
     * @return WRONG_COORDS jeśli nie znaleziono, Coords jeśli znaleziono
     */
    Coords getFieldCoords(Field* field);

    /**
     * @brief Selektor ostatniego Movement
     * @return WRONG_MOVEMENT jeśli nie ma poprzedniego ruchu, w przeciwnym wypadku Movement
     */
    Movement getLastMovement();

    /**
     * @brief Przenosi figurę z where do to, jeśli figura ma taką możliwość
     * @param where Litera, Liczba 1-8
     * @param to Litera, Liczba 1-8
     * @param erc Referencja na MovementErrorCode. Przechowuje się tam flagę błędu przy przenoszeniu.
     * @return True, jeśli figura została przeniesiona, False jeśli się to nie udało
     */
    bool moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to, MovementErrorCode& erc);
    /**
     * @brief Nakładka na moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to, MovementErrorCode& erc), pomijająca kod błędu
     * @see moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to, MovementErrorCode& erc)
     */
    bool moveFigureFromTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);
    void setFigurePositionFormTo(pair<FieldsCoordinates, int> where, pair<FieldsCoordinates, int> to);

    /**
     * @brief Ustawia figurę na pozycji, bez sprawdzania czy coś się już znajduje na tym polu
     * @param fc FieldsCoordinates
     * @param fc2 Liczba całkowita <0; 7>
     * @param fig Wskaźnik na figurę do przeniesienia
     */
    void setFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);
    void removeFigureAt(FieldsCoordinates fc, int fc2, Figure* fig);

    /**
     * @brief Wyświetla układ planszy na standardowym wyjściu
     */
    void display();

    list<Field*> merge(list<Field*> a, list<Field*> b);

    /**
     * @brief Sprawdza czy collection zawiera item
     * @param collection lista wskaźników na Field
     * @param item wskaźnik na Field
     * @return True jeśli znajdzie, False jeśli nie
     */
    bool contains(list<Field*> collection, Field* item);
    /**
     * @brief sprawdza czy partia została zakończona
     * @return True jeśli tak, False jeśli nie
     */
    bool testForEndGame();
    /**
     * @brief Sprawdza czy król jest szachowany
     * @param t Kolor króla
     * @return True jeśli tak, False jeśli nie
     */
    bool isKingChecked(Team t);
    /**
     * @brief Sprawdza czy można zasłonić swojego króla
     * @param t Kolor własnego króla
     * @return True jeśli tak, False jeśli nie
     */
    bool isPossibleToCoverKing(Team t);
    /**
     * @brief Sprawdza czy przeciwnik może stanąć na określonym polu
     * @param myTeam Kolor własny, nie przeciwnika
     * @param testing Testowane pole
     * @return True jeśli tak, False jeśli nie
     */
    bool canEnemyMoveOnField(Team myTeam, Coords testing);
    /**
     * @see canEnemyMoveOnField(Team myTeam, Coords testing)
     */
    bool canEnemyMoveOnField(Team myTeam, FieldsCoordinates x, int y);

    static std::string getVersion();
};

#endif // BOARD_H
