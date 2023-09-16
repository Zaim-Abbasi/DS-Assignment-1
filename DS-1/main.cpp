/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#include <iostream>
#include <string>
#include <conio.h>
#include "Employee.h"
#include "filehandling.h"
#include "display.h"
#include "scenario1.h"
#include "scenario2.h"
#include "scenario3.h"
#include "scenario4.h"
#include "scenario5.h"
using namespace std;
int main()
{
    const int maxEmployee = 10;
    EmployeeTemplate<string> employees[maxEmployee];

    FileHandling(employees, maxEmployee);

    char scenario_changer;
    char operation_changer;

initial_start:
    system("cls");
    cout << "Welcome to Employee Management System" << endl;
    cout << "Which Scenario you want to run:" << endl;
    cout << "1. Scenario-1" << endl;
    cout << "2. Scenario-2" << endl;
    cout << "3. Scenario-3" << endl;
    cout << "4. Scenario-4" << endl;
    cout << "5. Scenario-5" << endl;
    scenario_changer = _getch();
    switch (scenario_changer)
    {

    case '1':
    {
        // scenario-1
        system("cls");
    scenario_1:
        cout << "Select an Operation you want to Perform:" << endl;
        cout << "1. Average Salary in the Company" << endl;
        cout << "2. Total Number of Employees" << endl;
        cout << "3. Average Tenure of Employees" << endl;
        cout << "4. Distribution of employees based on their designations" << endl;
        cout << "5. Employee with highest Tenure" << endl;
        cout << "0. Back" << endl;
        operation_changer = _getch();
        switch (operation_changer)
        {
        case '1':
        {
            system("cls");
            cout << "Average salary is " << AverageSalary(employees, maxEmployee) << endl;
            cout << "\n";
            goto scenario_1;
        }
        case '2':
        {
            system("cls");
            cout << "Total Number of Employees is " << TotalEmployees(employees, maxEmployee) << endl;
            cout << "\n";
            goto scenario_1;
        }
        case '3':
        {
            system("cls");
            cout << "Average Tenure is " << AverageTenure(employees, maxEmployee) << " years" << endl;
            cout << "\n";
            goto scenario_1;
        }
        case '4':
        {
            system("cls");
            Distribution(employees, maxEmployee);
            cout << "\n";
            cout << "\n";
            goto scenario_1;
        }
        case '5':
        {
            system("cls");
            HighestTenure(employees, maxEmployee);
            cout << "\n";
            goto scenario_1;
        }
        case '0':
        {
            system("cls");
            cout << "\n";
            goto initial_start;
            break;
        }
        default:
        {
            system("cls");
            cout << "Invalid Input" << endl;
            cout << "\n";
            goto scenario_1;
        }
        }
        break;
    }

    case '2':
    {
        // Scenario-2
        system("cls");
    scenario_2:
        cout << "Select an Operation you want to Perform:" << endl;
        cout << "1. Highest Salary in the Company" << endl;
        cout << "2. Lowest Salary in the Company" << endl;
        cout << "3. Salary range in the Company" << endl;
        cout << "4. Median Salary in the Company" << endl;
        cout << "5. Average Salary for each Designation" << endl;
        cout << "0. Back" << endl;
        operation_changer = _getch();
        switch (operation_changer)
        {
        case '1':
        {
            system("cls");
            cout << "Highest Salary is ";
            cout << HighestSalary(employees, maxEmployee);
            cout << "\n";
            cout << "\n";
            goto scenario_2;
        }
        case '2':
        {
            system("cls");
            cout << "Lowest Salary is " << LowestSalary(employees, maxEmployee) << endl;
            cout << "\n";
            goto scenario_2;
        }
        case '3':
        {
            system("cls");
            cout << "Salary Range is " << SalaryRange(employees, maxEmployee) << endl;
            cout << "\n";
            goto scenario_2;
        }
        case '4':
        {
            system("cls");
            cout << "Median Salary is " << MedianSalary(employees, maxEmployee) << endl;
            cout << "\n";
            goto scenario_2;
        }
        case '5':
        {
            system("cls");
            AverageSalaryforDesignation(employees, maxEmployee);
            cout << "\n";
            cout << "\n";
            goto scenario_2;
        }
        case '0':
        {
            system("cls");
            goto initial_start;
            cout << "\n";
            break;
        }
        default:
        {
            system("cls");
            cout << "Invalid Input" << endl;
            cout << "\n";
            goto scenario_2;
        }
        }

        break;
    }

    case '3':
    {
        // scenaio-3
        system("cls");
    scenario_3:
        cout << "Select an Operation you want to Perform:" << endl;
        cout << "1. Employee with the longest tenure" << endl;
        cout << "2. Employee with the shortest tenure" << endl;
        cout << "3. Average Tenure for each Designation" << endl;
        cout << "4. Highest Paying Designation" << endl;
        cout << "0. Back" << endl;
        operation_changer = _getch();
        switch (operation_changer)
        {
        case '1':
        {
            system("cls");
            HighestTenure(employees, maxEmployee);
            cout << "\n";
            goto scenario_3;
        }
        case '2':
        {
            system("cls");
            cout << "Employee with shortest Tenure is: " << endl;
            ShortestTenure(employees, maxEmployee);
            cout << "\n";
            goto scenario_3;
        }
        case '3':
        {
            system("cls");
            AverageTenureforDesignation(employees, maxEmployee);
            cout << "\n";
            goto scenario_3;
        }
        case '4':
        {
            system("cls");
            HighestPayingDesignation(employees, maxEmployee);
            cout << "\n";
            goto scenario_3;
        }
        case '0':
        {
            system("cls");
            goto initial_start;
            cout << "\n";
            break;
        }
        default:
        {
            system("cls");
            cout << "Invalid Input" << endl;
            cout << "\n";
            goto scenario_3;
        }
        }
        break;
    }

    case '4':
    {
        system("cls");
    scenario_4:
        cout << "Which Algorithm you want to rank employees based on Salary:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "0. Back" << endl;
        operation_changer = _getch();
        switch (operation_changer)
        {
        case '1':
        {
            system("cls");
            cout << "Sorting using Bubble Sort:" << endl;
            BubbleSort_Salary(employees, maxEmployee);
            cout << "\n";
            goto scenario_4;
        }
        case '2':
        {
            system("cls");
            cout << "Sorting using Selection Sort" << endl;
            SelectionSort_Salary(employees, maxEmployee);
            cout << "\n";
            goto scenario_4;
        }
        case '3':
        {
            system("cls");
            cout << "Sorting using Insertion Sort" << endl;
            InsertionSort_Salary(employees, maxEmployee);
            cout << "\n";
            goto scenario_4;
        }
        case '0':
        {
            system("cls");
            goto initial_start;
            cout << "\n";
            break;
        }
        default:
        {
            system("cls");
            cout << "Invalid Input" << endl;
            cout << "\n";
            goto scenario_4;
        }
        }
        break;
    }

    case '5':
    {
        system("cls");
    scenario_5:
        cout << "Which Algorithm you want to  to rank employees based on their tenure:" << endl;
        cout << "1. Binary Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "0. Back" << endl;
        operation_changer = _getch();
        switch (operation_changer)
        {
        case '1':
        {
            system("cls");
            cout << "Sorting using Binary Sort:" << endl;
            cout << "\n";
            BubbleSort_Tenure(employees, maxEmployee);
            cout << "\n";
            goto scenario_5;
        }
        case '2':
        {
            system("cls");
            cout << "Sorting using Selection Sort" << endl;
            SelectionSort_Tenure(employees, maxEmployee);
            cout << "\n";
            goto scenario_5;
        }
        case '3':
        {
            system("cls");
            cout << "Sorting using Insertion Sort" << endl;
            InsertionSort_Tenure(employees, maxEmployee);
            cout << "\n";
            goto scenario_5;
        }
        case '0':
        {
            system("cls");
            goto initial_start;
            cout << "\n";
            break;
        }
        default:
        {
            system("cls");
            cout << "Invalid Input" << endl;
            cout << "\n";
            goto scenario_5;
        }
        }
        break;
    }

    default:
    {
        cout << "Invalid Input" << endl;
        goto initial_start;
    }
    }

    system("pause");
    return 0;
}