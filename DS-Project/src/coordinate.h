#pragma once
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#include <iostream>
using namespace std;

class Coordinate
{
private:
    int x;
    int y;

public:
    // constructors
    Coordinate()
    {
        x = 0;
        y = 0;
    }
    Coordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // getters and setters
    int getX()
    {
        return x;
    }

    void setX(int x)
    {
        this->x = x;
    }

    int getY()
    {
        return y;
    }

    void setY(int y)
    {
        this->y = y;
    }
    bool operator==(const Coordinate &other) const
    {
        return (x == other.x) && (y == other.y);
    }
};
