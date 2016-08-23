
#include "stdafx.h"
#include "UniqueCharacters.h"

namespace StringManip
{

	bool HasAllUniqueCharacters(std::string input)
	{
		if(input.empty())
		{
			return true;
		}

		std::sort(begin(input), end(input));

		for(auto i = 0u; i < input.length() - 1; i++)
		{
			if(input[i] == input[i + 1])
			{
				return false;
			}
		}

		return true;
	}

	bool HasAllUniqueCharacters_AdjFind(std::string input)
	{
		if(input.empty())
		{
			return true;
		}

		std::sort(begin(input), end(input));
		auto iter = std::adjacent_find(begin(input), end(input));

		if(iter == input.end())
		{
			// No equal adjacent elements were found
			return true;
		}


		return false;
	}

	bool HasAllUniqueCharactersMap(std::string input)
	{
		if(input.empty())
		{
			return true;
		}

		std::map<char, bool> theMap;

		for(const auto& character : input)
		{
			auto result = theMap.find(character);
			if(result == theMap.end())
			{
				theMap.insert(std::make_pair(character, true));
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	bool HasAllUniqueCharactersSet(std::string input)
	{
		if(input.empty())
		{
			return true;
		}

		std::set<char> theSet;

		for(const auto& character : input)
		{
			auto result = theSet.find(character);
			if(result == theSet.end())
			{
				theSet.insert(character);
			}
			else
			{
				return false;
			}
		}

		return true;
	}
};