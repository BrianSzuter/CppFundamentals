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
	SORT_IMPL_DLLEXPORT std::pair<int, int> FindIndicesOfSum(const std::vector<int> v, const int sum, bool UseSTL = true);
}
