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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

#include "cstring.h"
#include "Population.h"
#include "File.h"

#define DATAFILE "PCpopulations.csv"

using namespace std;
namespace sdds {

    int numRecords;
    Population* populations;


    void sort()
    {
        int i, j;
        Population temp;
        for (i = numRecords - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (populations[j].pop > populations[j + 1].pop) {
                    temp = populations[j];
                    populations[j] = populations[j + 1];
                    populations[j + 1] = temp;
                }
            }
        }
    }

    void deallocateMemory()
    {
        delete[] populations;
        populations = nullptr;
    }

    bool load(Population& localPop)
    {
        bool ok = false;

        if (&localPop != nullptr)
        {
            if (read(localPop.postal) && read(localPop.pop))
            {
                ok = true;
            }
        }

        return ok;
    }

    bool load(const char filename[])
    {
        int i;
        bool ok = false;
        bool loading = true;

        if (filename != nullptr)
        {
            if (openFile(filename))
            {
                numRecords = noOfRecords();
                populations = new Population[numRecords];

                for (i = 0; i < numRecords; i++)
                {
                    loading = load(populations[i]);
                }

                closeFile();

                sort();
            }
            else
            {
                cout << "Could not open data file: " << DATAFILE << endl;
            }
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

    void display()
    {
        int i;
        int totalPop = 0;

        sort();


        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        for (i = 0; i < numRecords; i++)
        {
            cout << i + 1 << "- " << populations[i].postal << ":  " << populations[i].pop << endl;
            totalPop += populations[i].pop;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPop << endl;
    }

}