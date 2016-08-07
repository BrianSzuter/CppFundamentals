#pragma once

#include <vector>
#include "SortImplExp.h"

namespace SortNS
{
	void SORT_IMPL_DLLEXPORT MergeSort(std::vector<int>& array);

	void MergeSort(std::vector<int>& array, std::vector<int>& helper, int low, int high);

	void Merge(std::vector<int>& array, std::vector<int>& helper, int low, int middle, int high);

	void SORT_IMPL_DLLEXPORT QuickSort(std::vector<int>& values);

	void QuickSort(std::vector<int>& values, int low, int high);

	int Partition(std::vector<int>& values, int low, int high);

	int SORT_IMPL_DLLEXPORT MergeTogetherSortedArrays(std::vector<int>& a, std::vector<int>& b);
}