#include "stdafx.h"
#include <sstream>
#include "StringSplit.h"
using namespace std;

namespace ArrayAndStringManip
{
	vector<string> StringSplit(const string& str, char delim)
	{
		vector<string> v;
		stringstream ss(str);
		
		while(ss)
		{
			string s;
			getline(ss, s, delim);
			if(!s.empty())
				v.push_back(s);
		}

		return move(v);
	}

}