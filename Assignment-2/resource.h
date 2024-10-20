/*
Zaim Khan Abbasi
22I-2462
Section B
DS-Assigment-2
*/
#pragma once
#include "skill.h"
class Resource
{
public:
    static int next_id;
    int id;
    int availability;
    Skill *skills;
    int numSkills;    // Number of skills for this resource
    Resource *next;

    // Constructor
    Resource(int availability, Resource *next = nullptr)
    {
        id = next_id++;
        this->availability = availability;
        this->skills = nullptr;
        this->numSkills = 0;
        this->next = next;
    }

};
int Resource::next_id = 1;