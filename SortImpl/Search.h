#pragma once

#include <vector>
#include <utility>
#include "SortImplExp.h"

namespace SortNS
{
	// Search the vector v for 2 values that add up to sum.
	// Returns a pair of indices into v of two such values or (-1, -1) if no match is found.
	// v must only contain positive values. If multiple matches exist, any correct match might be returned.
	// The first index in the returned pair will always be less than the second index.
	SORT_IMPL_DLLEXPORT std::pair<int, int> FindIndicesOfSum(const std::vector<int>& v, int sum, bool UseSTL = true);

	// Returns the index "i" into "values" such that (v[0]+...+v[i-1] == v[i+1] +...+v[v.size()-1])
	// Returns -1 if no such index exists.
	SORT_IMPL_DLLEXPORT int FindSumMidPointIndex(const std::vector<int>& values);

	// Given a circularly sorted vector of values, returns the number of times the vector
	// has been rotated.
	// values must not have any duplicates.
	SORT_IMPL_DLLEXPORT int FindNumTimesRotated(const std::vector<int>& values);

	// Given a circularly sorted vector of values, returns the index of the specified value 'x'.
	// values must not have any duplicates.
	SORT_IMPL_DLLEXPORT int FindValueInCircularlySortedArray(const std::vector<int>& values, int x);
}
