#include "stdafx.h"
#include "CppUnitTest.h"
#include "Search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SortNS;

namespace SortImplTests
{		
	TEST_CLASS(FindValueInCircularlySortedArrayTests)
	{
	public:
		TEST_METHOD(FindValueInCircularlySortedArray_MidPointIsPivot_1)
		{
			// Arrange
			vector<int> v{4, 5, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 1);

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MidPointIsPivot_2)
		{
			// Arrange
			vector<int> v{4, 5, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 2);

			// Assert
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MidPointIsPivot_5)
		{
			// Arrange
			vector<int> v{4, 5, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 5);

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MidPointIsPivot_6)
		{
			// Arrange
			vector<int> v{4, 5, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 6);

			// Assert
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsRightOfMidPoint_4)
		{
			// Arrange
			vector<int> v{4, 5, 6, 7, 8, 9, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 4);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsRightOfMidPoint_6)
		{
			// Arrange
			vector<int> v{4, 5, 6, 7, 8, 9, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 6);

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsRightOfMidPoint_9)
		{
			// Arrange
			vector<int> v{4, 5, 6, 7, 8, 9, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 9);

			// Assert
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsRightOfMidPoint_3)
		{
			// Arrange
			vector<int> v{4, 5, 6, 7, 8, 9, 1, 2, 3};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 3);

			// Assert
			Assert::AreEqual(8, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsLeftOfMidPoint_9)
		{
			// Arrange
			vector<int> v{9, 1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 9);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsLeftOfMidPoint_1)
		{
			// Arrange
			vector<int> v{9, 1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 1);

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsLeftOfMidPoint_7)
		{
			// Arrange
			vector<int> v{9, 1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 7);

			// Assert
			Assert::AreEqual(7, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_PivotIsLeftOfMidPoint_8)
		{
			// Arrange
			vector<int> v{9, 1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 8);

			// Assert
			Assert::AreEqual(8, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_NoRotations_1)
		{
			// Arrange
			vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 1);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_NoRotations_2)
		{
			// Arrange
			vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 2);

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_NoRotations_4)
		{
			// Arrange
			vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 4);

			// Assert
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_NoRotations_7)
		{
			// Arrange
			vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 7);

			// Assert
			Assert::AreEqual(6, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_NoRotations_8)
		{
			// Arrange
			vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 8);

			// Assert
			Assert::AreEqual(7, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MaxRotations_2)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 2);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MaxRotations_3)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 3);

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MaxRotations_5)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 5);

			// Assert
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MaxRotations_6)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 6);

			// Assert
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MaxRotations_8)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 8);

			// Assert
			Assert::AreEqual(6, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_MaxRotations_1)
		{
			// Arrange
			vector<int> v{2, 3, 4, 5, 6, 7, 8, 1};

			// Act
			auto result = FindValueInCircularlySortedArray(v, 1);

			// Assert
			Assert::AreEqual(7, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_Empty)
		{
			// Arrange
			vector<int> v;

			// Act
			auto result = FindValueInCircularlySortedArray(v, 4);

			// Assert
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_OneElement_42)
		{
			// Arrange
			vector<int> v{42};
			Assert::AreEqual(1u, v.size());

			// Act
			auto result = FindValueInCircularlySortedArray(v, 42);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FindValueInCircularlySortedArray_OneElement_5)
		{
			// Arrange
			vector<int> v{42};
			Assert::AreEqual(1u, v.size());

			// Act
			auto result = FindValueInCircularlySortedArray(v, 5);

			// Assert
			Assert::AreEqual(-1, result);
		}
	};
}