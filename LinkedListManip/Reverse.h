#pragma once

#include "Exp.h"
#include "Node.h"

template<typename T>
std::unique_ptr<Node<T>> Node<T>::Reverse(std::unique_ptr<Node<T>> pHead)
{
	if(!pHead.get())
		return pHead;

	if(!pHead->GetNext())
		return pHead;

	std::unique_ptr<Node<T>> pPrevious = nullptr;
	auto pCurrent = std::move(pHead);
	auto pLeading = std::move(pCurrent->m_pNext);

	while(pCurrent != nullptr)
	{
		pCurrent->m_pNext = std::move(pPrevious);
		pPrevious = std::move(pCurrent);
		pCurrent = std::move(pLeading);
		if(pCurrent != nullptr)
		{
			pLeading = std::move(pCurrent->m_pNext);
		}
	}

	return pPrevious;
}