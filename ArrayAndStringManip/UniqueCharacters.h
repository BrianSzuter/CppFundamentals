#pragma once

#include <string>
#include "ArrayAndStringManipExp.h"

namespace ArrayAndStringManip
{
	// These methods will return true if the specified string contains all unique characters.
	//{
		bool STRING_MANIP_DLLEXPORT HasAllUniqueCharacters(std::string input);

		bool STRING_MANIP_DLLEXPORT HasAllUniqueCharacters_AdjFind(std::string input);

		bool STRING_MANIP_DLLEXPORT HasAllUniqueCharactersMap(std::string input);

		bool STRING_MANIP_DLLEXPORT HasAllUniqueCharactersSet(std::string input);
	//}

	// Returns the first non repeating character present in the specified string.
	// Returns '\0' if there is no repeating character.
	char STRING_MANIP_DLLEXPORT GetFirstUniqueCharacter(const std::string& input);
};