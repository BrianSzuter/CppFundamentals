#include "stdafx.h"
#include "CppUnitTest.h"
#include "UniqueCharacters.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArrayAndStringManip;
using namespace std::string_literals;

namespace ArrayAndStringManipTests
{		
	TEST_CLASS(UniqueCharactersTests)
	{
	public:

	#pragma region "HasAllUniqueCharacters Tests"
		TEST_METHOD(HasAllUniqueCharacters_WhenSimpleDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharacters("abb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_WhenFarAwayDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharacters("abcb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_WhenNoDuplicate_ReturnsTrue)
		{
			auto result = HasAllUniqueCharacters("abc");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_EmptyString_ReturnsTrue)
		{
			auto result = HasAllUniqueCharacters("");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_SingleChar_ReturnsTrue)
		{
			auto result = HasAllUniqueCharacters("a");

			Assert::IsTrue(result);
		}
	#pragma endregion
		//---------------------------------------------------------------------
	#pragma region "HasAllUniqueCharacters_AdjFind Tests"
		TEST_METHOD(HasAllUniqueCharacters_AdjFind_WhenSimpleDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharacters_AdjFind("abb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_AdjFind_WhenFarAwayDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharacters_AdjFind("abcb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_AdjFind_WhenNoDuplicate_ReturnsTrue)
		{
			auto result = HasAllUniqueCharacters_AdjFind("abc");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_AdjFind_EmptyString_ReturnsTrue)
		{
			auto result = HasAllUniqueCharacters_AdjFind("");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharacters_AdjFind_SingleChar_ReturnsTrue)
		{
			auto result = HasAllUniqueCharacters_AdjFind("a");

			Assert::IsTrue(result);
		}
	#pragma endregion
		//---------------------------------------------------------------------
	#pragma region "HasAllUniqueCharactersMap Tests"
		TEST_METHOD(HasAllUniqueCharactersMap_WhenSimpleDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharactersMap("abb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharactersMap_WhenFarAwayDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharactersMap("abcb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharactersMap_WhenNoDuplicate_ReturnsTrue)
		{
			auto result = HasAllUniqueCharactersMap("abc");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharactersMap_EmptyString_ReturnsTrue)
		{
			auto result = HasAllUniqueCharactersMap("");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharactersMap_SingleChar_ReturnsTrue)
		{
			auto result = HasAllUniqueCharactersMap("a");

			Assert::IsTrue(result);
		}
	#pragma endregion
		//---------------------------------------------------------------------
	#pragma region "HasAllUniqueCharactersSet Tests"
		TEST_METHOD(HasAllUniqueCharactersSet_WhenSimpleDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharactersSet("abb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharactersSet_WhenFarAwayDuplicate_ReturnsFalse)
		{
			auto result = HasAllUniqueCharactersSet("abcb");

			Assert::IsFalse(result);
		}

		TEST_METHOD(HasAllUniqueCharactersSet_WhenNoDuplicate_ReturnsTrue)
		{
			auto result = HasAllUniqueCharactersSet("abc");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharactersSet_EmptyString_ReturnsTrue)
		{
			auto result = HasAllUniqueCharactersSet("");

			Assert::IsTrue(result);
		}

		TEST_METHOD(HasAllUniqueCharactersSet_SingleChar_ReturnsTrue)
		{
			auto result = HasAllUniqueCharactersSet("a");

			Assert::IsTrue(result);
		}
	#pragma endregion
		//---------------------------------------------------------------------
	#pragma region "GetFirstUniqueCharacter Tests"
		TEST_METHOD(GetFirstUniqueCharacter_EmptyString_ReturnsTrue)
		{
			auto result = GetFirstUniqueCharacter("");

			Assert::AreEqual('\0', result);
		}

		TEST_METHOD(GetFirstUniqueCharacter_FirstCharacterIsUnique_ReturnsIt)
		{
			auto result = GetFirstUniqueCharacter("hello"s);

			Assert::AreEqual('h', result);
		}

		TEST_METHOD(GetFirstUniqueCharacter_SingleCharacter_ReturnsIt)
		{
			auto result = GetFirstUniqueCharacter("a"s);

			Assert::AreEqual('a', result);
		}

		TEST_METHOD(GetFirstUniqueCharacter_NoUniques_ReturnsNothing)
		{
			auto result = GetFirstUniqueCharacter("abba"s);

			Assert::AreEqual('\0', result);
		}

		TEST_METHOD(GetFirstUniqueCharacter_MiddleCharacter_ReturnsIt)
		{
			auto result = GetFirstUniqueCharacter("abcba"s);

			Assert::AreEqual('c', result);
		}

		TEST_METHOD(GetFirstUniqueCharacter_LastCharacter_ReturnsIt)
		{
			auto result = GetFirstUniqueCharacter("abbac"s);

			Assert::AreEqual('c', result);
		}

		TEST_METHOD(GetFirstUniqueCharacter_SeveralUnique_ReturnsFirst)
		{
			auto result = GetFirstUniqueCharacter("zxvczbtxyzvy"s);

			Assert::AreEqual('c', result);
		}
	#pragma endregion
};
}