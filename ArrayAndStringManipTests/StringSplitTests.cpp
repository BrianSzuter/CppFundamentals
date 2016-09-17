#include "stdafx.h"
#include "CppUnitTest.h"
#include "StringSplit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace ArrayAndStringManip;

namespace ArrayAndStringManipTests
{		
	TEST_CLASS(StringSplitTests)
	{
	public:
		TEST_METHOD(StringSplit_EmptyString_EmptyVector)
		{
			// Arrange
			string s;

			// Act
			auto result = StringSplit(s, ' ');

			// Assert
			Assert::AreEqual(0u, result.size());
		}

		TEST_METHOD(StringSplit_SingleString_OneItems)
		{
			// Arrange
			string s("abc");

			// Act
			auto result = StringSplit(s, ' ');

			// Assert
			Assert::AreEqual(1u, result.size());
		}

		TEST_METHOD(StringSplit_TwoString_OneSpace_TwoItems)
		{
			// Arrange
			string s("abc xyz");

			// Act
			auto result = StringSplit(s, ' ');

			// Assert
			Assert::AreEqual(2u, result.size());
		}

		TEST_METHOD(StringSplit_TwoString_TrailingSpaces_TwoItems)
		{
			// Arrange
			string s(" abc xyz ");

			// Act
			auto result = StringSplit(s, ' ');

			// Assert
			Assert::AreEqual(2u, result.size());
		}

		TEST_METHOD(StringSplit_TwoString_TrailingCommas_TwoItems)
		{
			// Arrange
			string s(",abc,xyz,");

			// Act
			auto result = StringSplit(s, ',');

			// Assert
			Assert::AreEqual(2u, result.size());
		}

		TEST_METHOD(StringSplit_TwoString_ExtraSpaces_TwoItems)
		{
			// Arrange
			string s("abc    xyz");

			// Act
			auto result = StringSplit(s, ' ');

			// Assert
			Assert::AreEqual(2u, result.size());
		}

		TEST_METHOD(StringSplit_TwoString_ExtraCommas_TwoItems)
		{
			// Arrange
			string s("abc,,,,xyz");

			// Act
			auto result = StringSplit(s, ',');

			// Assert
			Assert::AreEqual(2u, result.size());
		}

		TEST_METHOD(StringSplit_TenStrings_TenItems)
		{
			// Arrange
			string s("a bc def   de ght ew jki 45 uio *&^");

			// Act
			auto result = StringSplit(s, ' ');

			// Assert
			Assert::AreEqual(10u, result.size());
		}
	};
}