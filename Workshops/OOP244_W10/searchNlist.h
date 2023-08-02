#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H

#include "Collection.h"

namespace sdds {
	

	// In order for this template function to work, you must supply it with 
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
