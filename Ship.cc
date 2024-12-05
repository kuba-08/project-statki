#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship(int size, int startX, int startY, bool horizontal)  : size(size), hits(0), isSunkFlag(false), startX(startX), startY(startY), horizontal(horizontal) {}


bool Ship::occupiesPosition(int x, int y) const
{
    if (horizontal)
    {
        return (x>= startX && x < startX + size && y == startY);
    }else{
        return (y>= startY && y < startY + size && x == startX);
    }
    
}

bool Ship::isSunk() const
{
    return isSunkFlag;
}

void Ship::hit()
{
    hits++;
    if (hits >= size)
    {
       isSunkFlag = true; // zatopiony
    }
    
}

int Ship::getSize() const
{
    return size;
}

bool Ship::getOrientation() const
{
    return horizontal;
}

int Ship::getstartX() const
{
    return startX;
}

int Ship::getstartY() const
{
    return startY;
}
