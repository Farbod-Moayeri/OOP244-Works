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

    FILE* fptr = nullptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int tempInt;
      double tempDouble;
      char tempArray[1000];

      int noOfRecs = 0;
      //char ch = 0;
      while (fscanf(fptr, "%d,%lf,%999[^\n]%*c", &tempInt, &tempDouble, tempArray) == 3) {

          noOfRecs++;
      }

     
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
      fptr = nullptr;
   }

   // TODO: read functions go here    
   bool read(char array[])
   {

       bool isSuccess = false;
        
       if (array != nullptr)
       {
           if (fscanf(fptr, "%[^\n]\n", array) != -1)
           {
               isSuccess = true;
           }
       }
       
       return isSuccess;
   }

   bool read(int &employNum) 
   {

       bool isSuccess = false;

       if (&employNum != nullptr)
       {
           if (fscanf(fptr, "%d,", &employNum) != -1)
           {
               isSuccess = true;
           }
       }

       return isSuccess;
   }

   bool read(double &employSal) {
       
       bool isSuccess = false;

       if (&employSal != nullptr)
       {
           if (fscanf(fptr, "%lf,", &employSal) != -1)
           {
               isSuccess = true;
           }
       }

       return isSuccess;
   }
   
}