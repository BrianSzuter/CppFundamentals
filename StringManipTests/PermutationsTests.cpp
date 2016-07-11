#include "stdafx.h"
#include "CppUnitTest.h"
#include "Permutations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PermutationsNS;

namespace Chapter1Tests
{		
	TEST_CLASS(Question1_3_Tests)
	{
	public:
		TEST_METHOD(IsPermutation_EmptyStrings_ReturnsTrue)
		{
			auto result = IsPermutation("", "");
			Assert::IsTrue(result);
		}

		TEST_METHOD(IsPermutation_EmptyStringAndNonEmpty_ReturnsFalse)
		{
			auto result = IsPermutation("", "a");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutation_NonEmptyAndEmptyString_ReturnsFalse)
		{
			auto result = IsPermutation("A", "");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutation_PermutationsNoDuplicateCharacters_ReturnsTrue)
		{
			auto result = IsPermutation("blah", "lahb");
			Assert::IsTrue(result);
		}

		TEST_METHOD(IsPermutation_PermutationsWithDuplicateCharacters_ReturnsTrue)
		{
			auto result = IsPermutation("blabh", "lbahb");
			Assert::IsTrue(result);
		}

		TEST_METHOD(IsPermutation_PermutationsWithWrongNumberDuplicateCharacters_ReturnsTrue)
		{
			auto result = IsPermutation("blabhaa", "lbahabl");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutation_DifferentCases_ReturnsFalse)
		{
			auto result = IsPermutation("Blah", "lahb");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutation_DifferentWhiteSpace_ReturnsFalse)
		{
			auto result = IsPermutation("bla  h", "l ahb");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutation_TabsVersusWhiteSpace_ReturnsFalse)
		{
			auto result = IsPermutation("bla\th", "l  ahb");
			Assert::IsFalse(result);
		}

		//---------------------------------------------------------------

		TEST_METHOD(IsPermutationMap_EmptyStrings_ReturnsTrue)
		{
			auto result = IsPermutationMap("", "");
			Assert::IsTrue(result);
		}

		TEST_METHOD(IsPermutationMap_EmptyStringAndNonEmpty_ReturnsFalse)
		{
			auto result = IsPermutationMap("", "a");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_NonEmptyAndEmptyString_ReturnsFalse)
		{
			auto result = IsPermutationMap("A", "");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_PermutationsNoDuplicateCharacters_ReturnsTrue)
		{
			auto result = IsPermutationMap("blah", "lahb");
			Assert::IsTrue(result);
		}

		TEST_METHOD(IsPermutationMap_PermutationsWithDuplicateCharacters_ReturnsTrue)
		{
			auto result = IsPermutationMap("blabh", "lbahb");
			Assert::IsTrue(result);
		}

		TEST_METHOD(IsPermutationMap_PermutationsWithWrongNumberDuplicateCharacters_ReturnsTrue)
		{
			auto result = IsPermutationMap("blabhaa", "lbahabl");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_DifferentCases_ReturnsFalse)
		{
			auto result = IsPermutationMap("Blah", "lahb");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_DifferentWhiteSpace_ReturnsFalse)
		{
			auto result = IsPermutationMap("bla  h", "l ahb");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_TabsVersusWhiteSpace_ReturnsFalse)
		{
			auto result = IsPermutationMap("bla\th", "l  ahb");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_Megan)
		{
			auto result = IsPermutationMap("doog", "dogg");
			Assert::IsFalse(result);
		}
	};
}