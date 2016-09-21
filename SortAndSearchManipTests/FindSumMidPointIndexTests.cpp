#include "stdafx.h"
#include "CppUnitTest.h"
#include "Search.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SortAndSearchManip;
using namespace std;

namespace SortAndSearchManipTests
{		
	TEST_CLASS(FindSumMidPointIndexTests)
	{
	public:
		TEST_METHOD(FindSumMidPointIndex_ThreeItems)
		{
			// Arrange
			vector<int> v{1, 2, 3};

			// Act
			auto result = FindSumMidPointIndex(v);

			// Assert
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(FindSumMidPointIndex_FourItems)
		{
			// Arrange
			vector<int> v{1, 2, 3, 3};

			// Act
			auto result = FindSumMidPointIndex(v);

			// Assert
			Assert::AreEqual(2, result);
		}

		//Returns this file's directory
		#define TEST_CASE_DIRECTORY (GetDirectoryName(__FILE__))
		string GetDirectoryName(string path)
		{
			const auto last_slash_idx = path.rfind('\\');
			if(std::string::npos != last_slash_idx)
			{
				return path.substr(0, last_slash_idx + 1);
			}
			return "";
		}

		TEST_METHOD(FindSumMidPointIndex_ExtremelyLarge_Table_FileDriven)
		{
			// Arrange
			ifstream ifile;
			string filename = std::string(TEST_CASE_DIRECTORY) + "FindSumMidPointIndexTests_Input.txt";

			ifile.open(filename);
			Assert::IsTrue(ifile.is_open(), L"Failed to open test input file.");

			int T;
			ifile >> T;			

			for(auto testCase = 0; testCase < T; testCase++)
			{
				int N;
				ifile >> N;

				wstring AssertMessage = L"Test Case Number: "s + to_wstring(testCase);

				vector<int> values(N);
				for(auto in = 0u; in < values.size(); in++)
				{
					ifile >> values[in];
				}

				// Act
				auto result = FindSumMidPointIndex(values);

				// Assert
				int expected;
				ifile >> expected;
				Assert::AreEqual(expected, result, AssertMessage.c_str());
			}

			ifile.close();
		}

	};
}