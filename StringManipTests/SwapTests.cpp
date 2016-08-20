#include "stdafx.h"
#include "CppUnitTest.h"
#include "Swap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipTests
{		
	TEST_CLASS(SwapTests)
	{
	public:
		TEST_METHOD(SwapChars_SwapsTwoDifferentChars_CharsAreSwapped)
		{
			char first = 'x';
			char second = 'y';

			Swap::SwapChar(first, second);

			Assert::AreEqual('y', first);
			Assert::AreEqual('x', second);
		}

		TEST_METHOD(SwapChars_SwapsTwoIdenticalChars_CharsAreSwapped)
		{
			char first = 'x';
			char second = 'x';

			Swap::SwapChar(first, second);

			Assert::AreEqual('x', first);
			Assert::AreEqual('x', second);
		}
	};
}