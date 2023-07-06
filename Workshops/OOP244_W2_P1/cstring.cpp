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

#include "cstring.h"

namespace sdds {

	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int i = 0;

		if (des != nullptr && src != nullptr)
		{
			for (i = 0; src[i] != '\0'; i++)
			{
				des[i] = src[i];
			}

			if (src[i] == '\0')
			{
				des[i] = src[i];
			}
		}
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int i = 0;

		if (des != nullptr && src != nullptr)
		{
			for (i = 0; src[i] != '\0' && i < len; i++)
			{
				des[i] = src[i];
			}
			
			i--;

			if (strLen(src) == len-1)
			{
				i++;
				des[i] = src[i];
			}
		}
	}

	// Compares two C-strings 
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		int i;
		int stringCase = 0;
		bool keepGoing = true;

		if (s1 != nullptr && s2 != nullptr)
		{
			for (i = 0; s1[i] != '\0' && s2[i] != '\0' && keepGoing == true; i++)
			{
				if (s1[i] > s2[i])
				{
					keepGoing = false;
					stringCase = 1;
				}
				else if (s1[i] < s2[i])
				{
					keepGoing = false;
					stringCase = -1;
				}
			}

			i--;

			if (keepGoing)
			{
				if (s1[i] > s2[i])
				{
					stringCase = 1;
				}
				else if (s1[i] < s2[i])
				{
					stringCase = -1;
				}
				else
				{
					stringCase = 0;
				}
			}
		}

		return stringCase;
	}

	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i;
		int stringCase = 0;
		bool keepGoing = true;

		if (s1 != nullptr && s2 != nullptr)
		{
			for (i = 0; s1[i] != '\0' && s2[i] != '\0' && keepGoing == true && i < len; i++)
			{
				if (s1[i] > s2[i])
				{
					keepGoing = false;
					stringCase = 1;
				}
				else if (s1[i] < s2[i])
				{
					keepGoing = false;
					stringCase = -1;
				}
			}

			i--;

			if (keepGoing && len != i)
			{
				if (s1[i] > s2[i])
				{
					stringCase = 1;
				}
				else if (s1[i] < s2[i])
				{
					stringCase = -1;
				}
				else
				{
					stringCase = 0;
				}
			}
		}

		return stringCase;
	}

	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int i = 0;

		if (s != nullptr)
		{
			for (i = 0; s[i] != '\0'; i++) {}
		}

		return i;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int i = 0;
		int j = 0;
		bool keepGoing = true;
		bool finished = false;

		if (str1 != nullptr && str2 != nullptr)
		{
			for (i = 0; str1[i] != '\0' && !finished; i++)
			{
				keepGoing = true;

				if (str1[i] == str2[0])
				{
					for (j = 1; str2[j] != '\0' && keepGoing == true; j++)
					{
						if (str1[i + j] != str2[j])
						{
							keepGoing = false;
						}
					}

					if (str2[j] == '\0')
					{
						finished = true;
					}
				}
			}

			i--;

		}


		if (finished)
		{
			return &str1[i];
		}
		else
		{
			return nullptr;
		}
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		int i;
		int j;

		if (des != nullptr && src != nullptr)
		{
			for (i = 0; des[i] != '\0'; i++) {}

			for (j = 0; src[j] != '\0'; j++)
			{
				des[i + j] = src[j];
			}

			if (src[i + j] != '\0')
			{
				des[i + j] = '\0';
			}
		}
	}

}