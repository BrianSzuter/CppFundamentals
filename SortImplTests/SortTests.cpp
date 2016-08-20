#include "stdafx.h"
#include "CppUnitTest.h"
#include "Sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::vector;

namespace SortImplTests
{		
	TEST_CLASS(SortTests)
	{
	public:
	#pragma region MergeSort Tests
		TEST_METHOD(MergeSort_Sort0Items_EmptyReturned)
		{
			vector<int> theVector{};

			SortNS::MergeSort(theVector);

			vector<int> expected{};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(MergeSort_Sort1Item_OneReturned)
		{
			vector<int> theVector{5};

			SortNS::MergeSort(theVector);

			vector<int> expected{5};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(MergeSort_Sort2Items_ItemsSorted)
		{
			vector<int> theVector{5, 2};

			SortNS::MergeSort(theVector);

			vector<int> expected{2, 5};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(MergeSort_Sort4Items_ItemsSorted)
		{
			vector<int> theVector{5, 2, 1, 0};

			SortNS::MergeSort(theVector);

			vector<int> expected{0, 1, 2, 5};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(MergeSort_Sort5Items_ItemsSorted)
		{
			vector<int> theVector{5, 2, 7, 11, 9};

			SortNS::MergeSort(theVector);

			vector<int> expected{2, 5, 7, 9, 11};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(MergeSort_Sort5000Items_ItemsSorted)
		{
			constexpr size_t NumItems = 5000;
			vector<int> theVector(NumItems);
			for(int i = 0; i < NumItems; i++)
			{
				theVector[i] = NumItems - i - 1;				
			}

			SortNS::MergeSort(theVector);

			vector<int> expected(NumItems);
			for(int i = 0; i < NumItems; i++)
			{
				expected[i] = i;
			}

			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(MergeSort_Sort5ItemsDuplicates_ItemsSorted)
		{
			vector<int> theVector{5, 5, 5, 5, 5};

			SortNS::MergeSort(theVector);

			vector<int> expected{5, 5, 5, 5, 5};
			Assert::IsTrue(expected == theVector);
		}
	#pragma endregion
	#pragma region QuickSort Tests
		TEST_METHOD(QuickSort_Sort0Items_EmptyReturned)
		{
			vector<int> theVector{};

			SortNS::QuickSort(theVector);

			vector<int> expected{};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort1Item_OneReturned)
		{
			vector<int> theVector{5};

			SortNS::QuickSort(theVector);

			vector<int> expected{5};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort2Items_ItemsSorted)
		{
			vector<int> theVector{5, 2};

			SortNS::QuickSort(theVector);

			vector<int> expected{2, 5};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort4Items_ItemsSorted)
		{
			vector<int> theVector{5, 2, 1, 0};

			SortNS::QuickSort(theVector);

			vector<int> expected{0, 1, 2, 5};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort5Items_ItemsSorted)
		{
			vector<int> theVector{5, 2, 7, 11, 9};

			SortNS::QuickSort(theVector);

			vector<int> expected{2, 5, 7, 9, 11};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort5000Items_ItemsSorted)
		{
			constexpr size_t NumItems = 5000;
			vector<int> theVector(NumItems);
			for(int i = 0; i < NumItems; i++)
			{
				theVector[i] = NumItems - i - 1;
			}

			SortNS::QuickSort(theVector);

			vector<int> expected(NumItems);
			for(int i = 0; i < NumItems; i++)
			{
				expected[i] = i;
			}

			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort5ItemsWorstCasePivot_ItemsSorted)
		{
			vector<int> theVector{5, 9, 11, 7, 2};

			SortNS::QuickSort(theVector);

			vector<int> expected{2, 5, 7, 9, 11};
			Assert::IsTrue(expected == theVector);
		}

		TEST_METHOD(QuickSort_Sort5ItemsDuplicates_ItemsSorted)
		{
			vector<int> theVector{5, 5, 5, 5, 5};

			SortNS::QuickSort(theVector);

			vector<int> expected{5, 5, 5, 5, 5};
			Assert::IsTrue(expected == theVector);
		}
	#pragma endregion
	#pragma region MergeTogetherSortedArrays Sort Tests
		TEST_METHOD(MergeTogetherSortedArrays_InterlacedValues_ItemsSorted)
		{
			vector<int> a{1, 3, 5, 6};
			a.resize(7);
			a.resize(4);
			vector<int> b{2, 4, 7};

			auto retval = SortNS::MergeTogetherSortedArrays(a, b);
			
			Assert::AreEqual(0, retval);
			vector<int> expected{1, 2, 3, 4, 5, 6, 7};
			Assert::IsTrue(expected == a);
		}

		TEST_METHOD(MergeTogetherSortedArrays_AHasAllGreaterValues_ItemsSorted)
		{
			vector<int> a{8, 9, 10, 11};
			a.resize(7);
			a.resize(4);
			vector<int> b{2, 4, 7};

			auto retval = SortNS::MergeTogetherSortedArrays(a, b);

			Assert::AreEqual(0, retval);
			vector<int> expected{2, 4, 7, 8, 9, 10, 11};
			Assert::IsTrue(expected == a);
		}

		TEST_METHOD(MergeTogetherSortedArrays_AHasAllLesserValues_ItemsSorted)
		{
			vector<int> a{1, 3, 4, 5};
			a.resize(7);
			a.resize(4);
			vector<int> b{6, 7, 8};

			auto retval = SortNS::MergeTogetherSortedArrays(a, b);

			Assert::AreEqual(0, retval);
			vector<int> expected{1, 3, 4, 5, 6, 7, 8};
			Assert::IsTrue(expected == a);
		}

		TEST_METHOD(MergeTogetherSortedArrays_AIsEmpty_ItemsSorted)
		{
			vector<int> a(3);
			a.resize(0);
			vector<int> b{6, 7, 8};

			auto retval = SortNS::MergeTogetherSortedArrays(a, b);

			Assert::AreEqual(0, retval);
			vector<int> expected{6, 7, 8};
			Assert::IsTrue(expected == a);
		}

		TEST_METHOD(MergeTogetherSortedArrays_BIsEmpty_ItemsSorted)
		{
			vector<int> a{1, 3, 4, 5};
			vector<int> b(0);

			auto retval = SortNS::MergeTogetherSortedArrays(a, b);

			Assert::AreEqual(0, retval);
			vector<int> expected{1, 3, 4, 5};
			Assert::IsTrue(expected == a);
		}

		TEST_METHOD(MergeTogetherSortedArrays_BothAreEmpty_ItemsSorted)
		{
			vector<int> a(0);
			vector<int> b(0);

			auto retval = SortNS::MergeTogetherSortedArrays(a, b);

			Assert::AreEqual(0, retval);
			vector<int> expected(0);
			Assert::IsTrue(expected == a);
		}
	#pragma endregion
	};
}