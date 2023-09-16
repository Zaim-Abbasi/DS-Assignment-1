/*
Zaim Khan Abbasi
22I-2462    SE-B
DS Assignmant-1
*/
#pragma once
#include <iostream>
using namespace std;
template <typename T>
class EmployeeTemplate
{
private:
    T name;
    T employeeId;
    float salary;
    T dateOfJoin;
    T designations;

public:
    T GetName() const
    {
        return name;
    }

    T GetId() const
    {
        return employeeId;
    }

    float GetSalary() const
    {
        return salary;
    }

    T GetDateOfJoin() const
    {
        return dateOfJoin;
    }

    T GetDesignation() const
    {
        return designations;
    }

    void SetName(const T& value)
    {
        name = value;
    }

    void SetId(const T& value)
    {
        employeeId = value;
    }

    void SetSalary(float value)
    {
        salary = value;
    }

    void SetDateOfJoin(const T& value)
    {
        dateOfJoin = value;
    }

    void SetDesignation(const T& value)
    {
        designations = value;
    }
};