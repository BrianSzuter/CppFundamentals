#pragma once

#include "ArrayAndStringManipExp.h"
#include <vector>
#include <string>

namespace ArrayAndStringManip
{
	// Split a string into a vector of strings based on a delimiter character.
	// Multiple adjacent delimiters together are treated as a single delimiter.
	// An empty string is never added to the result vector.
	std::vector<std::string> STRING_MANIP_DLLEXPORT StringSplit(const std::string& str, char delim);
}
