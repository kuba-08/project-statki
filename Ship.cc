#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship(int size, int row, int col, bool horizontal)
    : size(size), hits(0), row(row), col(col), horizontal(horizontal) {}

bool Ship::isSunk() const {
    return hits >= size;  // Jeśli liczba trafień jest równa lub większa od rozmiaru, statek jest zatopiony
}

void Ship::hit() {
    if (hits < size) {
        hits++;  // Zwiększa liczbę trafień, gdy statek jest trafiony
    }
}

int Ship::getSize() const {
    return size;
}

bool Ship::getOrientation() const {
    return horizontal;
}

int Ship::getRow() const {
    return row;
}

int Ship::getCol() const {
    return col;
}