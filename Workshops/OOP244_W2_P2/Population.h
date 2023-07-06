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

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define POSTAL 3

namespace sdds {

	struct Population
	{
		char postal[POSTAL + 1];
		unsigned int pop;
	};

	void sort();

	void deallocateMemory();

	bool load(Population& localPop);

	bool load(const char filename[]);

	void display();
}
#endif // SDDS_POPULATION_H_