
#include "stdafx.h"
#include "UniqueCharacters.h"
#include <unordered_map>

using namespace std;

namespace ArrayAndStringManip
{

	bool HasAllUniqueCharacters(string input)
	{
		if(input.empty())
		{
			return true;
		}

		sort(begin(input), end(input));

		for(auto i = 0u; i < input.length() - 1; i++)
		{
			if(input[i] == input[i + 1])
			{
				return false;
			}
		}

		return true;
	}

	bool HasAllUniqueCharacters_AdjFind(string input)
	{
		if(input.empty())
		{
			return true;
		}

		sort(begin(input), end(input));
		auto iter = adjacent_find(begin(input), end(input));

		if(iter == input.end())
		{
			// No equal adjacent elements were found
			return true;
		}


		return false;
	}

	bool HasAllUniqueCharactersMap(string input)
	{
		if(input.empty())
		{
			return true;
		}

		map<char, bool> theMap;

		for(const auto& character : input)
		{
			auto result = theMap.find(character);
			if(result == theMap.end())
			{
				theMap.insert(make_pair(character, true));
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	bool HasAllUniqueCharactersSet(string input)
	{
		if(input.empty())
		{
			return true;
		}

		set<char> theSet;

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

	char GetFirstUniqueCharacter(const string& input)
	{
		unordered_map<char, int> map;
		for(auto i = 0u; i < input.length(); i++)
		{
			auto result = map.find(input[i]);
			if(result != end(map))
				result->second++;
			else
				map[input[i]] = 1;
		}

		for(auto i = 0u; i < input.length(); i++)
		{
			if(map[input[i]] == 1)
			{
				return input[i];
			}
		}
		return '\0';
	}
};