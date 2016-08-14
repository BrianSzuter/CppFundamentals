#pragma once

#include "StringManipExp.h"
#include <vector>
#include <string>

namespace TimeConversionNS
{
	std::string STRING_MANIP_DLLEXPORT ToMilitaryTime(const std::string& time);

	std::vector<std::string> SplitString(const std::string& input, char delim);
}