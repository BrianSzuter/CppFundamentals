#pragma once
#include <memory>
#include <vector>

namespace LinkedListManip
{

	template<typename T>
	class Node
	{
	public:
		static std::unique_ptr<Node<T>> CreateList(std::vector<T>& data);

		void AppendToTail(T data);

		static std::unique_ptr<Node<T>> DeleteNode(std::unique_ptr<Node<T>> pNode, T data);

		static std::unique_ptr<Node<T>> Reverse(std::unique_ptr<Node<T>> pNode);

		Node<T>* GetNext()
		{
			return m_pNext.get();
		}

		T GetData()
		{
			return m_data;
		}

	private:
		Node(T data);

		T m_data;
		std::unique_ptr<Node<T>> m_pNext;
	};

	template<typename T>
	std::unique_ptr<Node<T>> Node<T>::CreateList(std::vector<T>& data)
	{
		if(data.empty())
			return nullptr;

		auto myList = std::unique_ptr<Node<T>>(new Node<T>(data[0]));

		for(auto i = 1u; i < data.size(); ++i)
		{
			myList->AppendToTail(data[i]);
		}

		return myList;
	}

	template<typename T>
	Node<T>::Node(T data)
		: m_data(data)
		, m_pNext(nullptr)
	{
	}

	template<typename T>
	void Node<T>::AppendToTail(T data)
	{
		auto pNewEnd = std::unique_ptr<Node<T>>(new Node<T>(data));

		auto pTheEnd = this;
		while(pTheEnd->m_pNext != nullptr)
		{
			pTheEnd = pTheEnd->GetNext();
		}

		pTheEnd->m_pNext = std::move(pNewEnd);
	}

	template<typename T>
	std::unique_ptr<Node<T>> Node<T>::DeleteNode(std::unique_ptr<Node<T>> pHead, T data)
	{
		if(!pHead)
		{
			return nullptr;
		}

		if(pHead->m_data == data)
		{
			auto pNewHead = pHead->m_pNext.release();
			return std::unique_ptr<Node<T>>(pNewHead);
		}

		auto pCurrent = pHead.get();
		while(pCurrent->m_pNext != nullptr)
		{
			if(pCurrent->m_pNext->m_data == data)
			{
				pCurrent->m_pNext.reset(pCurrent->m_pNext->m_pNext.release());
				return pHead;
			}

			pCurrent = pCurrent->GetNext();
		}

		return pHead;
	}
}