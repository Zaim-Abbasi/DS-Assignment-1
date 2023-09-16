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
float AverageSalary(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    float total = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        total += employees[i].GetSalary();
    }
    return (total / maxEmployees);
}

template <typename T>
int* TenureConverter(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    string temp;
    int* tenuresInDays = new int[maxEmployees];
    for (int i = 0; i < maxEmployees; i++)
    {
        temp = employees[i].GetDateOfJoin();
        int year = stoi(temp.substr(0, 4));
        int month = stoi(temp.substr(5, 2));
        int day = stoi(temp.substr(8, 2));

        // Calculate tenure in days (assuming 30 days per month)
        tenuresInDays[i] = (2023 - year) * 360 + (12 - month) * 30 + (30 - day);
    }
    return tenuresInDays;
}

template <typename T>
int AverageTenure(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    int total = 0;
    string temp;
    int* years = new int[maxEmployees];
    for (int i = 0; i < maxEmployees; i++)
    {
        temp = employees[i].GetDateOfJoin();
        temp = temp.substr(0, 4);
        years[i] = stoi(temp);
        years[i] = 2023 - years[i];
    }
    // now calculating avg
    for (int i = 0; i < maxEmployees; i++)
    {
        total += years[i];
    }
    return total / 10;
}

template <typename T>
void Distribution(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    //! Location store karwa do or baad me print kar do
    int se, ds, pm, da, ux, qa;
    se = ds = pm = da = ux = qa = 0;
    for (int i = 0; i < maxEmployees; i++)
    {
        if (employees[i].GetDesignation() == "Software Engineer" || employees[i].GetDesignation() == "Senior Software Engineer")
            se++;

        else if (employees[i].GetDesignation() == "Data Scientist")
            ds++;

        else if (employees[i].GetDesignation() == "Project Manager")
            pm++;

        else if (employees[i].GetDesignation() == "Senior Data Analyst")
            da++;

        else if (employees[i].GetDesignation() == "UX Designer")
            ux++;

        else if (employees[i].GetDesignation() == "Quality Assurance Analyst")
            qa++;

        else
            cout << "Invalid Position" << endl;
    }
    cout << "Software Engineers: " << se << endl;
    cout << "Data Scientists: " << ds << endl;
    cout << "Project Managers: " << pm << endl;
    cout << "Senior Data Analysts: " << da << endl;
    cout << "UX Designers: " << ux << endl;
    cout << "Quality Assurance Analysts: " << qa << endl;
}

template <typename T>
void HighestTenure(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    // Suppose today is 30 Dec 2023
    // We will find the highest tenure according to it
    string temp;
    int* tenuresInDays = TenureConverter(employees, maxEmployees);

    int maxTenureIndex = 0;
    for (int i = 1; i < maxEmployees; i++)
    {
        if (tenuresInDays[i] > tenuresInDays[maxTenureIndex])
            maxTenureIndex = i;
    }

    cout << "Employee with the highest tenure: \n";
    DisplaySingleEmployee(employees, maxTenureIndex);

    delete[] tenuresInDays;
}

template <typename T>
int TotalEmployees(const EmployeeTemplate<T> employees[], int maxEmployees)
{
    return maxEmployees;
}