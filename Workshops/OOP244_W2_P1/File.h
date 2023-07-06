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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	bool openFile(const char filename[]);

	void closeFile();

	int noOfRecords();

	bool read(char array[]);

	bool read(int& employNum);

	bool read(double& employSal);
}
#endif // !SDDS_FILE_H_
