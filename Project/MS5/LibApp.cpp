#define _CRT_SECURE_NO_WARNINGS
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
#include "PublicationSelector.h"


namespace sdds {
	const Publication* const LibApp::getPub(const int libRef) const
	{
		return m_PPA[libRef] != nullptr && *m_PPA[libRef] ? m_PPA[libRef] : nullptr;
	}

	LibApp::~LibApp()
	{
		int i{};
		for (i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
		{
			delete[] m_PPA[i];
		}
	}

	LibApp::LibApp(const char filename[]) : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationMenu("Choose the type of publication:")
	{
		m_pubFileName[0] = '\0';
		m_changed = false;
		//m_mainMenu = "Seneca Library Application";
		//m_exitMenu = "Changes have been made to the data, what would you like to do?";
		//m_publicationMenu = "Choose the type of publication:"; // MS5

		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_publicationMenu << "Book" << "Publication"; //MS5
		if (filename != nullptr)
		{
			strncpy(m_pubFileName, filename, SDDS_PUBLICATION_FILE_NAME);
			load();
		}
		
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
		int i{};
		char pType;
		if (m_pubFileName != nullptr && m_pubFileName[0] != '\0')
		{
			cout << "Loading Data" << endl;
			ifstream reading(m_pubFileName, ios::app);

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
				i--;
			}
			else
			{
				cout << "ERROR: FILE AT LIBAPP::LOAD() FAILED TO OPEN!";
			}

			reading.close();
			m_NOLP = i;
			m_LLRN = m_PPA[i-1]->getRef();
		}

	}

	void LibApp::save()
	{
		int i;
		cout << "Saving Data" << endl;
		ofstream writing(m_pubFileName, ios::app);
		if (writing)
		{
			for (i = 0; writing && i < m_NOLP; i++) {

				if (m_PPA[i]->getRef() != 0)
				{
					m_PPA[i]->write(writing);
				}
			}
		}
		else
		{
			cout << "ERROR: FILE AT LIBAPP::SAVE() FAILED TO OPEN!";
		}

		writing.close();
		m_changed = false;
	}
	int LibApp::search(const int type) const
	{
		int i{};
		int libRef = 0;
		bool matchFound = false;
		unsigned choice{};
		char srchTitle[256 + 1];
		char choiceType = 'Z';
		PublicationSelector selector("Select one of the following found matches:", 15);

		choice = m_publicationMenu.run();
		if (choice == 0) {
			cout << "Aborted!";
		}
		else {
			if (choice == 1) {
				choiceType = 'B';
			}
			else if (choice == 2) {
				choiceType = 'P';
			}

			cout << "Publication Title: ";
			cin.get(srchTitle, 256, '\n');
			if (cin.peek() != '\n') {
				cin.setstate(ios::failbit);
			}
			else
			{
				cin.ignore();
			}

			if (cin.good()) {
				for (i = 0; i < m_NOLP; i++) 
				{
					if (m_PPA[i] != nullptr && *m_PPA[i] && strcmp(m_PPA[i]->operator const char* const(), srchTitle) == 0
						&& m_PPA[i]->type() == choiceType) {

						if ((type == SDDS_SEARCH_ALL) ||
							(type == SDDS_SEARCH_CHECKOUT && m_PPA[i]->onLoan()) ||
							(type == SDDS_SEARCH_AVAILABLE && !m_PPA[i]->onLoan())) {

							selector << m_PPA[i];
							matchFound = true;
						}
					}
				}

				if (matchFound)
				{
					selector.sort();
					libRef = selector.run();
					if (libRef == 0)
					{
						cout << "Aborted!";
					}
				}
				else
				{
					cout << "No matches found!";
				}
			}
			else {
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}

		return libRef;
	}
	void LibApp::returnPub()
	{
		search(SDDS_SEARCH_CHECKOUT);
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	void LibApp::newPublication()
	{
		Publication* temp{};
		unsigned pubChoice = 0;
		if (m_NOLP == SDDS_LIBRARY_CAPACITY || m_NOLP > SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!";
		}
		else
		{
			pubChoice = m_publicationMenu.run();
			if (pubChoice == 1)
			{
				temp = new Book;
			}
			else if (pubChoice == 2)
			{
				temp = new Publication;
			}

			if (pubChoice != 0)
			{
				cin >> *temp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Aborted!";
				}
				else
				{
					if (confirm("Add this publication to library?") == true)
					{
						m_changed = true;
						if (*temp)
						{
							m_LLRN++;
							temp->setRef(m_LLRN);
							m_NOLP++;
							if (m_NOLP < SDDS_LIBRARY_CAPACITY)
							{
								m_PPA[m_NOLP] = temp;
								m_changed = true;
								cout << "Publication added" << endl;
							}
							else
							{
								cout << "Publication could not be added, capacity is full" << endl;
							}
							
						}
						else
						{
							cout << "Failed to add publication!";
							delete temp;
						}
					}
					else
					{
						cout << "Aborted!";
					}
				}
			}
		}

	}
	void LibApp::removePublication()
	{
		unsigned removeRef = 0;
		cout << "Removing publication from library" << endl;
		removeRef = search(SDDS_SEARCH_ALL);
		if (removeRef != 0)
		{
			if (confirm("Remove this publication from the library?") == true)
			{
				m_PPA[removeRef]->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
			else
			{
				cout << "Aborted!";
			}
		}
	}

	void LibApp::checkOutPub()
	{
		unsigned checkout = 0;
		int tempMem{};
		bool isValid = true;

		cout << "Checkout publication from the library";
		checkout = search(SDDS_SEARCH_AVAILABLE);
		if (checkout != 0)
		{
			if (confirm("Check out publication?") == true)
			{
				cout << "Enter Membership number: ";
				do {
					isValid = true;
					cin >> tempMem;
					if (cin.fail() || tempMem > 99999 || tempMem < 10000)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(10000, '\n');
						}
						isValid = false;
						cout << "Invalid membership number, try again: " << endl;
					}
				} while (!isValid);
				
				if (m_PPA[checkout] != nullptr)
				{
					m_PPA[checkout]->set(tempMem);
					m_changed = true;
					cout << "Publication checked out" << endl;
				}
			}
			else
			{
				cout << "Aborted!";
			}
		}
	}


}
