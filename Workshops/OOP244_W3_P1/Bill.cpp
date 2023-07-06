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
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax() const
    {
        int i;
        double sum = 0;

        for (i = 0; i < m_noOfItems; i++)
        {
            sum += m_items[i].tax();
        }

        return sum;
    }

    double Bill::totalPrice() const
    {
        int i;
        double sum = 0;

        for (i = 0; i < m_noOfItems; i++)
        {
            sum += m_items[i].price();
        }

        return sum;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;

        if (!isValid())
        {
            cout << "| " << std::left << std::setw(36) << m_title << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (!isValid())
        {
            cout << "|                Total Tax: " << std::right << std::setw(10) << std::setprecision(2) << totalTax() << " |" << endl;
            cout << "|              Total Price: " << std::right << std::setw(10) << std::setprecision(2) << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: " << std::setw(10) << std::setprecision(2) << totalTax() + totalPrice()  << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const
    {
        bool isit = false;
        int i;

        if (m_title[0] != '\0' && m_items != nullptr)
        {
            isit = true;

            for (i = 0; i < m_noOfItems && isit; i++)
            {
                if (m_items[i].isValid())
                {
                    isit = false;
                }
            }
        }
        else
        {
            isit= false;
        }

        return isit;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 1)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            setEmpty();
            strnCpy(m_title, title, TITLE_LENGTH);
            m_items = new Item[m_noOfItems];
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool successful = false;
        int i;

        if (m_itemsAdded < m_noOfItems)
        {
            for (i = 0; i < m_noOfItems && !successful; i++)
            {
                if (!m_items[i].isValid())
                {
                    successful = true;
                    m_items[i].set(item_name, price, taxed);
                    m_itemsAdded++;
                }
            }
        }

        return successful;
    }

    void Bill::display() const
    {
        int i;
        Title();
        for (i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {
        if (m_items != nullptr)
        {
            delete[] m_items;
            m_items = nullptr;
        }
    }

    Bill::Bill()
    {
        setEmpty();
    }

    Bill::~Bill()
    {
        deallocate();
    }
}