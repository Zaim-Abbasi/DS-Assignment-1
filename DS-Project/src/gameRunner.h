#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include "Graph.h"
#include "human.h"
#include "tree.h"
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
using namespace std;

int PlayAutomatic(Graph &maze, Car &AI, BinaryTree &scoreTree)
{
    // Define the destination coordinates
    int destX = maze.getSize() - 1;
    int destY = maze.getSize() - 1;

    while (true)
    {
        int destX, destY;
        int shortestPath = AI.calculateShortestPath(maze, destX, destY);

        if (shortestPath == 1e7)
        {
            cout << "No valid path to the destination. Game over!" << endl;
            break;
        }
        system("cls");

        printGrid(maze);

        Sleep(2000);

        // Move the car to the next position in the shortest path
        int nextX = AI.getX();
        int nextY = AI.getY();

        // Update the maze with the new position of the car
        maze.getAdjMatrix()[nextX][nextY].getResource()->setCar(false);
        AI.move(Direction::Right, maze, scoreTree);
        
        // moving down
        if (nextY < destY)
        {
            AI.move(Direction::Down, maze, scoreTree);
        }
        // moving up
        else if (nextY > destY)
        {
            AI.move(Direction::Up, maze, scoreTree);
        }
        // moving left
        else if (nextX > destX)
        {
            AI.move(Direction::Left, maze, scoreTree);
        }
        // moving right
        else if (nextX < destX)
        {
            AI.move(Direction::Right, maze, scoreTree);
        }


        // Check if the AI has reached the destination
        if (AI.getX() == destX && AI.getY() == destY)
        {
            cout << "AI has reached the destination. Game over!" << endl;
            break;
        }
    }

    return 0;
}


void printTitle()
{
    system("cls");
    cout << R"(
__        __   _                            _          ____  ____    
\ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___   |___ \|  _ \   
 \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \    __) | | | |  
  \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |  / __/| |_| |  
 __\_/\_/ \___|_|\___\___/|_| |_| |_|\___| _\__\___/  |_____|____/   
|  \/  | __ _ _______   / ___|__ _ _ __   / ___| __ _ _ __ ___   ___ 
| |\/| |/ _` |_  / _ \ | |   / _` | '__| | |  _ / _` | '_ ` _ \ / _ \
| |  | | (_| |/ /  __/ | |__| (_| | |    | |_| | (_| | | | | | |  __/
|_|  |_|\__,_/___\___|  \____\__,_|_|     \____|\__,_|_| |_| |_|\___|
)" << endl;
}

void displayWelcomeMenu()
{
    setConsoleColor(FOREGROUND_RED); // red color
    printTitle();
    setConsoleColor(FOREGROUND_RED); // red color

    cout << "\nWelcome to the 2D Console-Based Race Car Game!" << endl;
    cout << "Choose an option to play:" << endl;
    cout << "1. Play (Manual Mode)" << endl;
    cout << "2. AI (Automatic Mode)" << endl;
    cout << "3. View High Scores" << endl;

    setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // resets color
}

int getDifficultyLevel()
{
    int difficulty;
    setConsoleColor(FOREGROUND_RED); // red color
    cout << "\nChoose difficulty level:" << endl;
    cout << "1. Easy (Grid Size: 5)" << endl;
    cout << "2. Medium (Grid Size: 10)" << endl;
    cout << "3. Hard (Grid Size: 15)" << endl;
    setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    while (true)
    {
        setConsoleColor(FOREGROUND_RED); // red color
        cout << "Enter difficulty level (1-3): ";
        setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin >> difficulty;

        if (cin.fail() || difficulty < 1 || difficulty > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setConsoleColor(FOREGROUND_RED); // red color
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // resets color

            continue;                                                                                    
        }
        else
        {
            break;
        }
    }

    return difficulty;
}

int GameRunner()
{
    displayWelcomeMenu();

    int choice;

    setConsoleColor(FOREGROUND_RED); // red color
    cout << "\nEnter your choice: ";
    setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // resets color

    while (true)
    {
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setConsoleColor(FOREGROUND_RED); // red color
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // resets color
        }
        else
        {
            break;
        }
    }

    int gridSize;
    int difficulty = getDifficultyLevel();

    switch (difficulty)
    {
    case 1:
        gridSize = 5;
        break;
    case 2:
        gridSize = 10;
        break;
    case 3:
        gridSize = 15;
        break;
    default:
        cout << "Invalid difficulty level. Exiting..." << endl;
        return 1;
    }

    Graph maze(gridSize);
    maze.buildMaze();

    // true at beginning
    maze.getAdjMatrix()[0][0].getResource()->setCar(true);
    maze.getAdjMatrix()[gridSize - 1][gridSize - 1].getResource()->setReachedDestination(true);

    Car player;
    Car AI;

    BinaryTree scoreTree;

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "You selected Manual Mode. Get ready to play!" << endl;
        PlayHuman(maze, player, scoreTree);
        break;
    case 2:
        cout << "You selected Automatic Mode. Watch the AI play!" << endl;
        PlayAutomatic(maze, AI, scoreTree);
        break;
    case 3:
        // View high scores
        system("cls");
        scoreTree.displayScores(); // displaying total score
        break;
    default:
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }

    cout << "Thank you for playing the 2D Console-Based Race Car Game!" << endl;

    return 0;
}
