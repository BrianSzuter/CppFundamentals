#include "stdafx.h"
#include "Permutations.h"
#include <exception>

namespace StringManip
{
	// Checks if two strings are permutations of each other using sort
	bool IsPermutation(const std::string& string1, const std::string& string2)
	{

		// Cannot be permutations if lengths differ
		if(string1.length() != string2.length())
			return false;

		std::string localString1 = string1;
		std::string localString2 = string2;

		std::sort(begin(localString1), end(localString1));
		std::sort(begin(localString2), end(localString2));

		// If sorted strings are identical, it must be a permutation
		if(localString1 == localString2)
			return true;
		else
			return false;
	}

	// Checks if two strings are permutations of each other using a map
	bool IsPermutationMap(const std::string& string1, const std::string& string2)
	{
		// Cannot be permutations if lengths differ
		if(string1.length() != string2.length())
			return false;

		std::map<char, uint64_t> table;

		// Add all the characters from string1 to the map, counting occurrences
		for(auto& character : string1)
		{
			if(table.find(character) != table.end())
			{
				table[character]++;
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
				// Found an extra character in string2
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

		if(!table.empty())
			throw std::logic_error("Logic Error: Map not empty, but strings are equal length.");

		return true;
	}

	// Mutates the specified string to the next lexicographical string in place
	// Returns true if successful, false if there is no such next string
	// On failure, the original string is not modified.
	bool MutateToNextPermutation(std::string& s)
	{
		if(s.length() < 2)
		{
			return false;
		}

		// Find longest non-increasing suffix
		int SuffixIndexEnd = s.length() - 1;
		int SuffixIndexBegin = SuffixIndexEnd;
		while(s[SuffixIndexBegin - 1] >= s[SuffixIndexBegin])
		{
			SuffixIndexBegin--;
		}

		// Find the pivot
		int PivotIndex = SuffixIndexBegin - 1;

		// No Pivot -> Last Permutation, so no answer
		if(PivotIndex < 0)
		{
			return false;
		}

		// Swap right-most element that is greater than pivot with the pivot
		for(int i = SuffixIndexEnd; i >= SuffixIndexBegin; i--)
		{
			if(s[i] > s[PivotIndex])
			{
				std::swap(s[i], s[PivotIndex]);
				break;
			}

			// Not possible
			if(i == SuffixIndexBegin)
			{
				// Assert
				throw std::logic_error("Logic Error: Some element of suffix must be greater than the pivot.");
			}
		}

		// Reverse the suffix
		std::reverse(&s[SuffixIndexBegin], &s[SuffixIndexEnd + 1]);

		return true;
	}
};