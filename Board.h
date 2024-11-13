#pragma once
 
class Board {
private:

    char grid[10][10];  // Plansza gry
    
    
public:
    Board();
    void printBoard(bool reveal) const;
    bool placeShip(int x, int y, int size, bool horizontal);
    bool isAreaClear(int x, int y, int size, bool horizontal) const;
    bool canPlaceShip(int x, int y, int size, bool horizontal) const;
    bool areAllShipsSunk() const;
    bool receiveAttack(int x, int y);  // Odbiera atak i zwraca true, jeśli trafiony
    bool hasbeenShotAt(int row, int col) const; // metoda sprawdzająca czy dane pole było już trafione
    // void markAreaArrounShip(int x, int y, int size, bool horizontal); // funcja do umieszczania pudła wokó zatopionego statku
    


};