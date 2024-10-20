// Zaim Khan Abbasi_22I-2462_Assignment 3
#pragma once
#include "nodeInfo.h"
class Node
{
public:
    NodeInfo *Info;
    Node *Left;
    Node *Right;

    Node()
    {
        Info = new NodeInfo();
        Left = nullptr;
        Right = nullptr;
    }

    Node(NodeInfo *info)
    {
        Info = info;
        Left = nullptr;
        Right = nullptr;
    }

    ~Node()
    {
        delete Info;
        delete Left;
        delete Right;
    }
};