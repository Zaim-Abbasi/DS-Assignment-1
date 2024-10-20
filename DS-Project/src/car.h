// car.h
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#pragma once
#include "List.h"
#include "resources.h"
#include "output.h"

#include <windows.h>
#include <iostream>
#include "tree.h"

enum class Direction
{
    Right,
    Left,
    Up,
    Down
};
class Car
{
private:
    Coordinate position;
    int score;
    CollectedItemsList collectedItemsList; // Added collected items list

public:
    Car()
    {
        position.setX(0);
        position.setY(0);
        score = 0;
    }

    Car(int x, int y)
    {
        position.setX(x);
        position.setY(y);
        score = 0;
    }

    int getX()
    {
        return position.getX();
    }

    void setX(int CarX)
    {
        position.setX(CarX);
    }

    int getY()
    {
        return position.getY();
    }

    void setY(int CarY)
    {
        position.setY(CarY);
    }

    int getScore()
    {
        return score;
    }

    void setScore(int newScore)
    {
        score = newScore;
    }

    bool WinChecker(Graph &maze)
    {
        return maze.getAdjMatrix()[position.getX()][position.getY()].hasFinish();
    }

    void showWin(Graph &maze, BinaryTree &scoreTree)
    {
        if (WinChecker(maze))
        {
            cout << "You win!" << endl;
            string name;
            cout << "Enter your name: ";
            cin >> name;

            int score = getScore();
            scoreTree.insertScore(score, name);       // Store the score and name in the binary tree
            scoreTree.saveScoresToFile("scores.txt"); // Save scores to a file

            // clear the screen after 2 seconds
            Sleep(2000);
            system("cls");
        }
    }

    void move(Direction dir, Graph &maze, BinaryTree &scoreTree)
    {
        int carX = position.getX();
        int carY = position.getY();

        switch (dir)
        {
        case Direction::Up:
            carY--;
            break;
        case Direction::Down:
            carY++;
            break;
        case Direction::Left:
            carX--;
            break;
        case Direction::Right:
            carX++;
            break;
        }

        if (isValidMove(carX, carY, maze) && isValidDirection(dir, maze))
        {
            moveCar(carX, carY, maze);

            // Check if the user has reached the destination
            showWin(maze, scoreTree); // Pass the scoreTree to showWin
        }
    }

    void DisplayScore()
    {
        cout << "\033[40m\033[31mScore: " << score << "\033[43m\033[37m" << endl;
    }

private:
    bool isValidMove(int x, int y, Graph &maze)
    {
        return maze.chkInputs(x, y) && maze.getAdjMatrix()[x][y].getResource() != nullptr;
    }

    bool isValidDirection(Direction dir, Graph &maze)
    {
        return (maze.ifRightExists(position.getX(), position.getY()) && dir == Direction::Right) ||
               (maze.ifDownExists(position.getX(), position.getY()) && dir == Direction::Down) ||
               (maze.ifLeftExists(position.getX(), position.getY()) && dir == Direction::Left) ||
               (maze.ifUpExists(position.getX(), position.getY()) && dir == Direction::Up);
    }

    void moveCar(int carX, int carY, Graph &maze)
    {
        int prevX = position.getX();
        int prevY = position.getY();

        // Set the car on the new position
        maze.getAdjMatrix()[prevX][prevY].getResource()->setCar(false);
        position.setX(carX);
        position.setY(carY);
        maze.getAdjMatrix()[carX][carY].getResource()->setCar(true);

        // Display the updated score
        DisplayScore();

        // Check if the new position has a node and handle collected items
        handleCollectedItem(maze.getAdjMatrix()[carX][carY].getHead());
        maze.getAdjMatrix()[carX][carY].getHead()->setNodeType(0);
    }

    void handleCollectedItem(Node *newNode)
    {
        if (newNode == nullptr)
            return;

        int nodeType = newNode->getNodeType();

        switch (nodeType)
        {
        case 1: // Coin
            handleItemCollection("Coin collected!", 1);
            break;
        case 2: // Power-up
            handleItemCollection("Power-up collected!", 2);
            break;
        case 3: // Obstacle
            handleItemCollection("Obstacle hit!", -2);
            break;
        }
    }

    void handleItemCollection(const string &message, int scoreChange)
    {
        cout << "\033[40m\033[31m" << message << "\033[43m\033[37m" << endl;
        srand(time(NULL));
        int newScore = rand() % 2 + 1;
        newScore += scoreChange;
        setScore(getScore() + newScore);
    }

public:
    int calculateShortestPath(Graph &maze, int destX, int destY)
    {
        int startX = getX();
        int startY = getY();

        return maze.shortestPathWithTurns(startX, startY, destX, destY);
    }

    void updateScore(int scoreChange)
    {
        setScore(getScore() + scoreChange);
        DisplayScore();
    }
};
