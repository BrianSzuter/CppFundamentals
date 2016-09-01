#pragma once

#include <string>
#include "ArrayAndStringManipExp.h"

namespace ArrayAndStringManip
{
	bool STRING_MANIP_DLLEXPORT HasAllUniqueCharacters(std::string input);

	bool STRING_MANIP_DLLEXPORT HasAllUniqueCharacters_AdjFind(std::string input);

	bool STRING_MANIP_DLLEXPORT HasAllUniqueCharactersMap(std::string input);

	bool STRING_MANIP_DLLEXPORT HasAllUniqueCharactersSet(std::string input);
};