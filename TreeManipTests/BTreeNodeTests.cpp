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
using std::to_string;


namespace TreeManipTests
{		
	TEST_CLASS(BTreeNodeTests)
	{
	public:
		
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

	};
}