#include "stdafx.h"
#include <sstream>
#include "TimeConversion.h"
using namespace std;

namespace TimeConversionNS
{

	// Format: HH:MM:SSAM or HH:MM:SSPM
	// Hours, minutes, seconds can be one or two characters
	// Does not validate that HH <= 12, MM <= 60 or SS <= 60.
	string ToMilitaryTime(const std::string& time)
	{
		vector<string> elems = SplitString(time, ':');

		const char delim = ':';
		const auto HHindex = 0u;
		const auto MMindex = 1u;
		const auto SSindex = 2u;

		// Validate overall format
		if(elems.size() != 3)
		{
			throw invalid_argument("time");
		}

		// Validate length of HH and MM
		for(auto i = 0u; i < 2; i++)
		{
			if(elems[i].length() != 1 && elems[i].length() != 2)
			{
				throw invalid_argument("time");
			}
		}

		// Validate length of SS
		auto SSLength = elems[SSindex].length();
		if(SSLength != 3 && SSLength != 4)
		{
			throw invalid_argument("time");
		}

		// Determine if the time is AM or PM
		bool isAM = (elems[SSindex][SSLength - 2] == 'A' || elems[SSindex][SSLength - 2] == 'a') ? true : false;

		// Remove AM/PM from SS
		elems[SSindex] = elems[SSindex].substr(0, SSLength - 2);

		// Adjust HH for AM/PM
		auto HH = stoi(elems[HHindex]);
		if(isAM)
		{
			if(HH == 12)
			{
				elems[HHindex] = "00";
			}
		}
		else
		{
			if(HH == 12)
			{
				// Do nothing
			}
			else
			{
				HH += 12;
				elems[HHindex] = to_string(HH);
			}
		}

		// Adjust each element for potential single-digit
		for(auto&& item : elems)
		{
			if(item.size() == 1)
			{
				item = "0"s + item;
			}
		}

		// Build result string
		ostringstream ss;
		for(auto i = 0u; i < elems.size(); i++)
		{
			ss << elems[i];
			if(i != elems.size() - 1)
				ss << ':';
		}

		return ss.str();
	}

	// Split a string into a vector of strings given the delimiter
	vector<string> SplitString(const std::string& input, char delim)
	{
		vector<string> elems;
		stringstream stime(input);

		// Split the input string
		string part;
		while(getline(stime, part, delim))
		{
			elems.push_back(part);
		}

		return elems;
	}
}