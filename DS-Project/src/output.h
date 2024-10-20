// output.h
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
#define RESET_COLOR "\033[0m"
#define BLACK_BACKGROUND "\033[40m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_BACKGROUND "\033[43m"
#define WHITE_TEXT "\033[37m"
#define BLUE_TEXT "\033[34m"
#define DARK_GREEN_TEXT "\033[32m"
#define RED_TEXT "\033[91m"

#include "Graph.h"

void printNodeContent(Graph &maze, int i, int j)
{
    auto &node = maze.getAdjMatrix()[i][j];

    if (node.getResource()->getCar())
    {
        // dipslay using color defined as global variables
        cout << BLACK_BACKGROUND << GREEN_TEXT << "C" << YELLOW_BACKGROUND << WHITE_TEXT;
    }
    else if (node.hasFinish())
    {
        // dipslay using color defined as global variables
        cout << BLACK_BACKGROUND << BLUE_TEXT << "o" << YELLOW_BACKGROUND << WHITE_TEXT;
    }
    else
    {
        Node *currentItem = node.getHead();
        bool foundItem = false;

        while (currentItem != nullptr && !foundItem)
        {
            int itemType = currentItem->getNodeType();

            switch (itemType)
            {
            case 1:                                         
                cout << BLACK_BACKGROUND << BLUE_TEXT << "o" << YELLOW_BACKGROUND << WHITE_TEXT;    // for coins
                foundItem = true;
                break;
            case 2:                                      
                cout << BLACK_BACKGROUND << DARK_GREEN_TEXT << "*" << YELLOW_BACKGROUND << WHITE_TEXT;  // powerUps
                foundItem = true;
                break;
            case 3:
                cout << BLACK_BACKGROUND << RED_TEXT << "x" << YELLOW_BACKGROUND << WHITE_TEXT; // Obstacle
                foundItem = true;
                break;
            }

            currentItem = currentItem->getNext();
        }

        // If no item was found, print a blank space
        if (!foundItem && currentItem == nullptr)
        {
            cout << "\033[40m \033[43m";
        }
    }

    // Print a space if there is a path to the right, otherwise print a wall
    if (maze.ifRightExists(i, j))
    {
        cout << "\033[40m    \033[43m";
    }
    else
    {
        cout << "    ";
    }
}

// This function checks if a downward path exists from the current node in the maze. If a path exists, it prints a space, otherwise it prints a wall.
void displayDownwardPath(Graph &maze, int i, int j)
{
    if (maze.ifDownExists(i, j))
    {
        cout << "\033[40m \033[43m    ";
    }
    else
    {
        cout << "     ";
    }
}

void displayMaze(Graph &maze)
{
    for (int row = 0; row < maze.getSize(); ++row)
    {
        for (int col = 0; col < maze.getSize(); ++col)
        {
            printNodeContent(maze, col, row);
        }

        cout << endl;

        for (int col = 0; col < maze.getSize(); ++col)
        {
            displayDownwardPath(maze, col, row);
        }

        cout << endl;
    }
}

void printGrid(Graph &maze)
{
    displayMaze(maze);
}
