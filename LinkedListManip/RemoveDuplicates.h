
#pragma once
#include "LinkedListManipExp.h"
#include "Node.h"

namespace LinkedListManip
{
	// Removes duplicate nodes.
	// Returns pointer to new head of the list.
	template<typename T>
	std::unique_ptr<Node<T>> RemoveDuplicates(std::unique_ptr<Node<T>> pHead)
	{
		std::map<T, int> tracker;

		auto pCurrent = pHead.get();
		while(pCurrent != nullptr)
		{
			auto data = pCurrent->GetData();
			tracker[data] += 1;

			pCurrent = pCurrent->GetNext();
		}

		for(auto& pair : tracker)
		{
			for(auto numDuplicates = pair.second - 1; numDuplicates > 0; --numDuplicates)
			{
				pHead = Node<T>::DeleteNode(std::move(pHead), pair.first);
			}
		}

		return pHead;
	}
}