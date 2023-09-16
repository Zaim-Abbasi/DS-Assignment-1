/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include <iostream>
#include <chrono>
#include "display.h"
using namespace std;

template <typename T>
void Swap(EmployeeTemplate<T> employees[], int i, int j)
{
    // Swap entire employee objects
    EmployeeTemplate<T> temp = employees[i];
    employees[i] = employees[j];
    employees[j] = temp;
}

template <typename T>
void BubbleSort_Salary(EmployeeTemplate<T> employees[], int maxEmployees)
{
    int comparisons = 0;
    int swaps = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // Bubble sort algorithm with comparison and swap counting
    for (int i = 0; i < maxEmployees - 1; i++)
    {
        for (int j = 0; j < maxEmployees - i - 1; j++)
        {
            comparisons++; // Increment the comparison counter
            if (employees[j + 1].GetSalary() < employees[j].GetSalary())
            {
                swaps++; // Increment the swap counter

                Swap(employees, j, j + 1);
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
        cout << "Employee Salary " << employees[i].GetSalary() << endl;
        // Print other employee details as needed
        cout << endl;
    }

    // Print the results
    cout << "Bubble Sort Results:" << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

template <typename T>
void SelectionSort_Salary(EmployeeTemplate<T> employees[], int maxEmployees)
{
    int comparisons = 0;
    int swaps = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // selection sort algorithm

    for (int i = 0; i < maxEmployees; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < maxEmployees; j++)
        {
            comparisons++; // Increment the comparison counter

            if (employees[j].GetSalary() < employees[minIndex].GetSalary())
            {
                minIndex = j;
            }
        }
        // swap minIndex with i
        swaps++;
        Swap(employees, i, minIndex);
    }

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    double elapsed_time = static_cast<double>(duration.count()) / 1e6; // Convert microseconds to seconds

    // Print the sorted employees
    for (int i = 0; i < maxEmployees; i++)
    {
        cout << "Employee Name: " << employees[i].GetName() << endl;
        cout << "Employee Salary " << employees[i].GetSalary() << endl;
        // Print other employee details as needed
        cout << endl;
    }

    // Print the results
    cout << "Selection Sort Results:" << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

template <typename T>
void InsertionSort_Salary(EmployeeTemplate<T> employees[], int maxEmployees)
{
    int comparisons = 0;
    int swaps = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // Insertion sort algorithm with comparison and swap counting
    for (int i = 1; i < maxEmployees; i++)
    {
        EmployeeTemplate<T> key = employees[i]; // Store the current element to be inserted
        int j = i - 1;
        comparisons++; // Increment comparisons here

        while (j >= 0 && employees[j].GetSalary() > key.GetSalary())
        {
            employees[j + 1] = employees[j]; // Shift elements to the right
            j--;
            comparisons++; // Increment comparisons inside the loop
        }

        // Place the stored element at the correct position
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
        cout << "Employee Salary " << employees[i].GetSalary() << endl;
        // Print other employee details as needed
        cout << endl;
    }

    // Print the results
    cout << "Insertion Sort Results:" << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}
