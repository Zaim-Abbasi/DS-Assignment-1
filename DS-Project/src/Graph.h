// graph.h:
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "List.h"
#include <queue>

#include "coordinate.h"
#include "queue.h"
#include <queue>
#include <stack>

class Graph
{
private:
    int size;
    List **adjMatrix;
    Queue obstacleQueue;

public:

    int getSize()
    {
        return size;
    }

    List **getAdjMatrix()
    {
        return adjMatrix;
    }

    void setAdjMatrix(List **matrix)
    {
        adjMatrix = matrix;
    }


    Graph(int size)
    {
        this->size = size;
        adjMatrix = new List *[size];
        for (int i = 0; i < size; ++i)
        {
            adjMatrix[i] = new List[size];
        }
    }

    ~Graph()
    {
        for (int i = 0; i < size; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    bool chkInputs(int x1, int y1, int x2, int y2)
    {
        if (x1 < 0 || x1 >= size || y1 < 0 || y1 >= size || x2 < 0 || x2 >= size || y2 < 0 || y2 >= size)
        {
            return false;
        }
        return true;
    }

    bool chkInputs(int x, int y)
    {
        if (x < 0 || x >= size || y < 0 || y >= size)
        {
            return false;
        }
        return true;
    }


    bool isNextToPowerUp(int x, int y)
    {
        return (checkNeighbor(x, y, x + 1, y) || checkNeighbor(x, y, x - 1, y) ||
                checkNeighbor(x, y, x, y + 1) || checkNeighbor(x, y, x, y - 1));
    }

    void generateObstacles(int numObstacles)
    {
        // Generate 'numObstacles' obstacle nodes and enqueue them
        for (int i = 0; i < numObstacles; ++i)
        {
            int x = rand() % size;
            int y = rand() % size;
            Coordinate *coordinate = new Coordinate(x, y);
            Node *obstacleNode = new Node(x, y, 3); // NodeType 3 for Obstacle
            obstacleQueue.enqueue(obstacleNode);
        }
    }

    void addEdge(int x1, int y1, int x2, int y2)
    {
        if (!chkInputs(x1, y1, x2, y2))
        {
            return;
        }

        Coordinate *coordinate1 = new Coordinate(x1, y1);
        Coordinate *coordinate2 = new Coordinate(x2, y2);

        int totalWeight = 100;
        int random = rand() % totalWeight;

        int weightRegular = 50;
        int weightCoin = 10;
        int weightPowerUp = 30;
        int weightObstacle = 5;

        generateObstacles(5);

        // Connect the cell to the right (i + 1, j)
        if (random < weightCoin && canAddItemAt(x1, y1))
        {
            adjMatrix[x1][y1].addNode(coordinate2, 1); // Coin
            adjMatrix[x2][y2].addNode(coordinate1, 1); // Coin
        }
        else if (random < weightCoin + weightPowerUp && canAddItemAt(x1, y1))
        {
            // Check if two power-ups are not next to each other
            if (!isNextToPowerUp(x1, y1) && !isNextToPowerUp(x2, y2))
            {
                adjMatrix[x1][y1].addNode(coordinate2, 2); // Power-up
                adjMatrix[x2][y2].addNode(coordinate1, 2); // Power-up
            }
        }
        else if (random < weightCoin + weightPowerUp + weightObstacle && canAddItemAt(x1, y1))
        {
            // Dequeue obstacle nodes and add them to the graph
            if (!obstacleQueue.isEmpty())
            {
                Node *obstacleNode1 = obstacleQueue.dequeue();
                Node *obstacleNode2 = obstacleQueue.dequeue();

                adjMatrix[x1][y1].addNode(obstacleNode1);
                adjMatrix[x2][y2].addNode(obstacleNode2);
            }
        }
        else
        {
            // Regular node
            adjMatrix[x1][y1].addNode(coordinate2, 0);
            adjMatrix[x2][y2].addNode(coordinate1, 0);
        }
    }


    bool canAddItemAt(int x, int y)
    {
        // Adjusted the conditions to allow items to be added at the borders
        return (x >= 0 && x < size && y >= 0 && y < size);
    }

    bool checkNeighbor(int x, int y, int targetX, int targetY)
    {
        if (!chkInputs(x, y))
        {
            return false;
        }

        Node *temp = adjMatrix[x][y].getHead();
        while (temp != nullptr)
        {
            if (temp->getCoordinate()->getX() == targetX && temp->getCoordinate()->getY() == targetY)
            {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    bool ifRightExists(int x, int y)
    {
        return checkNeighbor(x, y, x + 1, y);
    }

    bool ifDownExists(int x, int y)
    {
        return checkNeighbor(x, y, x, y + 1);
    }

    bool ifLeftExists(int x, int y)
    {
        return checkNeighbor(x, y, x - 1, y);
    }

    bool ifUpExists(int x, int y)
    {
        return checkNeighbor(x, y, x, y - 1);
    }

    void buildMaze()
    {
        srand(static_cast<unsigned int>(time(nullptr)));

        // Loop through each cell in the maze
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col < size; ++col)
            {
                connectCell(col, row, col + 1, row); // Connect the cell to the right (i + 1, j)
                connectCell(col, row, col - 1, row); // Connect the cell to the left (i - 1, j)
                connectCell(col, row, col, row + 1); // Connect the cell below (i, j + 1)
                connectCell(col, row, col, row - 1); // Connect the cell above (i, j - 1)
            }
        }

        for (int i = 0; i < size; i++)
        {
            addEdge(i, 0, i, 1);
        }
        for (int i = 0; i < size; i++)
        {
            addEdge(i, size - 1, i, size - 2);
        }
        for (int i = 0; i < size; i++)
        {
            addEdge(0, i, 1, i);
        }
        for (int i = 0; i < size; i++)
        {
            addEdge(size - 1, i, size - 2, i);
        }
    }

    void connectCell(int fromCol, int fromRow, int toCol, int toRow)
    {
        int randomDirection = rand() % 4;

        // Probability of connection is higher for randomDirection 0 and 1
        if (randomDirection < 2)
        {
            addEdge(fromCol, fromRow, toCol, toRow);
        }
    }

    int minDistance(int outputArr[], bool sptSet[], int size)
    {
        int min = INT_MAX, min_index;

        for (int v = 0; v < size; v++)
        {
            if (!sptSet[v] && outputArr[v] <= min)
            {
                min = outputArr[v];
                min_index = v;
            }
        }

        return min_index;
    }

    // calculates the shortest path between two points in the maze, considering turns.

    int shortestPathWithTurns(int startX, int startY, int endX, int endY)
    {
        const int MAX_DISTANCE = 1e7;
        int graph[size * size][size * size];

        // Populate the graph with the maze information
        // If a path exists b/w nodes weight 1, else it's MAX_DISTANCE
        for (int i = 0; i < size * size; ++i)
        {
            for (int j = 0; j < size * size; ++j)
            {
                graph[i][j] = (getAdjMatrix()[i / size][i % size].getResource() != nullptr) ? 1 : MAX_DISTANCE;
            }
        }

        int outputArr[size * size]; //  hold the shortest distance from src to i

        bool sptSet[size * size]; // sptSet[i] will be true if vertex i is included in the shortest path tree

        for (int i = 0; i < size * size; i++)
        {
            outputArr[i] = MAX_DISTANCE, sptSet[i] = false;
        }

        // Distance of source vertex from itself is always 0
        outputArr[startX * size + startY] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < size * size - 1; count++)
        {
            // selecting the minimum distance vertex from the set of vertices not yet processed
            int u = minDistance(outputArr, sptSet, size * size);
            sptSet[u] = true;

            // Update outputArr value of the adjacent vertices of the picked vertex
            for (int v = 0; v < size * size; v++)
            {
                // Update outputArr[v] only if it is not in sptSet, there is an edge from u to v,

                // and total weight of path from src to v through u is smaller than current value of outputArr[v]
                if (!sptSet[v] && graph[u][v] && outputArr[u] != MAX_DISTANCE &&
                    outputArr[u] + graph[u][v] < outputArr[v])
                {
                    outputArr[v] = outputArr[u] + graph[u][v];
                }
            }
        }

        // The distance to the destination is stored in outputArr[endX * size + endY]
        return outputArr[endX * size + endY];
    }
};
