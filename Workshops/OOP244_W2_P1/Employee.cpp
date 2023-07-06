///////////////////////////////////////////////////////
// Workshop 3
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& localEmploy)
    {

        bool ok = false;
        char name[128];

        if (&localEmploy != nullptr)
        {
            if (read(localEmploy.m_empNo) && read(localEmploy.m_salary) && read(name))
            {
                localEmploy.m_name = new char[strLen(name) + 1];
                strCpy(localEmploy.m_name, name);
                ok = true;
            }
        }

        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        bool loading = true;
        int i = 0;


        if (openFile(DATAFILE)) {

            noOfEmployees = noOfRecords();


            employees = new Employee[noOfEmployees];


            for (i = 0; i < noOfEmployees && loading; i++)
            {
                loading = load(employees[i]);
            }

            closeFile();

        }
        else {

            cout << "Could not open data file: " << DATAFILE << endl;
        }

        if (loading)
        {
            ok = true;
        }
        else
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
        }

        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& localEmploy)
    {
        if (&localEmploy != nullptr)
        {
            cout << localEmploy.m_empNo << ": " << localEmploy.m_name << ", " << localEmploy.m_salary << endl;
        }
    }

    void display()
    {
        int i = 0;

        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        if (employees != nullptr)
        {
            sort();

            for (i = 0; i < noOfEmployees; i++)
            {
                cout << i + 1 << "- ";
                display(employees[i]);
            }
        }
        else
        {
            cout << "employees pointer is NULL. Could not display." << endl;
        }
    }
    // TODO: Implementation for the deallocateMemory function goes here

    void deallocateMemory()
    {
        int i = 0;
        for (i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }

        delete[] employees;
    }

}