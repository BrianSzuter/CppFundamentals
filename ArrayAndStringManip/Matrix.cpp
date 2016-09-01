#include "stdafx.h"
#include "Matrix.h"

using std::vector;

namespace ArrayAndStringManip
{
	Matrix::Matrix()
	{
		m_MatrixData = new vector<std::vector<int>>;
	}

	Matrix::Matrix(size_t Dimension)
		: Matrix()
	{
		for(auto i = 0u; i < Dimension; i++)
		{
			vector<int> v(Dimension, 0);
			m_MatrixData->push_back(v);
		}
	}

	Matrix::~Matrix()
	{
		delete m_MatrixData;
	}

	// Rotates the matrix in-place
	void Matrix::RotateNinety(Direction dir)
	{
		// Iterate over the layers of the matrix, from outer-most to inner-most
		for(int layer = 0; layer < GetDimension() / 2; layer++)
		{
			// Create starting and ending indices for this layer
			const int start = layer;
			const int end = GetDimension() - layer - 1;

			// Iterate over the cells of the rows / columns
			for(int i = start; i < end; i++)
			{
				const int offset = i - start;
				 
				int& topleft = m_MatrixData->at(start).at(i);
				int& bottomleft = m_MatrixData->at(i).at(end);
				int& topright = m_MatrixData->at(end - offset).at(start); 
				int& bottomright = m_MatrixData->at(end).at(end - offset);

				if(dir == Direction::Clockwise)
					RotateCellsNinetyClockwise(topleft, bottomleft, bottomright, topright);
				else
					RotateCellsNinetyCounterClockwise(topleft, bottomleft, bottomright, topright);
			}
		}
	}

	void Matrix::SetCellValue(int x, int y, int val)
	{
		m_MatrixData->at(x).at(y) = val;
	}

	int Matrix::GetCellValue(int x, int y)
	{
		return m_MatrixData->at(x).at(y);
	}

	int Matrix::GetDimension()
	{
		return m_MatrixData->size();
	}

	void Matrix::RotateCellsNinetyClockwise(int & topleft, int & bottomleft, int & bottomright, int & topright)
	{
		// Save top-left layer cell
		int temp = topleft;

		topleft = bottomleft;
		bottomleft = bottomright;
		bottomright = topright;
		topright = temp;
	}

	void Matrix::RotateCellsNinetyCounterClockwise(int & topleft, int & bottomleft, int & bottomright, int & topright)
	{
		// Save top-left layer cell
		int temp = topleft;

		topleft = topright;
		topright = bottomright;
		bottomright = bottomleft;
		bottomleft = temp;
	}
}