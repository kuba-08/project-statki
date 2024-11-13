#pragma once

using namespace std;
class Ship
{
private:
    int size;            // Rozmiar statku (liczba masztów)
    int hits;            // Liczba trafień
    int row;             // Wiersz początkowy statku
    int col;             // Kolumna początkowa statku
    bool horizontal;     // Orientacja statku: true = poziomy, false = pionowy
public:
    Ship(int size, int row, int col, bool horizontal);
    
    bool isSunk() const;                 // Sprawdza, czy statek jest zatopiony
    void hit();                          // Zwiększa liczbę trafień
    int getSize() const;                 // Zwraca rozmiar statku
    bool getOrientation() const;         // Zwraca orientację statku
    int getRow() const;                  // Zwraca początkowy wiersz statku
    int getCol() const;                  // Zwraca początkową kolumnę statku
    

};


