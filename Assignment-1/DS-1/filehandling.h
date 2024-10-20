/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "Employee.h"
template <typename T>

void FileHandling(EmployeeTemplate<T> employees[], int maxEmployees)
{
    ifstream myFile;
    myFile.open("Employeedata.txt");
    if (!myFile.is_open())
    {
        cout << "Cannot open file" << endl;
        exit(0);
    }

    cout << "File Opened Successfully!!" << endl;
    string line;
    // Regex objects
    regex Name("Employee Name:");
    regex id("Employee ID:");
    regex salary("Salary:");
    regex dateOfJoin("Date of Joining:");
    regex designations("Designation:");

    int employeeCounter = 0;

    while (getline(myFile, line))
    {
        if (regex_search(line, Name))
        {
            employees[employeeCounter].SetName(line.substr(line.find(":") + 2));
        }
        else if (regex_search(line, id))
        {
            employees[employeeCounter].SetId(line.substr(line.find(":") + 2));
        }
        else if (regex_search(line, salary))
        {
            string salaryStr = line.substr(line.find("$") + 1);
            salaryStr.erase(remove(salaryStr.begin(), salaryStr.end(), ','), salaryStr.end());
            float salaryValue = stof(salaryStr);
            employees[employeeCounter].SetSalary(salaryValue);
        }
        else if (regex_search(line, dateOfJoin))
        {
            employees[employeeCounter].SetDateOfJoin(line.substr(line.find(":") + 2));
        }
        else if (regex_search(line, designations))
        {
            employees[employeeCounter].SetDesignation(line.substr(line.find(":") + 2));
            employeeCounter++;
        }
    }
}