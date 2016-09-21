#include "stdafx.h"
#include "CppUnitTest.h"
#include "Search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SortAndSearchManip;
using namespace std;

namespace SortAndSearchManipTests
{		
	TEST_CLASS(FindNumTimesRotatedTests)
	{
	public:
		TEST_METHOD(FindNumTimesRotated_MidPointIsPivot)
		{
			// Arrange
			vector<int> v{4, 5, 1, 2, 3};

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(FindNumTimesRotated_PivotIsRightOfMidPoint)
		{
			// Arrange
			vector<int> v{4, 5, 6, 7, 8, 9, 1, 2, 3};

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(6, result);
		}

		TEST_METHOD(FindNumTimesRotated_PivotIsLeftOfMidPoint)
		{
			// Arrange
			vector<int> v{9, 1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(FindNumTimesRotated_NoRotations)
		{
			// Arrange
			vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FindNumTimesRotated_MaxRotations)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(7, result);
		}

		TEST_METHOD(FindNumTimesRotated_Empty)
		{
			// Arrange
			vector<int> v;

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(FindNumTimesRotated_OneElement)
		{
			// Arrange
			vector<int> v{42};
			Assert::AreEqual(1u, v.size());

			// Act
			auto result = FindNumTimesRotated(v);

			// Assert
			Assert::AreEqual(0, result);
		}
	};
}