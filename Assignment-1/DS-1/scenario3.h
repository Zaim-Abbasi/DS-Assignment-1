/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include <iostream>
#include "Employee.h"
#include "scenario1.h"
#include "display.h"
using namespace std;

template <typename T>
void LongestTenure(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    HighestTenure(employees, maxEmployees);
}

template <typename T>
void ShortestTenure(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    string temp;
    int* tenuresInDays = TenureConverter(employees, maxEmployees);

    // Find the index of the employee with the highest tenure
    int minTenureIndex = 0;
    for (int i = 1; i < maxEmployees; i++)
    {
        if (tenuresInDays[i] < tenuresInDays[minTenureIndex])
            minTenureIndex = i;
    }

    DisplaySingleEmployee(employees, minTenureIndex);

    delete[] tenuresInDays;
}

template <typename T>
void DaysConverter(T days)
{
    int years = 0, months = 0;
    while (days >= 365)
    {
        if (days > 365)
        {
            years++;
            days -= 365;
        }
        if (days > 30)
        {
            months++;
            days -= 30;
        }
    }
    cout << "Average Tenure is " << years << " years and " << months << " months" << endl;
}

template <typename T>
void AverageTenureforDesignation(const EmployeeTemplate<T> employees[], int maxEmployees)
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
    int* seArray = new int[se];
    int* dsArray = new int[ds];
    int* pmArray = new int[pm];
    int* daArray = new int[da];
    int* uxArray = new int[ux];
    int* qaArray = new int[qa];

    int* tenuresInDays = TenureConverter(employees, maxEmployees);
    se = 0, ds = 0, pm = 0, da = 0, ux = 0, qa = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        // for Software Engineer
        if (employees[i].GetDesignation() == "Software Engineer" || employees[i].GetDesignation() == "Senior Software Engineer")
        {
            //! is me se ke tenure dalney hein

            seArray[se] = tenuresInDays[i];
            se++;
        }
        else if (employees[i].GetDesignation() == "Data Scientist")
        {
            dsArray[ds] = tenuresInDays[i];
            ds++;
        }
        else if (employees[i].GetDesignation() == "Project Manager")
        {
            pmArray[pm] = tenuresInDays[i];
            pm++;
        }
        else if (employees[i].GetDesignation() == "Senior Data Analyst")
        {
            daArray[da] = tenuresInDays[i];
            da++;
        }
        else if (employees[i].GetDesignation() == "UX Designer")
        {
            uxArray[ux] = tenuresInDays[i];
            ux++;
        }
        else if (employees[i].GetDesignation() == "Quality Assurance Analyst")
        {
            qaArray[qa] = tenuresInDays[i];
            qa++;
        }
    }

    int days = 0;
    //! ab ham ney har designation ki avergae nikalni hein
    cout << "Designation Average for Software Engineers:";
    int total = 0;
    for (int i = 0; i < se; i++)
    {
        total += seArray[i];
    }
    days = (total / se);

    DaysConverter(days);

    total = 0;
    cout << "Designation Average for Data Scientists:";
    for (int i = 0; i < ds; i++)
    {
        total += dsArray[i];
    }
    days = (total / ds);
    DaysConverter(days);

    total = 0;
    cout << "Designation Average for Project Managers:";
    for (int i = 0; i < pm; i++)
    {
        total += pmArray[i];
    }
    days = (total / pm);
    DaysConverter(days);

    total = 0;
    cout << "Designation Average for Data Analyst:";
    for (int i = 0; i < da; i++)
    {
        total += daArray[i];
    }
    days = (total / pm);
    DaysConverter(days);

    total = 0;
    cout << "Designation Average for UX Designer:";
    for (int i = 0; i < ux; i++)
    {
        total += uxArray[i];
    }
    days = (total / pm);
    DaysConverter(days);

    total = 0;
    cout << "Designation Average for Quality Assurance:";
    for (int i = 0; i < qa; i++)
    {
        total += qaArray[i];
    }
    days = (total / pm);
    DaysConverter(days);
}

template <typename T>
void HighestPayingDesignation(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    int highestIndex = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        if (employees[i].GetSalary() > employees[highestIndex].GetSalary())
            highestIndex = i;
    }
    cout << "The Highest paying Designation is " << employees[highestIndex].GetDesignation() << endl;
}