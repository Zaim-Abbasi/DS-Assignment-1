// human.h

#pragma once
#include "car.h"
#include <conio.h>
#include "tree.h"
using namespace std;
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

void setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void PlayHuman(Graph &maze, Car &player, BinaryTree &scoreTree)
{
    while (1)
    {
        // Display score
        cout << "\n\033[40m\033[31mScore: " << player.getScore() << "\033[43m\033[37m" << endl;

        // Display controls
        cout << "\nControls:" << endl;
        cout << "W: Move Forward\nA: Turn Left\nD: Turn Right\nS: Move Down" << endl;

        cout << "\nItems:" << endl;
        setConsoleColor(FOREGROUND_BLUE);

        cout << "o: Coins   " << endl;
        setConsoleColor(FOREGROUND_GREEN);

        cout << "*: Power-ups   " << endl;
        setConsoleColor(FOREGROUND_RED);

        cout << "x: Obstacles\n"
             << endl;

        // Reset colors
        setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        // actual maze
        printGrid(maze);

        int c = 0;

        switch ((c = _getch()))
        {
        case KEY_W:
            player.move(Direction::Up, maze, scoreTree);
            break;
        case KEY_S:
            player.move(Direction::Down, maze, scoreTree);
            break;
        case KEY_A:
            player.move(Direction::Left, maze, scoreTree);
            break;
        case KEY_D:
            player.move(Direction::Right, maze, scoreTree);
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }
        system("cls");
    }
}
