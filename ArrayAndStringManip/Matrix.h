#pragma once

#include "ArrayAndStringManipExp.h"
#include <vector>

namespace ArrayAndStringManip
{	
	enum class Direction
	{
		Clockwise,
		Counterclockwise
	};

	// Represents a Square 2 Dimensional Matrix
	//
	//      x ->
	//  y  (0,0) (1,0)
	//  |  (0,1) (1,1)
	//  v
	class STRING_MANIP_DLLEXPORT Matrix
	{
	public:
		Matrix();
		Matrix(size_t Dimension);

		~Matrix();		

		// Rotates the matrix, 90 degrees, in the specified direction, in-place
		// For Dimension = 2, the above grid would be rotated as follows:
		// (0, 1)(0, 0) 
		// (1, 1)(1, 0)
		void RotateNinety(Direction);

		void SetCellValue(int x, int y, int val);

		int GetCellValue(int x, int y);

		size_t GetDimension();

	private:
		void RotateCellsNinetyClockwise(int & topleft, int & bottomleft, int & bottomright, int & topright);
		void RotateCellsNinetyCounterClockwise(int & topleft, int & bottomleft, int & bottomright, int & topright);

		std::vector<std::vector<int>>* m_MatrixData;
	};
}