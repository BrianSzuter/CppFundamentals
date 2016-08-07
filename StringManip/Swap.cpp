
#include "stdafx.h"
#include "Swap.h"

namespace Swap
{
	// Swap two characters using no additional memory
	void SwapChar(char& a, char& b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
}