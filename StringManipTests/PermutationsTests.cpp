#include "stdafx.h"
#include "CppUnitTest.h"
#include "Permutations.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PermutationsNS;
using namespace std::string_literals;
using std::string;

namespace StringManipTests
{		
	TEST_CLASS(PermutationsTests)
	{
	public:
	#pragma region "IsPermutation Tests"
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

		TEST_METHOD(IsPermutation_PermutationsWithWrongNumberDuplicateCharacters_ReturnsFalse)
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
	#pragma endregion

	#pragma region "IsPermutationMap Tests"
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

		TEST_METHOD(IsPermutationMap_PermutationsWithWrongNumberDuplicateCharacters_ReturnsFalse)
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

		TEST_METHOD(IsPermutationMap_OneCharacterDifference_ReturnsFalse)
		{
			auto result = IsPermutationMap("doog", "dogg");
			Assert::IsFalse(result);
		}

		TEST_METHOD(IsPermutationMap_DifferentLengths_ReturnsFalse)
		{
			auto result = IsPermutationMap("fooo", "foo");
			Assert::IsFalse(result);
		}
	#pragma endregion
	
	#pragma region "MutateToNextPermutation Tests"
		TEST_METHOD(MutateToNextPermutation_EmptyString_Fails)
		{
			string str("");
			auto result = MutateToNextPermutation(str);
			Assert::IsFalse(result);
			Assert::AreEqual(""s, str);
		}

		TEST_METHOD(MutateToNextPermutation_SingleChar_Fails)
		{
			string str("a");
			auto result = MutateToNextPermutation(str);
			Assert::IsFalse(result);
			Assert::AreEqual("a"s, str);
		}

		TEST_METHOD(MutateToNextPermutation_TwoCharDecreasing_Fails)
		{
			string str("cb");
			auto result = MutateToNextPermutation(str);
			Assert::IsFalse(result);
			Assert::AreEqual("cb"s, str);
		}

		TEST_METHOD(MutateToNextPermutation_NonDecreasing_Fails)
		{
			string str("fedcba");
			auto result = MutateToNextPermutation(str);
			Assert::IsFalse(result);
			Assert::AreEqual("fedcba"s, str);
		}

		TEST_METHOD(MutateToNextPermutation_TwoCharIncreasing_Success)
		{
			string str("bc");
			auto result = MutateToNextPermutation(str);
			Assert::IsTrue(result);
			Assert::AreEqual("cb"s, str);
		}

		TEST_METHOD(MutateToNextPermutation_RightmostPivot_Success)
		{
			string str("hefg");
			auto result = MutateToNextPermutation(str);
			Assert::IsTrue(result);
			Assert::AreEqual("hegf"s, str);
		}

		TEST_METHOD(MutateToNextPermutation_LeftmostPivot_Success)
		{
			string str("dedcbba");
			auto result = MutateToNextPermutation(str);
			Assert::IsTrue(result);
			Assert::AreEqual("eabbcdd"s, str);
		}

		TEST_METHOD(MutateToNextPermutation_MiddlePivot_Success)
		{
			string str("qdedcbba");
			auto result = MutateToNextPermutation(str);
			Assert::IsTrue(result);
			Assert::AreEqual("qeabbcdd"s, str);
		}
	#pragma endregion
	};
}