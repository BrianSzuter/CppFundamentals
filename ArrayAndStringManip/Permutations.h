#pragma once

#include <string>
#include "ArrayAndStringManipExp.h"

namespace ArrayAndStringManip
{
	bool STRING_MANIP_DLLEXPORT IsPermutation(const std::string& string1, const std::string& string2);
	bool STRING_MANIP_DLLEXPORT IsPermutationMap(const std::string& string1, const std::string& string2);

	bool STRING_MANIP_DLLEXPORT MutateToNextPermutation(std::string& s);
};