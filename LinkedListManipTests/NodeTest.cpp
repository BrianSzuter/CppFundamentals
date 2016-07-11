#include "stdafx.h"
#include "CppUnitTest.h"
#include "Node.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chapter2Tests
{		
	TEST_CLASS(NodeTests)
	{
	public:		

		TEST_METHOD(CreateList_Empty_Succeeds)
		{
			std::vector<int> data{};
			auto myList = Node<int>::CreateList(data);

			Assert::IsNull(myList.get());
		}

		TEST_METHOD(CreateList_WithOneInt_Succeeds)
		{
			std::vector<int> data{3};
			auto myList = Node<int>::CreateList(data);

			Assert::AreEqual(3, myList->GetData());
			Assert::IsNull(myList->GetNext());
		}

		TEST_METHOD(CreateList_WithOneChar_Succeeds)
		{
			std::vector<char> data{'a'};
			auto myList = Node<char>::CreateList(data);
			Assert::AreEqual('a', myList->GetData());
		}

		TEST_METHOD(CreateList_WithThreeInts_Succeeds)
		{
			std::vector<int> data{3, 5, 7};
			auto myList = Node<int>::CreateList(data);

			Assert::IsNotNull(myList.get());
			Assert::AreEqual(3, myList->GetData());
			Assert::AreEqual(5, myList->GetNext()->GetData());
			Assert::AreEqual(7, myList->GetNext()->GetNext()->GetData());
			Assert::IsNull(myList->GetNext()->GetNext()->GetNext());
		}		
		

		TEST_METHOD(AppendToTailInt_BuildsList_CanGetData)
		{
			std::vector<int> data{3};
			auto myList = Node<int>::CreateList(data);

			myList->AppendToTail(5);
			myList->AppendToTail(7);

			Assert::AreEqual(3, myList->GetData());
			Assert::AreEqual(5, myList->GetNext()->GetData());
			Assert::AreEqual(7, myList->GetNext()->GetNext()->GetData());
		}

		TEST_METHOD(DeleteNode_CanDeleteEmptyList_ReturnsNullList)
		{
			std::vector<int> data{};
			auto myList = Node<int>::CreateList(data);

			myList = Node<int>::DeleteNode(std::move(myList), 2);

			Assert::IsNull(myList.get());
		}

		TEST_METHOD(DeleteNode_CanDeleteSingleElementList_ReturnsNullList)
		{
			std::vector<int> data{3};
			auto myList = Node<int>::CreateList(data);

			myList = Node<int>::DeleteNode(std::move(myList), 3);

			Assert::IsNull(myList.get());
		}

		TEST_METHOD(DeleteNode_CanDeleteItemNotInList_ListStillValid)
		{
			std::unique_ptr<Node<int>> myList = nullptr;

			{
				std::vector<int> data{3, 5, 7};
				auto OriginalList = Node<int>::CreateList(data);

				myList = Node<int>::DeleteNode(std::move(OriginalList), 2);
			} // OriginalList destroyed

			Assert::IsNotNull(myList.get());
			Assert::AreEqual(3, myList->GetData());
			Assert::AreEqual(5, myList->GetNext()->GetData());
			Assert::AreEqual(7, myList->GetNext()->GetNext()->GetData());
			Assert::IsNull(myList->GetNext()->GetNext()->GetNext());
		}

		TEST_METHOD(DeleteNode_CanDeleteHead_ListStillValid)
		{
			std::unique_ptr<Node<int>> myList = nullptr;

			{
				std::vector<int> data{3, 5, 7};
				auto OriginalList = Node<int>::CreateList(data);

				myList = Node<int>::DeleteNode(std::move(OriginalList), 3);
			} // OriginalList destroyed

			Assert::IsNotNull(myList.get());
			Assert::AreEqual(5, myList->GetData());
			Assert::AreEqual(7, myList->GetNext()->GetData());
			Assert::IsNull(myList->GetNext()->GetNext());
		}

		TEST_METHOD(DeleteNode_CanDeleteMiddle_ListStillValid)
		{
			std::unique_ptr<Node<int>> myList = nullptr;

			{
				std::vector<int> data{3, 5, 7};
				auto OriginalList = Node<int>::CreateList(data);

				myList = Node<int>::DeleteNode(std::move(OriginalList), 5);
			} // OriginalList destroyed

			Assert::IsNotNull(myList.get());
			Assert::AreEqual(3, myList->GetData());
			Assert::AreEqual(7, myList->GetNext()->GetData());
		}

		TEST_METHOD(DeleteNode_CanDeleteEnd_ListStillValid)
		{
			std::unique_ptr<Node<int>> myList = nullptr;

			{
				std::vector<int> data{3, 5, 7};
				auto OriginalList = Node<int>::CreateList(data);

				myList = Node<int>::DeleteNode(std::move(OriginalList), 7);
			} // OriginalList destroyed

			Assert::IsNotNull(myList.get());
			Assert::AreEqual(3, myList->GetData());
			Assert::AreEqual(5, myList->GetNext()->GetData());
		}

		TEST_METHOD(DeleteNode_CanDelete_AssignBackToOriginal)
		{
			std::vector<int> data{3, 5, 7};
			auto myList = Node<int>::CreateList(data);

			myList = Node<int>::DeleteNode(std::move(myList), 7);

			Assert::IsNotNull(myList.get());
			Assert::AreEqual(3, myList->GetData());
			Assert::AreEqual(5, myList->GetNext()->GetData());
		}

	};
}