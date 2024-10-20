// queue.h
#pragma once
#include "Node.h"
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(Node *newNode)
    {
        if (!front)
        {
            front = rear = newNode;
        }
        else
        {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    Node *dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }

        Node *temp = front;
        front = front->getNext();
        if (!front)
        {
            rear = nullptr;
        }

        return temp;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};
