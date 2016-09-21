#include "stdafx.h"
#include "Search.h"
#include <vector>

using namespace std;

namespace SortAndSearchManip
{
	namespace
	{
		// Helper struct for FindIndicesOfSum
		//
		struct ValueWithID
		{
			
			int Index;	//< Original Index
			int Value;	//< Value at that Index

			ValueWithID()
				: Index(-1)
				, Value(-1)
			{
			}

			ValueWithID(int id, int value)
				: Index(id)
				, Value(value)
			{
			}

			// Less than operator for std::equal_range
			bool operator<(const ValueWithID& rhs) const
			{
				return (this->Value < rhs.Value);
			}
		};

		// Helper method for FindIndicesOfSum
		//
		// Given a vector of ValueWithIDs to search and a target Value,
		// returns the Index field of the ValueWithID that has the same Value as targetValue.
		// All items with index < start will be ignored
		// Returns -1 if the value is not found.
		//
		// Complexity: O(log(values.size()))
		int BinarySearch(const vector<ValueWithID> values, const int targetValue, const int start = 0)
		{
			int first = start;
			int last = values.size() - 1;

			while(first <= last)
			{
				int mid = (first + last) / 2;
				if(values[mid].Value == targetValue)
				{
					// Found it!
					return values[mid].Index;
				}
				else if(targetValue < values[mid].Value)
				{
					// Search again on left half
					last = mid - 1;
				}
				else
				{
					// Search again on right half
					first = mid + 1;
				}
			}

			return -1; // Not Found
		}
	}

	pair<int, int> FindIndicesOfSum(const vector<int>& v, int sum, bool UseSTL)
	{
		vector<ValueWithID> values(v.size());
		for(auto i = 0u; i < values.size(); i++)
		{
			values[i].Index = i;
			values[i].Value = v[i];
		}

		// Sort the vector so we can use Binary Search
		sort(begin(values), end(values));

		for(auto i = 0u; i < values.size(); i++)
		{
			const int remainder = sum - values[i].Value;
			int firstValueIndex = values[i].Index;			

			if(remainder <= 0)
			{
				continue;// Short circuit - not enough left for 2nd value
			}

			int secondValueIndex = -1;

			// Executes one of two possible implementations based on this flag
			if(UseSTL)
			{
				auto first = begin(values) + i + 1;
				ValueWithID desired(-1, remainder);

				auto result = equal_range(first, end(values), desired);
				if((result.first == end(values)) || (result.first == result.second))
				{
					continue; // No different 2nd value found - go on to next first value
				}

				// Get index of 2nd value
				secondValueIndex = result.first->Index;
			}
			else
			{
				// Get index of 2nd value
				secondValueIndex = BinarySearch(values, remainder, i+1);
				if(secondValueIndex == -1)
				{
					continue;// No different 2nd value found - go on to next first value
				}
			}

			if(firstValueIndex > secondValueIndex)
			{
				swap(firstValueIndex, secondValueIndex);
			}

			// Output result
			return make_pair(firstValueIndex, secondValueIndex);
		}

		return make_pair(-1, -1);
	}


	int FindSumMidPointIndex(const vector<int>& values)
	{
		int left = 0;
		int right = values.size() - 1;
		int sum = 0;
		while(left < right)
		{
			if(sum <= 0)
			{
				sum += values[left];
				left++;
			}
			else // sum > 0
			{ 
				sum -= values[right];
				right--;
			}
		}

		if(sum == 0)
		{
			// Success
			return left;
		}

		// No such index exists
		return -1;		
	}

	int FindNumTimesRotated(const vector<int>& values)
	{
		int numElements = values.size();

		int low = 0;
		int high = numElements - 1;

		while(low <= high)
		{
			if(values[low] <= values[high])
			{
				return low;
			}

			int mid = (low + high) / 2;
			int next = (mid + 1) % numElements;
			int prev = (mid - 1 + numElements) % numElements;
			if(values[mid] < values[prev] && values[mid] < values[next])
			{
				return mid;
			}

			if(values[mid] <= values[high])
			{
				high = mid - 1;
			}
			else if(values[low] <= values[mid])
			{
				low = mid + 1;
			}
		}

		return -1;
	}

	int FindValueInCircularlySortedArray(const vector<int>& values, int x)
	{
		int numElements = values.size();

		int low = 0;
		int high = numElements - 1;

		while(low <= high)
		{
			int mid = (low + high) / 2;

			if(values[mid] == x)
			{
				return mid;
			}

			if(values[mid] <= values[high]) // Right half is sorted
			{
				if(x > values[mid] && x <= values[high])// x is in sorted Right half
				{
					low = mid + 1;
				}
				else// x is NOT in sorted Right half
				{
					high = mid - 1;
				}
			}
			else// Left half is sorted
			{
				if(x < values[mid] && x >= values[low])// x is in sorted Left half
				{
					high = mid - 1;
				}
				else// x is NOT in sorted Left half
				{
					low = mid + 1;
				}
			}			
		}

		return -1;
	}
}