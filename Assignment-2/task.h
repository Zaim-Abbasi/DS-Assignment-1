/*
Zaim Khan Abbasi
22I-2462
Section B
DS-Assigment-2
*/
#pragma once
#include "skill.h"
class Task
{
public:
    static int next_id;
    int id;
    int duration;
    Skill *skill;
    Task *next;
    int dependency1;
    int dependency2;
    int earlyStart;
    int earlyFinish;
    int lateStart;
    int lateFinish;
    int slack;

    // Constructor
    Task(int duration, Skill *skill, Task *next = nullptr, int dependency1 = 0, int dependency2 = 0)
    {
        id = next_id++;
        this->duration = duration;
        this->skill = skill;
        this->next = next;
        this->dependency1 = dependency1;
        this->dependency2 = dependency2;
        this->earlyStart = 0;
        this->lateStart = 0;
        this->earlyFinish = 0;
        this->lateFinish = 0;
        this->slack = 0;
    }
};

int Task::next_id = 1;
