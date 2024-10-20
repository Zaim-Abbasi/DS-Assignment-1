/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include "Employee.h"
template <typename T>
void DisplaySingleEmployee(const EmployeeTemplate<T> employees[], int i)
{
    cout << "Employee Name: " << employees[i].GetName() << endl;
    cout << "Employee Id: " << employees[i].GetId() << endl;
    cout << "Employee Salary: " << employees[i].GetSalary() << endl;
    cout << "Employee Date of Join: " << employees[i].GetDateOfJoin() << endl;
    cout << "Employee Designation: " << employees[i].GetDesignation() << endl;
    cout << endl;
}

template <typename T>
void Display(const EmployeeTemplate<T> employees[], int maxEmployee)
{
    for (int i = 0; i < maxEmployee; i++)
    {
        cout << "Employee Name: " << employees[i].GetName() << endl;
        cout << "Employee Id: " << employees[i].GetId() << endl;
        cout << "Employee Salary: " << employees[i].GetSalary() << endl;
        cout << "Employee Date of Join: " << employees[i].GetDateOfJoin() << endl;
        cout << "Employee Designation: " << employees[i].GetDesignation() << endl;
        cout << endl;
    }
}