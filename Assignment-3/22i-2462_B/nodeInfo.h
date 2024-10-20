// Zaim Khan Abbasi_22I-2462_Assignment 3
#pragma once
#include <iostream>
using namespace std;
class NodeInfo
{
public:
    string name;
    string type;
    string path;

    NodeInfo() : name(""), path(""), type("") {}
    NodeInfo(string name, string path, string type) : name(name), path(path), type(type) {}
};
