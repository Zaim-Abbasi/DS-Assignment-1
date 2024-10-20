/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include <iostream>
#include "Employee.h"
#include "display.h"
using namespace std;

template <typename T>
float HighestSalary(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    float highestSalary = employees[0].GetSalary(); // Initialize highestSalary with the first employee's salary
    for (int i = 1; i < maxEmployees; i++)
    {
        if (employees[i].GetSalary() > highestSalary)
            highestSalary = employees[i].GetSalary();
    }
    return highestSalary; // Return the highest salary as a float
}

template <typename T>
float LowestSalary(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    float lowestSalary = employees[0].GetSalary(); // Initialize lowestSalary with the first employee's salary
    for (int i = 1; i < maxEmployees; i++)
    {
        if (employees[i].GetSalary() < lowestSalary)
            lowestSalary = employees[i].GetSalary();
    }
    return lowestSalary;
}

template <typename T>
float SalaryRange(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    float highest = HighestSalary(employees, maxEmployees);
    float lowest = LowestSalary(employees, maxEmployees);
    return (highest - lowest);
}

template <typename T>
float MedianSalary(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    // arranging into ascending order using bubble sort
    // transfering all salaries into a new array
    float* salary = new float[maxEmployees];
    float median = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        salary[i] = employees[i].GetSalary();
    }

    // now arranging salary
    for (int i = 0; i < maxEmployees - 1; i++)
    {
        for (int j = 0; j < maxEmployees - 1 - i; j++)
        {
            // swap j with j+1
            if (salary[j + 1] < salary[j])
            {
                float temp = salary[j];
                salary[j] = salary[j + 1];
                salary[j + 1] = temp;
            }
        }
    }
    // now find middle number in the salary array
    //  (high-index + lower-index) / 2
    if (maxEmployees % 2 == 0)
    {
        // even
        int firstIndex = (maxEmployees / 2) - 1;
        int secondIndex = (maxEmployees / 2);
        median = ((salary[firstIndex] + salary[secondIndex]) / 2);
    }
    else
    {
        // odd
        // median is middle value
        int low = 0, high = maxEmployees;
        int medianIndex = (low + high) / 2;
        median = salary[medianIndex];
    }
    return median;
}

template <typename T>
void AverageSalaryforDesignation(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    // pehley designation ke index
    int se = 0, ds = 0, pm = 0, da = 0, ux = 0, qa = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        // for Software Engineer
        if (employees[i].GetDesignation() == "Software Engineer" || employees[i].GetDesignation() == "Senior Software Engineer")
        {
            se++;
        }
        else if (employees[i].GetDesignation() == "Data Scientist")
        {
            ds++;
        }
        else if (employees[i].GetDesignation() == "Project Manager")
        {
            pm++;
        }
        else if (employees[i].GetDesignation() == "Senior Data Analyst")
        {
            da++;
        }
        else if (employees[i].GetDesignation() == "UX Designer")
        {
            ux++;
        }
        else if (employees[i].GetDesignation() == "Quality Assurance Analyst")
        {
            qa++;
        }
    }
    float* seArray = new float[se];
    float* dsArray = new float[ds];
    float* pmArray = new float[pm];
    float* daArray = new float[da];
    float* uxArray = new float[ux];
    float* qaArray = new float[qa];

    se = 0, ds = 0, pm = 0, da = 0, ux = 0, qa = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        // for Software Engineer
        if (employees[i].GetDesignation() == "Software Engineer" || employees[i].GetDesignation() == "Senior Software Engineer")
        {
            seArray[se] = employees[i].GetSalary();
            se++;
        }
        else if (employees[i].GetDesignation() == "Data Scientist")
        {
            dsArray[ds] = employees[i].GetSalary();
            ds++;
        }
        else if (employees[i].GetDesignation() == "Project Manager")
        {
            pmArray[pm] = employees[i].GetSalary();
            pm++;
        }
        else if (employees[i].GetDesignation() == "Senior Data Analyst")
        {
            daArray[da] = employees[i].GetSalary();
            da++;
        }
        else if (employees[i].GetDesignation() == "UX Designer")
        {
            uxArray[ux] = employees[i].GetSalary();
            ux++;
        }
        else if (employees[i].GetDesignation() == "Quality Assurance Analyst")
        {
            qaArray[qa] = employees[i].GetSalary();
            qa++;
        }
    }

    //! ab ham ney har designation ki avergae nikalni hein
    cout << "Average Salary for Software Engineers: ";
    float total = 0;
    for (int i = 0; i < se; i++)
    {
        total += seArray[i];
    }
    cout << total / se << endl;

    total = 0;
    cout << "Average Salary for Data Scientists: ";
    for (int i = 0; i < ds; i++)
    {
        total += dsArray[i];
    }
    cout << total / ds << endl;

    total = 0;
    cout << "Average Salary for Project Managers: ";
    for (int i = 0; i < pm; i++)
    {
        total += pmArray[i];
    }
    cout << total / pm << endl;

    total = 0;
    cout << "Average Salary for Data Analyst: ";
    for (int i = 0; i < da; i++)
    {
        total += daArray[i];
    }
    cout << total / da << endl;

    total = 0;
    cout << "Average Salary for UX Designer: ";
    for (int i = 0; i < ux; i++)
    {
        total += uxArray[i];
    }
    cout << total / ux << endl;

    total = 0;
    cout << "Average Salary for Quality Assurance: ";
    for (int i = 0; i < qa; i++)
    {
        total += qaArray[i];
    }
    cout << total / qa << endl;
}

template <typename T>
void HighestSalaryEmployee(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    int highestIndex = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        if (employees[i].GetSalary() > employees[highestIndex].GetSalary())
            highestIndex = i;
    }
    DisplaySingleEmployee(employees, highestIndex);
}