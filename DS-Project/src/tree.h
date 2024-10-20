#pragma once

#include <iostream>
#include <string>
#include <fstream>
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
using namespace std;
class TreeNode
{
public:
    int score;
    string name;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int s, const string &n) : score(s), name(n), left(nullptr), right(nullptr) {}
};

// Binary Tree Class
class BinaryTree
{
private:
    TreeNode *root;

    void insert(TreeNode *&node, int score, const string &name)
    {
        if (node == nullptr)
        {
            node = new TreeNode(score, name);
        }
        else if (score > node->score)
        {
            insert(node->right, score, name);
        }
        else
        {
            insert(node->left, score, name);
        }
    }

    void saveScoresToFile(TreeNode *node, ofstream &outFile)
    {
        if (node == nullptr)
            return;

        saveScoresToFile(node->left, outFile);
        outFile << node->score << " " << node->name << endl;
        saveScoresToFile(node->right, outFile);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insertScore(int score, const string &name)
    {
        insert(root, score, name);
    }

    void saveScoresToFile(const string &filename)
    {
        ofstream outFile(filename, ios::app); // Append to the file instead of overwriting
        if (outFile.is_open())
        {
            saveScoresToFile(root, outFile);
            outFile.close();
        }
        else
        {
            cerr << "Error: Unable to open the file for saving scores." << endl;
        }
    }

    void loadScoresFromFile(const string &filename)
    {
        ifstream inFile(filename);
        int score;
        string name;

        if (inFile.is_open())
        {
            while (inFile >> score >> name)
            {
                insertScore(score, name);
            }

            inFile.close();
        }
        else
        {
            cerr << "Error: Unable to open the file for reading scores." << endl;
        }
    }

    void displayScores()
    {
        // Load scores from the file
        loadScoresFromFile("scores.txt");

        if (root == nullptr)
        {
            cout << "No scores available." << endl;
            return;
        }

        // Display sorted scores
        cout << "High Scores:" << endl;
        displayInorder(root);
    }

private:
    // Inorder traversal to display scores
    void displayInorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        displayInorder(node->right);
        cout << node->name << "\t" << node->score << endl; // Display the score
        displayInorder(node->left);
    }
};