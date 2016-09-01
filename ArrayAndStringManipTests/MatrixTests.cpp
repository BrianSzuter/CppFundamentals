#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArrayAndStringManip;

namespace ArrayAndStringManipTests
{		
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(MatrixConstruction_0x0)
		{
			// Act
			Matrix m(0);

			// Assert
			auto size = m.GetDimension();
			Assert::AreEqual(size_t(0), size);
		}

		TEST_METHOD(MatrixConstruction_5x5)
		{
			// Act
			Matrix m(5);

			// Assert
			auto size = m.GetDimension();
			Assert::AreEqual(size_t(5), size);

			for(int i = 0; i < 5; i++)
			{
				for(int j = 0; j < 5; j++)
				{
					auto result = m.GetCellValue(i, j);
					Assert::AreEqual(0, result);
				}
			}
		}

		TEST_METHOD(RotateNinety_Clockwise_0x0_NoChange)
		{
			// Arrange
			Matrix m(0);

			// Act
			m.RotateNinety(Direction::Clockwise);
		}

		TEST_METHOD(RotateNinety_Clockwise_1x1_NoChange)
		{
			// Arrange
			Matrix m(1);

			m.SetCellValue(0, 0, 5);

			// Act
			m.RotateNinety(Direction::Clockwise);

			// Assert
			Assert::AreEqual(5, m.GetCellValue(0, 0));
		}

		TEST_METHOD(RotateNinety_Clockwise_2x2)
		{
			// Arrange
			Matrix m(2);

			m.SetCellValue(0, 0, 1);
			m.SetCellValue(1, 0, 2);
			m.SetCellValue(1, 1, 3);
			m.SetCellValue(0, 1, 4);

			// Act
			m.RotateNinety(Direction::Clockwise);

			// Assert
			Assert::AreEqual(4, m.GetCellValue(0, 0));
			Assert::AreEqual(1, m.GetCellValue(1, 0));
			Assert::AreEqual(2, m.GetCellValue(1, 1));
			Assert::AreEqual(3, m.GetCellValue(0, 1));
		}

		TEST_METHOD(RotateNinety_Counterclockwise_2x2)
		{
			// Arrange
			Matrix m(2);

			m.SetCellValue(0, 0, 1);
			m.SetCellValue(1, 0, 2);
			m.SetCellValue(1, 1, 3);
			m.SetCellValue(0, 1, 4);

			// Act
			m.RotateNinety(Direction::Counterclockwise);

			// Assert
			Assert::AreEqual(2, m.GetCellValue(0, 0));
			Assert::AreEqual(3, m.GetCellValue(1, 0));
			Assert::AreEqual(4, m.GetCellValue(1, 1));
			Assert::AreEqual(1, m.GetCellValue(0, 1));
		}

		TEST_METHOD(RotateNinety_Clockwise_3x3)
		{
			// Arrange
			Matrix m(3);

			m.SetCellValue(0, 0, 1);
			m.SetCellValue(1, 0, 2);
			m.SetCellValue(2, 0, 3);
			m.SetCellValue(2, 1, 4);
			m.SetCellValue(2, 2, 5);
			m.SetCellValue(1, 2, 6);
			m.SetCellValue(0, 2, 7);
			m.SetCellValue(0, 1, 8);
			m.SetCellValue(1, 1, 9);

			// Act
			m.RotateNinety(Direction::Clockwise);

			// Assert
			Assert::AreEqual(7, m.GetCellValue(0, 0));
			Assert::AreEqual(8, m.GetCellValue(1, 0));
			Assert::AreEqual(1, m.GetCellValue(2, 0));
			Assert::AreEqual(2, m.GetCellValue(2, 1));
			Assert::AreEqual(3, m.GetCellValue(2, 2));
			Assert::AreEqual(4, m.GetCellValue(1, 2));
			Assert::AreEqual(5, m.GetCellValue(0, 2));
			Assert::AreEqual(6, m.GetCellValue(0, 1));
			Assert::AreEqual(9, m.GetCellValue(1, 1));
		}

		TEST_METHOD(RotateNinety_Counterclockwise_3x3)
		{
			// Arrange
			Matrix m(3);

			m.SetCellValue(0, 0, 1);
			m.SetCellValue(1, 0, 2);
			m.SetCellValue(2, 0, 3);
			m.SetCellValue(2, 1, 4);
			m.SetCellValue(2, 2, 5);
			m.SetCellValue(1, 2, 6);
			m.SetCellValue(0, 2, 7);
			m.SetCellValue(0, 1, 8);
			m.SetCellValue(1, 1, 9);

			// Act
			m.RotateNinety(Direction::Counterclockwise);

			// Assert
			Assert::AreEqual(3, m.GetCellValue(0, 0));
			Assert::AreEqual(4, m.GetCellValue(1, 0));
			Assert::AreEqual(5, m.GetCellValue(2, 0));
			Assert::AreEqual(6, m.GetCellValue(2, 1));
			Assert::AreEqual(7, m.GetCellValue(2, 2));
			Assert::AreEqual(8, m.GetCellValue(1, 2));
			Assert::AreEqual(1, m.GetCellValue(0, 2));
			Assert::AreEqual(2, m.GetCellValue(0, 1));
			Assert::AreEqual(9, m.GetCellValue(1, 1));
		}
	};
}