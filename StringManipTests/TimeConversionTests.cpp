#include "stdafx.h"
#include "CppUnitTest.h"
#include "TimeConversion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace TimeConversionNS;

namespace StringManipTests
{		
	TEST_CLASS(TimeConversionTests)
	{
	public:
		TEST_METHOD(ToMilitaryTime_12AM)
		{
			string result = ToMilitaryTime("12:00:00AM");

			Assert::AreEqual("00:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_1AM)
		{
			string result = ToMilitaryTime("01:00:00AM");

			Assert::AreEqual("01:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_11AM)
		{
			string result = ToMilitaryTime("11:00:00AM");

			Assert::AreEqual("11:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_12PM)
		{
			string result = ToMilitaryTime("12:00:00PM");

			Assert::AreEqual("12:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_1PM)
		{
			string result = ToMilitaryTime("01:00:00PM");

			Assert::AreEqual("13:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_11PM)
		{
			string result = ToMilitaryTime("11:00:00PM");

			Assert::AreEqual("23:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_ShortHours)
		{
			string result = ToMilitaryTime("1:00:00PM");

			Assert::AreEqual("13:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_ShortMinutes)
		{
			string result = ToMilitaryTime("01:0:00PM");

			Assert::AreEqual("13:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_ShortSeconds)
		{
			string result = ToMilitaryTime("01:00:0PM");

			Assert::AreEqual("13:00:00"s, result);
		}

		TEST_METHOD(ToMilitaryTime_MissingAMPM_ThrowsException)
		{
			auto func = []() {ToMilitaryTime("01:00:00"); };
			Assert::ExpectException<invalid_argument>(func);
		}

		TEST_METHOD(ToMilitaryTime_MissingHours_ThrowsException)
		{
			auto func = []() {ToMilitaryTime(":01:00PM"); };
			Assert::ExpectException<invalid_argument>(func);
		}

		TEST_METHOD(ToMilitaryTime_MissingMinutes_ThrowsException)
		{
			auto func = []() {ToMilitaryTime("01:00PM"); };
			Assert::ExpectException<invalid_argument>(func);
		}

		TEST_METHOD(ToMilitaryTime_MissingMinutes2_ThrowsException)
		{
			auto func = []() {ToMilitaryTime("01::00PM"); };
			Assert::ExpectException<invalid_argument>(func);
		}

		TEST_METHOD(ToMilitaryTime_MissingSeconds_ThrowsException)
		{
			auto func = []() {ToMilitaryTime("01:00:PM"); };
			Assert::ExpectException<invalid_argument>(func);
		}
	};
}