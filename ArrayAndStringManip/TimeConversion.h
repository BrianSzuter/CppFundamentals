#pragma once

#include "ArrayAndStringManipExp.h"
#include <vector>
#include <string>

namespace ArrayAndStringManip
{
	std::string STRING_MANIP_DLLEXPORT ToMilitaryTime(const std::string& time);

	std::vector<std::string> SplitString(const std::string& input, char delim);
}