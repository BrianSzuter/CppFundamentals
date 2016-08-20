#include "stdafx.h"
#include "CppUnitTest.h"
#include "Node.h"
#include "RemoveDuplicates.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListManipTests
{		
	TEST_CLASS(RemoveDuplicatesTests)
	{
	public:
		TEST_METHOD(RemoveDuplicates_SingleDuplicate_RemovesTheDuplicate)
		{
			std::vector<char> init = {'F', 'A', 'F'};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = RemoveDuplicates(std::move(pTheList));

			Assert::IsNotNull(pTheList.get());
			Assert::AreEqual('A', pTheList->GetData());
			Assert::AreEqual('F', pTheList->GetNext()->GetData());
		}

		TEST_METHOD(RemoveDuplicates_MultipleDuplicate_RemovesTheDuplicates)
		{
			std::vector<char> init = {'F', 'A', 'F', 'A', 'A', 'F'};
			auto pTheList = Node<char>::CreateList(init);

			pTheList = RemoveDuplicates(std::move(pTheList));

			Assert::IsNotNull(pTheList.get());
			Assert::AreEqual('A', pTheList->GetData());
			Assert::AreEqual('F', pTheList->GetNext()->GetData());
		}

		TEST_METHOD(RemoveDuplicates_EmptyList_ReturnsEmptyList)
		{
			std::vector<char> init;
			auto pTheList = Node<char>::CreateList(init);

			pTheList = RemoveDuplicates(std::move(pTheList));

			Assert::IsNull(pTheList.get());
		}
	};
}