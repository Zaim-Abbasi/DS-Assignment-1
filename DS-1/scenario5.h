/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include <iostream>
#include "Employee.h"
#include "display.h"
#include "scenario1.h"
#include "scenario4.h"
using namespace std;

template <typename T>
void YearConverter(T days)
{
    int years = 0, months = 0;
    while (days >= 365)
    {
        years++;
        days -= 365;
    }
    while (days >= 30)
    {
        months++;
        days -= 30;
    }
    cout << years << " years and " << months << " months";
}

template <typename T>
void BubbleSort_Tenure(EmployeeTemplate<T> employees[], int maxEmployees)
{
    int* tenuresInYears = TenureConverter(employees, maxEmployees);
    int comparisons = 0;
    int swaps = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // Bubble sort algorithm with comparison and swap counting
    for (int i = 0; i < maxEmployees - 1; i++)
    {
        for (int j = 0; j < maxEmployees - i - 1; j++)
        {
            comparisons++; // Increment the comparison counter
            if (tenuresInYears[j] > tenuresInYears[j + 1])
            {
                swaps++; // Increment the swap counter

                // Swap employees based on tenure
                EmployeeTemplate<T> temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;

                // Swap tenures as well
                int tempTenure = tenuresInYears[j];
                tenuresInYears[j] = tenuresInYears[j + 1];
                tenuresInYears[j + 1] = tempTenure;
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    double elapsed_time = static_cast<double>(duration.count()) / 1e6; // Convert microseconds to seconds

    // Print the sorted employees
    for (int i = 0; i < maxEmployees; i++)
    {
        cout << "Employee Name: " << employees[i].GetName() << endl;
        cout << "Employee Tenure (Years): ";
        YearConverter(tenuresInYears[i]);
        // Print other employee details as needed
        cout << "\n\n";
    }

    cout << "\n";
    // Print sorting statistics
    cout << "Bubble Sort Tenure Results:" << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    // Clean up dynamic memory
    delete[] tenuresInYears;
}

template <typename T>
void SelectionSort_Tenure(EmployeeTemplate<T> employees[], int maxEmployees)
{
    int* tenuresInYears = TenureConverter(employees, maxEmployees);
    int comparisons = 0;
    int swaps = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // Selection sort algorithm with comparison and swap counting
    for (int i = 0; i < maxEmployees - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < maxEmployees; j++)
        {
            comparisons++; // Increment the comparison counter
            if (tenuresInYears[j] < tenuresInYears[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swaps++; // Increment the swap counter

            // Swap employees based on tenure
            EmployeeTemplate<T> temp = employees[i];
            employees[i] = employees[minIndex];
            employees[minIndex] = temp;

            // Swap tenures as well
            int tempTenure = tenuresInYears[i];
            tenuresInYears[i] = tenuresInYears[minIndex];
            tenuresInYears[minIndex] = tempTenure;
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    double elapsed_time = static_cast<double>(duration.count()) / 1e6; // Convert microseconds to seconds

    // Print the sorted employees
    for (int i = 0; i < maxEmployees; i++)
    {
        cout << "Employee Name: " << employees[i].GetName() << endl;
        cout << "Employee Tenure (Years): ";
        YearConverter(tenuresInYears[i]);
        // Print other employee details as needed
        cout << "\n\n";
    }
    cout << "\n";
    // Print sorting statistics
    cout << "Selection Sort Tenure Results:" << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    // Clean up dynamic memory
    delete[] tenuresInYears;
}

template <typename T>
void InsertionSort_Tenure(EmployeeTemplate<T> employees[], int maxEmployees)
{
    int* tenuresInYears = TenureConverter(employees, maxEmployees);
    int comparisons = 0;
    int swaps = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // Insertion sort algorithm with comparison and swap counting
    for (int i = 1; i < maxEmployees; i++)
    {
        EmployeeTemplate<T> key = employees[i];
        int tenureKey = tenuresInYears[i];
        int j = i - 1;

        while (j >= 0 && tenuresInYears[j] > tenureKey)
        {
            comparisons++; // Increment the comparison counter

            employees[j + 1] = employees[j];
            tenuresInYears[j + 1] = tenuresInYears[j];

            j--;
        }

        tenuresInYears[j + 1] = tenureKey;
        employees[j + 1] = key;

        swaps++; // Increment the swap counter
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    double elapsed_time = static_cast<double>(duration.count()) / 1e6; // Convert microseconds to seconds

    // Print the sorted employees
    for (int i = 0; i < maxEmployees; i++)
    {
        cout << "Employee Name: " << employees[i].GetName() << endl;
        cout << "Employee Tenure (Years): ";
        YearConverter(tenuresInYears[i]);
        // Print other employee details as needed
        cout << "\n\n";
    }
    cout << "\n";
    // Print sorting statistics
    cout << "Insertion Sort Tenure Results:" << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    // Clean up dynamic memory
    delete[] tenuresInYears;
}
