#include "stdafx.h"
#include "Permutations.h"

namespace PermutationsNS
{

	bool IsPermutation(const std::string& string1, const std::string& string2)
	{
		if(string1.length() != string2.length())
			return false;

		std::string localString1 = string1;
		std::string localString2 = string2;

		std::sort(begin(localString1), end(localString1));
		std::sort(begin(localString2), end(localString2));

		if(localString1 == localString2)
			return true;
		else
			return false;
	}

	bool IsPermutationMap(const std::string& string1, const std::string& string2)
	{
		if(string1.length() != string2.length())
			return false;

		std::map<char, uint64_t> table;

		for(auto& character : string1)
		{
			if(table.find(character) != table.end())
			{
				table[character] = ++table[character];
			}
			else
			{
				table[character] = 1;
			}
		}

		for(auto& character : string2)
		{
			auto theItem = table.find(character);
			if(theItem == table.end())
			{
				return false;
			}
			else if(table[character] == 1)
			{
				table.erase(theItem);				
			}
			else
			{
				table[character] = --table[character];
			}
		}

		return true;
	}
};