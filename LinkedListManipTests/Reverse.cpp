#include "stdafx.h"
#include "Reverse.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chapter2Tests
{		
	TEST_CLASS(Chapter2Tests)
	{
	public:
		TEST_METHOD(Reverse_EmptyList_ReturnsEmptyList)
		{
			std::vector<char> init = {};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = Node<char>::Reverse(std::move(pTheList));

			Assert::IsNull(pTheList.get());
		}

		TEST_METHOD(Reverse_SingleElement_ReturnsSameList)
		{
			std::vector<char> init = {'a'};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = Node<char>::Reverse(std::move(pTheList));

			Assert::IsNotNull(pTheList.get());
			Assert::AreEqual('a', pTheList->GetData());
			Assert::IsNull(pTheList->GetNext());
		}

		TEST_METHOD(Reverse_TwoElements_ReturnsReversedList)
		{
			std::vector<char> init = {'a', 'b'};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = Node<char>::Reverse(std::move(pTheList));

			Assert::IsNotNull(pTheList.get());
			Assert::AreEqual('b', pTheList->GetData());
			Assert::AreEqual('a', pTheList->GetNext()->GetData());
			Assert::IsNull(pTheList->GetNext()->GetNext());
		}

		TEST_METHOD(Reverse_ThreeElements_ReturnsReversedList)
		{
			std::vector<char> init = {'a', 'b', 'c'};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = Node<char>::Reverse(std::move(pTheList));

			Assert::IsNotNull(pTheList.get());
			Assert::AreEqual('c', pTheList->GetData());
			Assert::AreEqual('b', pTheList->GetNext()->GetData());
			Assert::AreEqual('a', pTheList->GetNext()->GetNext()->GetData());
			Assert::IsNull(pTheList->GetNext()->GetNext()->GetNext());
		}

		TEST_METHOD(Reverse_FourElements_ReturnsReversedList)
		{
			std::vector<char> init = {'a', 'b', 'c', 'd'};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = Node<char>::Reverse(std::move(pTheList));

			Assert::IsNotNull(pTheList.get());
			Assert::AreEqual('d', pTheList->GetData());
			Assert::AreEqual('c', pTheList->GetNext()->GetData());
			Assert::AreEqual('b', pTheList->GetNext()->GetNext()->GetData());
			Assert::AreEqual('a', pTheList->GetNext()->GetNext()->GetNext()->GetData());
			Assert::IsNull(pTheList->GetNext()->GetNext()->GetNext()->GetNext());
		}
	};
}