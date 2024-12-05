#pragma once

using namespace std;
class Ship
{
private:
    int size;            // Rozmiar statku (liczba masztów)
    int hits;            // Liczba trafień
    
    bool horizontal;     // Orientacja statku: true = poziomy, false = pionowy
    int startX;
    int startY;
    bool isSunkFlag;
public:
    Ship(int size, int startX, int startY, bool horizontal);
    bool occupiesPosition(int x, int y) const;
    bool isSunk() const;                 // Sprawdza, czy statek jest zatopiony
    void hit();                          // Zwiększa liczbę trafień
    int getSize() const;                 // Zwraca rozmiar statku
    bool getOrientation() const;         // Zwraca orientację statku
    int getstartX() const;                  // Zwraca początkowy wiersz statku
    int getstartY() const;                  // Zwraca początkową kolumnę statku

    

};


