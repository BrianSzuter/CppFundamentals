#include "stdafx.h"
#include "Sort.h"

using std::vector;

void MergeSort(vector<int>& array)
{
	vector<int> helper(array.size());
	MergeSort(array, helper, 0, array.size() - 1);
}

void MergeSort(vector<int>& array, vector<int>& helper, int low, int high)
{
	if(low >= high)
		return;
	
	int middle = (low + high) / 2;
	MergeSort(array, helper, low, middle);
	MergeSort(array, helper, middle + 1, high);
	Merge(array, helper, low, middle, high);	
}

void Merge(vector<int>& array, vector<int>& helper, int low, int middle, int high)
{
	for(int i = low; i <= high; i++)
	{
		helper[i] = array[i];
	}

	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;

	while(helperLeft <= middle && helperRight <= high)
	{
		if(helper[helperLeft] <= helper[helperRight])
		{
			array[current] = helper[helperLeft];
			helperLeft++;
		}
		else
		{
			array[current] = helper[helperRight];
			helperRight++;
		}
		current++;
	}

	int remaining = middle - helperLeft;
	for(int i = 0; i <= remaining; i++)
	{
		array[current + i] = helper[helperLeft + i];
	}
}

void QuickSort(vector<int>& values)
{
	QuickSort(values, 0, values.size() - 1);
}

void QuickSort(vector<int>& values, int low, int high)
{
	if(low >= high)
		return;

	int index = Partition(values, low, high);
	if(low < index - 1)
	{
		QuickSort(values, low, index - 1);
	}

	if(high > index)
	{
		QuickSort(values, index, high);
	}
}

int Partition(vector<int>& values, int low, int high)
{
	int left = low;
	int right = high;
	int pivotValue = values[(left+right)/2];

	while(left <= right)
	{
		while(values[left] < pivotValue)
		{
			++left;
		}
		while(values[right] > pivotValue)
		{
			--right;
		}

		if(left <= right)
		{
			std::swap(values[left], values[right]);
			++left;
			--right;
		}
	}

	return left;
}

int MergeTogetherSortedArrays(std::vector<int>& a, std::vector<int>& b)
{
	if(a.size() + b.size() != a.capacity())
		return -1;

	int aIndex = a.size() - 1;
	int bIndex = b.size() - 1;

	a.resize(a.capacity());
	int insertPoint = a.capacity() - 1;		

	while(aIndex >= 0 || bIndex >= 0)
	{
		int aVal = (aIndex >= 0 ? a[aIndex] : INT_MIN);
		int bVal = (bIndex >= 0 ? b[bIndex] : INT_MIN);

		if(aVal > bVal)
		{
			a[insertPoint] = aVal;
			--aIndex;
		}
		else
		{
			a[insertPoint] = bVal;
			--bIndex;
		}

		// If only 'a' elements are left, we are done
		if(bIndex < 0)
			return 0;

		--insertPoint;
	}

	return 0;
}