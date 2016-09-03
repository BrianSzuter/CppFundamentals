#include "stdafx.h"
#include "CppUnitTest.h"
#include "Search.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SortNS;

namespace SortImplTests
{		
	TEST_CLASS(FindIndicesOfSumTests)
	{
	public:
		TEST_METHOD(FindIndicesOfSum_FiveValues_NoDuplicates)
		{
			// Arrange
			vector<int> v{1, 4, 5, 3, 2};
			auto sum = 4;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(0, result.first);
			Assert::AreEqual(3, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_FourValues_Duplicates)
		{
			// Arrange
			vector<int> v{2, 2, 4, 3};
			auto sum = 4;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(0, result.first);
			Assert::AreEqual(1, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_ThreeValues_LargerFirst)
		{
			// Arrange
			vector<int> v{5, 75, 25};
			auto sum = 100;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(1, result.first);
			Assert::AreEqual(2, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_SevenValues_TooLargeValuesExist)
		{
			// Arrange
			vector<int> v{150, 24, 79, 50, 88, 345, 3};
			auto sum = 200;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(0, result.first);
			Assert::AreEqual(3, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_SevenValues_NoMatch)
		{
			// Arrange
			vector<int> v{150, 24, 79, 51, 88, 345, 3};
			auto sum = 200;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(-1, result.first);
			Assert::AreEqual(-1, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_OneHundredValues_MatchFound)
		{
			// Arrange
			vector<int> v{230, 863, 916, 585, 981, 404, 316, 785, 88, 12, 70, 435, 384, 778, 887, 755, 740, 337, 86, 92, 325, 422, 815, 650, 920, 125, 277, 336, 221, 847, 168, 23, 677, 61, 400, 136, 874, 363, 394, 199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422, 927, 783, 930, 282, 306, 506, 44, 926, 691, 568, 68, 730, 933, 737, 531, 180, 414, 751, 28, 546, 60, 371, 493, 370, 527, 387, 43, 541, 13, 457, 328, 227, 652, 365, 430, 803, 59, 858, 538, 427, 583, 368, 375, 173, 809, 896, 370, 789};
			auto sum = 542;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(28, result.first);
			Assert::AreEqual(45, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_SixtyFiveValues_MatchFound)
		{
			// Arrange
			vector<int> v{591, 955, 829, 805, 312, 83, 764, 841, 12, 744, 104, 773, 627, 306, 731, 539, 349, 811, 662, 341, 465, 300, 491, 423, 569, 405, 508, 802, 500, 747, 689, 506, 129, 325, 918, 606, 918, 370, 623, 905, 321, 670, 879, 607, 140, 543, 997, 530, 356, 446, 444, 184, 787, 199, 614, 685, 778, 929, 819, 612, 737, 344, 471, 645, 726};
			auto sum = 789;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(10, result.first);
			Assert::AreEqual(55, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_FiveValues_MatchFound)
		{
			// Arrange
			vector<int> v{722, 600, 905, 54, 47};
			auto sum = 101;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(3, result.first);
			Assert::AreEqual(4, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_FiftyOneValues_MatchFound)
		{
			// Arrange
			vector<int> v{210, 582, 622, 337, 626, 580, 994, 299, 386, 274, 591, 921, 733, 851, 770, 300, 380, 225, 223, 861, 851, 525, 206, 714, 985, 82, 641, 270, 5, 777, 899, 820, 995, 397, 43, 973, 191, 885, 156, 9, 568, 256, 659, 673, 85, 26, 631, 293, 151, 143, 423};
			auto sum = 35;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(39, result.first);
			Assert::AreEqual(45, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_SixtyTwoValues_MatchFound)
		{
			// Arrange
			vector<int> v{286, 461, 830, 216, 539, 44, 989, 749, 340, 51, 505, 178, 50, 305, 341, 292, 415, 40, 239, 950, 404, 965, 29, 972, 536, 922, 700, 501, 730, 430, 630, 293, 557, 542, 598, 795, 28, 344, 128, 461, 368, 683, 903, 744, 430, 648, 290, 135, 437, 336, 152, 698, 570, 3, 827, 901, 796, 682, 391, 693, 161, 145};
			auto sum = 890;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(15, result.first);
			Assert::AreEqual(34, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}

		TEST_METHOD(FindIndicesOfSum_NinetyValues_MatchFound)
		{
			// Arrange
			vector<int> v{22, 391, 140, 874, 75, 339, 439, 638, 158, 519, 570, 484, 607, 538, 459, 758, 608, 784, 26, 792, 389, 418, 682, 206, 232, 432, 537, 492, 232, 219, 3, 517, 460, 271, 946, 418, 741, 31, 874, 840, 700, 58, 686, 952, 293, 848, 55, 82, 623, 850, 619, 380, 359, 479, 48, 863, 813, 797, 463, 683, 22, 285, 522, 60, 472, 948, 234, 971, 517, 494, 218, 857, 261, 115, 238, 290, 158, 326, 795, 978, 364, 116, 730, 581, 174, 405, 575, 315, 101, 99};
			auto sum = 163;

			// Act
			auto result = FindIndicesOfSum(v, sum);
			auto result2 = FindIndicesOfSum(v, sum, false);

			// Assert
			Assert::AreEqual(54, result.first);
			Assert::AreEqual(73, result.second);

			Assert::AreEqual(result.first, result2.first);
			Assert::AreEqual(result.second, result2.second);
		}
			
	};
}