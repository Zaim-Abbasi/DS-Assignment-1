/*
Zaim Khan Abbasi
22I-2462
Section B
DS-Assigment-2
*/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "skill.h"
#include "task.h"
#include "resource.h"
using namespace std;

class Project
{
public:
    int id;
    int duration;
    int numTasks;
    int numResources;
    Task *tasks_head;
    Resource *resources_head;

    Project()
    {
        tasks_head = nullptr;
        resources_head = nullptr;
        numTasks = 0;
        numResources = 0;
    }

    void addResources()
    {
        cout << "Adding Resources:" << endl;

        // Input number of resources
        int numResources;
        cout << "Enter number of resources: ";
        cin >> numResources;

        //validation
        if (numResources <= 0)
        {
            cout << "Invalid number of resources!" << endl;
            return;
        }
        // Input initial availability
        int initialAvailability;
        cout << "Enter initial availability: ";
        cin >> initialAvailability;
        if (initialAvailability <= 0)
        {
            cout << "Invalid initial availability!" << endl;
            return;
        }
        // Create a new resource with auto-assigned ID and initial availability
        Resource *newResource = new Resource(initialAvailability);

        // Inputting skills
        for (int i = 0; i < numResources; i++)
        {
            int skillChoice;
            cout << "Enter Skill ID (1: Testing, 2: Designing, 3: Planning, 4: Developing): ";
            cin >> skillChoice;

            // Create a new skill based on user's choice
            Skill *newSkill = nullptr;
            switch (skillChoice)
            {
            case 1:
                newSkill = new Skill("Testing", 0.0);
                break;
            case 2:
                newSkill = new Skill("Designing", 0.0);
                break;
            case 3:
                newSkill = new Skill("Planning", 0.0);
                break;
            case 4:
                newSkill = new Skill("Developing", 0.0);
                break;
            }

            // Add the new skill to the resource
            newResource->skills = newSkill;
        }

        // Add the new resource to the project's linked list
        if (resources_head == nullptr)
        {
            resources_head = newResource;
        }
        else
        {
            Resource *currentResource = resources_head;
            while (currentResource->next != nullptr)
            {
                currentResource = currentResource->next;
            }
            currentResource->next = newResource;
        }

        // Increment the count of resources
        numResources++;
    }

    void addTask()
    {
        // Input number of tasks
        cout << "Enter number of tasks: ";
        cin >> numTasks;

        //validation
        if (numTasks <= 0)
        {
            cout << "Invalid number of tasks!" << endl;
            return;
        }
        // Initialize variables for having a track of  tasks
        Task *previousTask = nullptr;
        Task *currentTask = nullptr;

        for (int i = 0; i < numTasks; i++)
        {
            cout << endl;
            cout << "Adding Task " << i + 1 << ":" << endl;
            int duration;
            cout << "Enter duration: ";
            cin >> duration;

            // Input task dependencies
            int dependency1 = 0, dependency2 = 0;

            if (i > 0) // pehle task ke liey dependency nahi hogi
            {
                cout << "Enter dependency(0 for no dependency): ";
                cin >> dependency1;
                if (dependency1 > 0)
                {
                    cout << "Enter dependency(0 for no second dependency): ";
                    cin >> dependency2;
                }
            }

            Skill *taskSkill;

            // Input task skill
            if (i == 0)        // yani 1st task ha
            {
                currentTask = new Task(duration, taskSkill, nullptr, 0, 0);
                currentTask->earlyStart = 0;
            }
            else
            {
                currentTask = new Task(duration, taskSkill, nullptr, dependency1, dependency2);
            }

            // Add the new task to the project's linked list
            if (previousTask == nullptr)
            {
                tasks_head = currentTask;
            }
            else
            {
                previousTask->next = currentTask;
            }

            // Update the previous task
            previousTask = currentTask;
            cout << endl;
        }
    }
    void setTaskDuration(int newDuration)
    {
        // Set the duration for all tasks
        Task *currentTask = tasks_head;
        while (currentTask != nullptr)
        {
            // Set the duration
            currentTask->duration = newDuration;
            currentTask = currentTask->next;
        }
    }

    void set_nth_TaskDuration(int taskId, int newDuration)
    {
        // Set the duration for the nth task
        Task *currentTask = tasks_head;
        while (currentTask != nullptr)
        {
            // Set the duration
            if (currentTask->id == taskId)
            {
                // Set the duration
                currentTask->duration = newDuration;
                break;
            }
            currentTask = currentTask->next;
        }
    }

    void printTaskDependencyList()
    {
        // Print the task dependency list
        Task *currentTask = tasks_head;
        while (currentTask != nullptr)
        {
            // Print the task ID
            cout << "Task-" << currentTask->id << " depends on ";

            if (currentTask->dependency1 == 0 && currentTask->dependency2 == 0)
            {
                cout << "None";
            }
            else
            {
                // Print the first dependency
                if (currentTask->dependency1 > 0)
                {
                    cout << "Task-" << currentTask->dependency1;
                }

                // Print the second dependency
                if (currentTask->dependency2 > 0)
                {
                    cout << " and Task-" << currentTask->dependency2;
                }
            }

            // Move to the next task
            currentTask = currentTask->next;
            cout << endl;
        }
        cout << endl;
    }
    // Function to calculate completion time with resource proficiency
    void calculateBasicSchedule()
    {
        // Calculate the earlyStart and earlyFinish for all tasks
        Task *currentTask = tasks_head;

        // Calculate earlyStart and earlyFinish for all tasks, starting from the first task
        while (currentTask != nullptr)
        {
            // Get the dependencies
            int dependency1 = currentTask->dependency1;
            int dependency2 = currentTask->dependency2;

            int earlyFinishDependency1 = 0;
            int earlyFinishDependency2 = 0;

            // Find the earlyFinish for dependency1
            if (dependency1 > 0)
            {
                // Find the task with the given ID
                Task *dependencyTask = tasks_head;
                while (dependencyTask != nullptr)
                {
                    if (dependencyTask->id == dependency1)
                    {
                        // Found the task
                        earlyFinishDependency1 = dependencyTask->earlyFinish;
                        break;
                    }
                    dependencyTask = dependencyTask->next;
                }
            }

            // Find the earlyFinish for dependency2
            if (dependency2 > 0)
            {
                // Find the task with the given ID
                Task *dependencyTask = tasks_head;

                // jab tak dependencyTask null nahi ho jata tab tak chalao
                while (dependencyTask != nullptr)
                {
                    if (dependencyTask->id == dependency2)
                    {
                        // task mil gaya
                        earlyFinishDependency2 = dependencyTask->earlyFinish;
                        break;
                    }
                    dependencyTask = dependencyTask->next;
                }
            }

            // ab earlyStart calculate
            currentTask->earlyStart = max(earlyFinishDependency1, earlyFinishDependency2);

            // ab earlyFinish calculate
            currentTask->earlyFinish = currentTask->earlyStart + currentTask->duration;

            if (dependency1 == 0 && dependency2 == 0)
            {
                // yani koi dependency nahi hai
                currentTask->lateStart = currentTask->earlyStart;
                currentTask->lateFinish = currentTask->earlyFinish;
            }

            // Move to the next task
            currentTask = currentTask->next;
        }

        // Find the last task to initialize the lateFinish
        Task *lastTask = tasks_head;
        while (lastTask->next != nullptr)
        {
            lastTask = lastTask->next;
        }

        lastTask->lateFinish = lastTask->earlyFinish;

        // Calculate lateStart and slack for all tasks, starting from the last task
        currentTask = lastTask;

        // ab last task se pehle wale task ko calculate karna ha
        cout << "Task ID" << setw(15) << "Early Start" << setw(15) << "Early Finish" << setw(15) << "Late Start" << setw(15) << "Late Finish" << setw(15) << "Slack" << endl;

        // end tak chalao
        while (currentTask != nullptr)
        {
            // Calculate lateStart and slack
            currentTask->lateStart = currentTask->lateFinish - currentTask->duration;
            currentTask->slack = currentTask->lateStart - currentTask->earlyStart;

            // Display task details
            cout << currentTask->id << setw(15) << currentTask->earlyStart << setw(15) << currentTask->earlyFinish << setw(15) << currentTask->lateStart << setw(15) << currentTask->lateFinish << setw(15) << currentTask->slack << endl;

            // Move to the previous task
            Task *previousTask = tasks_head;
            while (previousTask->next != currentTask)
            {
                previousTask = previousTask->next;
            }

            // Update lateFinish for the previous task
            previousTask->lateFinish = currentTask->lateStart;

            // Move to the previous task
            currentTask = previousTask;
        }
        cout << endl;
        return;
    }

    void printCriticalTasks()
    {
        // Calculate the critical path and populate task data
        calculateBasicSchedule();

        int projectDuration = 0; // To calculate the project's completion time

        cout << "Critical Tasks:" << endl;

        // Display table headers
        cout << left << setw(10) << "Task ID" << setw(12) << "Early Start" << setw(12) << "Early Finish" << setw(12) << "Late Start" << setw(12) << "Late Finish" << setw(8) << "Slack" << endl;

        Task *currentTask = tasks_head;

        while (currentTask != nullptr)
        {
            if (currentTask->slack == 0)
            {
                // This task is critical
                cout << left << setw(10) << currentTask->id << setw(12) << currentTask->earlyStart << setw(12) << currentTask->earlyFinish
                     << setw(12) << currentTask->lateStart << setw(12) << currentTask->lateFinish << setw(8) << currentTask->slack << endl;

                // Update project duration
                projectDuration = max(projectDuration, currentTask->earlyFinish);
            }

            currentTask = currentTask->next;
        }

        cout << "Project Completion Time: " << projectDuration << " units." << endl;
        cout << endl;
    }

    void Display()
    {
        // tasks ko display karey ha
        cout << endl;
        cout << left << setw(12) << "Task ID" << setw(12) << "Duration"
             << "Dependencies" << endl;
        Task *currentTask = tasks_head;

        while (currentTask != nullptr)
        {
            cout << left << setw(12) << currentTask->id << setw(12) << currentTask->duration;

            if (currentTask->dependency1 != 0)
            {
                cout << "Task-" << currentTask->dependency1;

                if (currentTask->dependency2 != 0)
                {
                    cout << ", Task-" << currentTask->dependency2;
                }
            }
            else
            {
                cout << "None";
            }
            cout << endl;

            currentTask = currentTask->next;
        }
        cout << endl;
    }
};