// list.h
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#pragma once
#include <list>
#include <queue>
#include "node.h"
#include "resources.h"
#include "coordinate.h"
using namespace std;

class List
{
private:
    Node *head;
    resource *resourceObj;

    queue<Node *> obstacleQueue;

    list<Node *> collectedItems;
    list<Node *> coinList; // List to store coins as Node pointers
    list<Node *> powerUpList; // list to store power-ups as Node pointers

public:
    List()
    {
        head = nullptr;
        resourceObj = new resource();
    }

    void removeNode(int x, int y)
    {
        Node *temp = head;
        Node *prev = nullptr;

        if (temp != nullptr && temp->getCoordinate()->getX() == x && temp->getCoordinate()->getY() == y)
        {
            head = temp->getNext();
            delete temp;
            return;
        }

        while (temp != nullptr && !(temp->getCoordinate()->getX() == x && temp->getCoordinate()->getY() == y))
        {
            prev = temp;
            temp = temp->getNext();
        }

        if (temp == nullptr)
        {
            return;
        }

        prev->setNext(temp->getNext());
        delete temp;
    }

    void removeNode(Node *nodeToRemove)
    {
        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr)
        {
            if (current == nodeToRemove)
            {
                if (previous != nullptr)
                {
                    previous->setNext(current->getNext());
                }
                else
                {
                    head = current->getNext();
                }

                delete current;
                return;
            }

            previous = current;
            current = current->getNext();
        }
    }

    bool DuplicateNode(int x, int y)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->getCoordinate()->getX() == x && temp->getCoordinate()->getY() == y)
            {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    // add nodes using coordinates
    void addNode(Coordinate *coordinate, int nodeType)
    {
        Node *newNode = new Node(coordinate->getX(), coordinate->getY(), nodeType);
        Node *temp = head;

        while (temp != nullptr)
        {
            if (DuplicateNode(coordinate->getX(), coordinate->getY()))
            {
                return;
            }
            temp = temp->getNext();
        }

        // If the node is a coin, power-up, or obstacle, add it to the linked list
        if (nodeType == 1 || nodeType == 2)
        {
            collectedItems.push_back(newNode);

            if (nodeType == 1)
            {
                coinList.push_back(newNode); // Add coin to coinList
            }
            if (nodeType == 2)
            {
                // Add power-up to powerUpList
                powerUpList.push_back(newNode);
            }
        }

        // If the node is an obstacle, enqueue it
        if (nodeType == 3)
        {
            obstacleQueue.push(newNode);
        }

        newNode->setNext(head);
        head = newNode;
    }

    void addNode(Node *node)
    {
        Coordinate *coordinate = node->getCoordinate();
        int nodeType = node->getNodeType();

        Node *newNode = new Node(coordinate->getX(), coordinate->getY(), nodeType);

        Node *temp = head;
        while (temp != nullptr)
        {
            if (DuplicateNode(coordinate->getX(), coordinate->getY()))
            {
                return;
            }
            temp = temp->getNext();
        }

        // If the node is a coin, power-up, or obstacle, add it to the linked list
        if (nodeType == 1 || nodeType == 2 || nodeType == 3)
        {
            collectedItems.push_back(newNode);

            if (nodeType == 1)
            {
                coinList.push_back(newNode); // Add coin to coinList
            }
        }

        newNode->setNext(head);
        head = newNode;
    }

    // process obstacles from the queue
    void processObstacles()
    {
        if (!obstacleQueue.empty())
        {
            Node *obstacleNode = obstacleQueue.front();
            obstacleQueue.pop();

            // implemented logic in Graph::generateObstacles()

            delete obstacleNode;
        }
    }

    Node *getHead()
    {
        return head;
    }

    bool hasCar() const
    {
        return resourceObj->getCar();
    }

    bool hasFinish() const
    {
        return resourceObj->getReachedDestination();
    }

    resource *getResource() const
    {
        return resourceObj;
    }

    resource *setResource()
    {
        return resourceObj;
    }

    // add collected items to the linked list
    void collectItem(Node *itemNode)
    {
        collectedItems.push_back(itemNode);

        // Update the player's score based on the collected item type
        if (itemNode->getNodeType() == 1)
        { // Coin
            resourceObj->setScore(resourceObj->getScore() + 1);
        }
        else if (itemNode->getNodeType() == 2)
        { // Power-up
            resourceObj->setScore(resourceObj->getScore() + 2);
        }
        else if (itemNode->getNodeType() == 3)
        { // Obstacle
            resourceObj->setScore(resourceObj->getScore() - 2);
        }
    }
};

class CollectedItemsList
{
private:
    struct CollectedItem
    {
        string name;
        int nodeType;
        int score;

        CollectedItem(string itemName, int itemNodeType, int itemScore)
            : name(itemName), nodeType(itemNodeType), score(itemScore) {}
    };

    list<CollectedItem> collectedItems;

public:
    // add collected items to the linked list
    void addItem(string name, int nodeType, int score)
    {
        collectedItems.push_back(CollectedItem(name, nodeType, score));
    }

    // calculate and return the total score of collected items
    int getTotalScore()
    {
        int totalScore = 0;
        for (const auto &item : collectedItems)
        {
            totalScore += item.score;
        }
        return totalScore;
    }

    // display the collected items
    void displayCollectedItems()
    {
        cout << "Collected Items:" << endl;
        for (const auto &item : collectedItems)
        {
            cout << "Name: " << item.name << ", NodeType: " << item.nodeType << ", Score: " << item.score << endl;
        }
    }
};