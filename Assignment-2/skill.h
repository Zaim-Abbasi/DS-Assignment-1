/*
Zaim Khan Abbasi
22I-2462
Section B
DS-Assigment-2
*/
#pragma once
#include <iostream>
using namespace std;
class Skill
{
public:
    static int next_id;
    static Skill *skills_head;
    int id;
    string name;
    float proficiency;
    Skill *next;

    // Constructor
    Skill(string name, float proficiency)
    {
        id = next_id++;
        this->name = name;
        this->proficiency = proficiency;
        this->next = nullptr;
    }
};
int Skill::next_id = 1;