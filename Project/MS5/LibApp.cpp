///////////////////////////////////////////////////////
// MS2
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;
#include "LibApp.h"
#include "Utils.h"
#include "Book.h"


namespace sdds {
	LibApp::LibApp()
	{
		m_changed = false;
		m_mainMenu = "Seneca Library Application";
		m_exitMenu = "Changes have been made to the data, what would you like to do?";
		m_publicationMenu = "Choose the type of publication:"; // MS5

		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_publicationMenu << "Book" << "Publication"; //MS5
		load();
	}
	void LibApp::run()
	{
		bool keepRunning = true;
		unsigned temp = 0;
		unsigned temp2 = 0;
		
		while (keepRunning == true)
		{
			temp = m_mainMenu.run();

			if (temp == 1)
			{
				newPublication();
			}
			else if (temp == 2)
			{
				removePublication();
			}
			else if (temp == 3)
			{
				checkOutPub();
			}
			else if (temp == 4)
			{
				returnPub();
			}
			else if (temp == 0)
			{
				if (m_changed == true)
				{
					temp2 = m_exitMenu.run();

					if (temp2 == 1)
					{
						save();
						keepRunning = false;
					}
					else if (temp2 == 0)
					{
						if (confirm("This will discard all the changes are you sure?") == true)
						{
							keepRunning = false;
						}
					}
				}
				else
				{
					keepRunning = false;
				}
			}

			cout << endl;


		}

		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
	bool LibApp::confirm(const char* message)
	{
		bool isit = false;

		if (message != nullptr)
		{
			Menu local(message);
			local << "Yes";
			if (local.run() == 1)
			{
				isit = true;
			}
		}
		
		return isit;
	}
	void LibApp::load()
	{
		Book temp{};
		int i{};
		char pType;
		cout << "Loading Data" << endl;
		ifstream reading("LibRecs.txt", ios::app);

		if (reading)
		{
			for (i = 0; reading && i < SDDS_LIBRARY_CAPACITY; i++) {
				reading >> pType;
				reading.ignore();
				if (reading) {
					if (pType == 'P')
						m_PPA[i] = new Publication;
					else if (pType == 'B')
						m_PPA[i] = new Book;
					if (m_PPA[i] != nullptr) {
						reading >> *m_PPA[i];
					}
				}
			}
		}
		else
		{
			cout << "ERROR: FILE AT LIBAPP::LOAD() FAILED TO OPEN!";
		}

		m_LLRN = i;

	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		m_changed = false;
	}
	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?") == true)
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}

	}
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?") == true)
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}

	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?") == true)
		{
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}


}