#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H

#include "Collection.h"

namespace sdds {
	

	// In order for this template function to work, you must supply it with four arguments when you invoke it
	// param 1: This is a template object that must be of the Collection type
	// param 2: An array that has the same type as the first param is received as an argument
	// param 3: The size of the array is sent as the argument
	// param 4: Another type of template object is sent that represents the key to be searched for in the array
	// The first template type must have a public add method that can be invoked by the template function
	// The add method must be able to accept the same object type that is invoking it as an argument
	// The object sent as the second argument must have a '==' operator overload implementation that is public
	// for the search() template function to utilize and the implementation of the '==' operator overload must accept
	// the type that KeyT as a right hand argument of '=='
	template<typename T, typename KeyT>
	bool search(Collection<T>& collection, const T colArray[], const size_t size, const KeyT& key)
	{
		size_t i{};
		bool found = false;

		for (i = 0; i < size; i++)
		{
			if (colArray[i] == key)
			{
				collection.add(colArray[i]);
				found = true;
			}
		}

		return found;
	}

	// In order for listArrayElements to be invoked and function properly, There must be a const char* argument sent,
	// , an array of any object type sent and the size of the array sent
	// The object array sent as the second argument must have a '<<' operator overload implementation that deals with
	// an ostream object on the left side and an object of its own type on the right side
	template<typename T>
	void listArrayElements(const char* title, const T objectArray[], const size_t size)
	{
		size_t i{};

		if (title != nullptr)
		{
			std::cout << title << '\n';
		}

		if (objectArray != nullptr)
		{
			for (i = 0; i < size; i++)
			{
				std::cout << i + 1 << ": " << objectArray[i] << '\n';
			}
		}
	}
}
#endif // !SDDS_SEARCHNLIST_H
