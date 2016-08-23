
#include "stdafx.h"
#include "Swap.h"

namespace StringManip
{
	// Swap two characters using no additional memory
	void SwapChar(char& a, char& b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
}