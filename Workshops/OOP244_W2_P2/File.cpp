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
#include "File.h"

namespace sdds {

    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    bool read(char array[])
    {
        bool isSuccess = false;

        if (array != nullptr)
        {
            if (fscanf(fptr, "%[^,],", array) != -1)
            {
                isSuccess = true;
            }
        }

        return isSuccess;
    }

    bool read(unsigned int& localPop)
    {
        bool isSuccess = false;

        if (&localPop != nullptr)
        {
            if (fscanf(fptr, "%d\n", &localPop) != -1)
            {
                isSuccess = true;
            }
        }

        return isSuccess;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

}