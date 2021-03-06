#include "stdafx.h"

#include <memory>
#include <string>
#include <functional>
#include "CppUnitTest.h"
#include "BTreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;
using namespace TreeManip;

using std::make_unique;
using std::unique_ptr;
using std::move;
using std::string;
using std::wstring;
using std::to_string;
using std::to_wstring;


namespace TreeManipTests
{		
	TEST_CLASS(BTreeNodeTests)
	{
	private:
		
		unique_ptr<BTreeNode> GenerateBTreeWithTwoNodeLeftOnly()
		{
			auto B = make_unique<BTreeNode>(1);

			return make_unique<BTreeNode>(2, move(B), nullptr);
		}

		unique_ptr<BTreeNode> GenerateBTreeWithTwoNodeRight()
		{
			auto C = make_unique<BTreeNode>(3);

			return make_unique<BTreeNode>(2, nullptr, move(C));
		}
	
		unique_ptr<BTreeNode> GenerateBTreeWithThreeNode()
		{
			auto B = make_unique<BTreeNode>(1);
			auto C = make_unique<BTreeNode>(3);

			return make_unique<BTreeNode>(2, move(B), move(C));
		}

		unique_ptr<BTreeNode> GenerateBTreeWithSevenNode()
		{
			auto Bl = make_unique<BTreeNode>(1);
			auto Br = make_unique<BTreeNode>(3);

			auto B = make_unique<BTreeNode>(2, move(Bl), move(Br));

			auto Cl = make_unique<BTreeNode>(5);
			auto Cr = make_unique<BTreeNode>(7);
			auto C = make_unique<BTreeNode>(6, move(Cl), move(Cr));

			return make_unique<BTreeNode>(4, move(B), move(C));
		}

	public:
		TEST_METHOD(VisitPreOrder_3Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitPreOrder(A.get(), f);

			// Assert
			Assert::AreEqual("2 1 3 "s, result);
		}

		TEST_METHOD(VisitPreOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitPreOrder(A.get(), f);

			// Assert
			Assert::AreEqual("4 2 1 3 6 5 7 "s, result);
		}

		TEST_METHOD(VisitInOrder_3Nodes_NodesVisited)
		{			
			// Arrange
			auto A = GenerateBTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitInOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 2 3 "s, result);
		}

		TEST_METHOD(VisitInOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitInOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 2 3 4 5 6 7 "s, result);
		}

		TEST_METHOD(VisitPostOrder_3Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitPostOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 3 2 "s, result);
		}

		TEST_METHOD(VisitPostOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitPostOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 3 2 5 7 6 4 "s, result);
		}

		TEST_METHOD(GetHeight_0Node)
		{
			// Act
			auto result = BTreeNode::GetHeight(nullptr);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(GetHeight_1Node)
		{
			// Arrange
			auto A = make_unique<BTreeNode>(2);

			// Act
			auto result = BTreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(GetHeight_2NodesLeftOnly)
		{
			// Arrange
			auto A = GenerateBTreeWithTwoNodeLeftOnly();

			// Act
			auto result = BTreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(GetHeight_2Nodes_RightOnly)
		{
			// Arrange
			auto A = GenerateBTreeWithTwoNodeRight();

			// Act
			auto result = BTreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(GetHeight_3Nodes)
		{
			// Arrange
			auto A = GenerateBTreeWithThreeNode();

			// Act
			auto result = BTreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(GetHeight_7Nodes)
		{
			// Arrange
			auto A = GenerateBTreeWithSevenNode();

			// Act
			auto result = BTreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(3, result);
		}

		TEST_METHOD(VisitEdgesOnly_3Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitEdgesOnly(A.get(), f);

			// Assert
			Assert::AreEqual("1 2 3 "s, result);
		}

		TEST_METHOD(VisitEdgesOnly_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitEdgesOnly(A.get(), f);

			// Assert
			Assert::AreEqual("1 2 4 6 7 "s, result);
		}

		TEST_METHOD(VisitLevelOrder_3Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitLevelOrder(A.get(), f);

			// Assert
			Assert::AreEqual("2 1 3 "s, result);
		}

		TEST_METHOD(VisitLevelOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateBTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			BTreeNode::VisitLevelOrder(A.get(), f);

			// Assert
			Assert::AreEqual("4 2 6 1 3 5 7 "s, result);
		}

		TEST_METHOD(InsertBST_Build3NodeTree_FromNothing)
		{
			// Act
			auto root = BTreeNode::InsertBST(nullptr, 2);
			root = BTreeNode::InsertBST(move(root), 1);
			root = BTreeNode::InsertBST(move(root), 3);

			// Assert
			Assert::AreEqual(2, root->GetData());
			Assert::AreEqual(1, root->GetLeft()->GetData());
			Assert::AreEqual(3, root->GetRight()->GetData());
		}

		TEST_METHOD(InsertBST_Build7NodeTree_FromExistingTree)
		{
			// Arrange
			auto root = GenerateBTreeWithThreeNode();

			// Act (Order Matters)			
			root = BTreeNode::InsertBST(move(root), 5);
			root = BTreeNode::InsertBST(move(root), 4);
			root = BTreeNode::InsertBST(move(root), 6);
			root = BTreeNode::InsertBST(move(root), 0);

			// Assert
			Assert::AreEqual(2, root->GetData());
			Assert::AreEqual(1, root->GetLeft()->GetData());
			Assert::AreEqual(3, root->GetRight()->GetData());
			Assert::AreEqual(5, root->GetRight()->GetRight()->GetData());
			Assert::AreEqual(4, root->GetRight()->GetRight()->GetLeft()->GetData());
			Assert::AreEqual(6, root->GetRight()->GetRight()->GetRight()->GetData());
			Assert::AreEqual(0, root->GetLeft()->GetLeft()->GetData());
		}

		TEST_METHOD(IsValidBST_nullroot_IsValid)
		{
			auto result = BTreeNode::IsValidBST(nullptr);

			Assert::IsTrue(result);
		}

		TEST_METHOD(IsValidBST_ValidBST_IsValid)
		{
			auto root = GenerateBTreeWithSevenNode();

			auto result = BTreeNode::IsValidBST(root.get());

			Assert::IsTrue(result);
		}

		TEST_METHOD(IsValidBST_RightGrandChild_GreaterThanRoot_IsNotValid)
		{
			auto root = GenerateBTreeWithSevenNode();
			root->GetLeft()->GetRight()->SetData(5);

			auto result = BTreeNode::IsValidBST(root.get());

			Assert::IsFalse(result);
		}

		TEST_METHOD(IsValidBST_RightGrandChild_IsDuplicate_IsNotValid)
		{
			auto root = GenerateBTreeWithSevenNode();
			root->GetLeft()->GetRight()->SetData(2);

			auto result = BTreeNode::IsValidBST(root.get());

			Assert::IsFalse(result);
		}

		TEST_METHOD(IsValidBST_LeftGrandChildRightSide_LessThanRoot_IsNotValid)
		{
			auto root = GenerateBTreeWithSevenNode();
			root->GetRight()->GetLeft()->SetData(3);

			auto result = BTreeNode::IsValidBST(root.get());

			Assert::IsFalse(result);
		}

		TEST_METHOD(IsValidBST_LeftGrandChildRightSide_IsDuplicate_IsNotValid)
		{
			auto root = GenerateBTreeWithSevenNode();
			root->GetRight()->GetRight()->SetData(6);

			auto result = BTreeNode::IsValidBST(root.get());

			Assert::IsFalse(result);
		}

		TEST_METHOD(GetLowestCommonAncestor_TableDriven)
		{
			struct TestItem
			{
				unsigned int TestID;
				int value1;
				int value2;
				int expected;
			};

			TestItem TestItems[] = 
			{
				{__LINE__, 1, 3, 2 },
				{__LINE__, 1, 2, 2 },
				{__LINE__, 1, 4, 4 },
				{__LINE__, 1, 6, 4 },
				{__LINE__, 6, 1, 4 },
				{__LINE__, 3, 2, 2 },
				{__LINE__, 3, 4, 4 },
				{__LINE__, 3, 6, 4 },
				{__LINE__, 6, 3, 4 },
				{__LINE__, 2, 6, 4 },
				{__LINE__, 2, 4, 4 },
				{__LINE__, 2, 5, 4 },
				{__LINE__, 2, 7, 4 },
				{__LINE__, 5, 7, 6 },
				{__LINE__, 5, 5, 5 },
				{__LINE__, 6, 6, 6 },
				{__LINE__, 4, 4, 4 },
				{__LINE__, 7, 5, 6 },
			};

			auto root = GenerateBTreeWithSevenNode();

			for(const auto& t : TestItems)
			{
				auto resultNode = BTreeNode::GetLowestCommonAncestor(root.get(), t.value1, t.value2);

				wstring AssertMsg = L"Test Case Line: "s + to_wstring(t.TestID);
				Assert::AreEqual(t.expected, resultNode->GetData(), AssertMsg.c_str());
			}
		}

		TEST_METHOD(GetInOrderSuccessor_FullSevenTree)
		{
			auto un1 = make_unique<BTreeNode>(1);
			auto n1 = un1.get();
			auto un3 = make_unique<BTreeNode>(3);
			auto n3 = un3.get();

			auto un2 = make_unique<BTreeNode>(2, move(un1), move(un3));
			auto n2 = un2.get();

			auto un5 = make_unique<BTreeNode>(5);
			auto n5 = un5.get();
			auto un7 = make_unique<BTreeNode>(7);
			auto n7 = un7.get();
			auto un6 = make_unique<BTreeNode>(6, move(un5), move(un7));
			auto n6 = un6.get();

			auto un4 = make_unique<BTreeNode>(4, move(un2), move(un6));
			auto n4 = un4.get();

			Assert::AreEqual(2, BTreeNode::GetInOrderSuccessor(n1)->GetData());
			Assert::AreEqual(3, BTreeNode::GetInOrderSuccessor(n2)->GetData());
			Assert::AreEqual(4, BTreeNode::GetInOrderSuccessor(n3)->GetData());
			Assert::AreEqual(5, BTreeNode::GetInOrderSuccessor(n4)->GetData());
			Assert::AreEqual(6, BTreeNode::GetInOrderSuccessor(n5)->GetData());
			Assert::AreEqual(7, BTreeNode::GetInOrderSuccessor(n6)->GetData());
			Assert::IsNull(BTreeNode::GetInOrderSuccessor(n7));
		}

		TEST_METHOD(GetInOrderSuccessor_NullTree)
		{
			Assert::IsNull(BTreeNode::GetInOrderSuccessor(nullptr));
		}

		TEST_METHOD(GetInOrderSuccessor_OneElementTree)
		{
			auto un1 = make_unique<BTreeNode>(1);

			Assert::IsNull(BTreeNode::GetInOrderSuccessor(un1.get()));
		}
	};
}