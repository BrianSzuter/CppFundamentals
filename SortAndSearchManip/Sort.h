#pragma once

#include "SortAndSearchManipExp.h"
#include <vector>

namespace SortAndSearchManip
{
	void SORT_AND_SEARCH_MANIP_DLLEXPORT MergeSort(std::vector<int>& array);

	void MergeSort(std::vector<int>& array, std::vector<int>& helper, int low, int high);

	void Merge(std::vector<int>& array, std::vector<int>& helper, int low, int middle, int high);

	void SORT_AND_SEARCH_MANIP_DLLEXPORT QuickSort(std::vector<int>& values);

	void QuickSort(std::vector<int>& values, int low, int high);

	int Partition(std::vector<int>& values, int low, int high);

	int SORT_AND_SEARCH_MANIP_DLLEXPORT MergeTogetherSortedArrays(std::vector<int>& a, std::vector<int>& b);
}