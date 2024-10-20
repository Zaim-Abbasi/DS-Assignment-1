#pragma once
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#include "coordinate.h"
class Node
{
private:
    Coordinate coordinate;
    Node *next;
    int nodeType; // 0 for regular, 1 for coin, 2 for power-up, 3 for obstacle

public:
    Node(int x, int y, int type)
        : coordinate(x, y), next(nullptr), nodeType(type)
    {
    }

    Node(int x, int y)
        : coordinate(x, y), next(nullptr), nodeType(0)
    {

    }

    Coordinate *getCoordinate()
    {
        return &coordinate;
    }

    void setCoordinate(int x, int y)
    {
        coordinate.setX(x);
        coordinate.setY(y);
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *node)
    {
        next = node;
    }

    int getNodeType() const
    {
        return nodeType;
    }

    void setNodeType(int type)
    {
        nodeType = type;
    }
};
