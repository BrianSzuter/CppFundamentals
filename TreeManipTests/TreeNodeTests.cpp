#include "stdafx.h"

#include <memory>
#include <string>
#include <functional>
#include "CppUnitTest.h"
#include "TreeNode.h"

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
	TEST_CLASS(TreeNodeTests)
	{
	public:
		
		unique_ptr<TreeNode> GenerateTreeWithTwoNodeLeftOnly()
		{
			auto B = make_unique<TreeNode>(1);

			return make_unique<TreeNode>(2, move(B), nullptr);
		}

		unique_ptr<TreeNode> GenerateTreeWithTwoNodeRight()
		{
			auto C = make_unique<TreeNode>(3);

			return make_unique<TreeNode>(2, nullptr, move(C));
		}

		unique_ptr<TreeNode> GenerateTreeWithThreeNode()
		{
			auto B = make_unique<TreeNode>(1);
			auto C = make_unique<TreeNode>(3);

			return make_unique<TreeNode>(2, move(B), move(C));
		}

		unique_ptr<TreeNode> GenerateTreeWithSevenNode()
		{
			auto Bl = make_unique<TreeNode>(1);
			auto Br = make_unique<TreeNode>(3);

			auto B = make_unique<TreeNode>(2, move(Bl), move(Br));

			auto Cl = make_unique<TreeNode>(5);
			auto Cr = make_unique<TreeNode>(7);
			auto C = make_unique<TreeNode>(6, move(Cl), move(Cr));

			return make_unique<TreeNode>(4, move(B), move(C));
		}

		TEST_METHOD(VisitPreOrder_3Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			TreeNode::VisitPreOrder(A.get(), f);

			// Assert
			Assert::AreEqual("2 1 3 "s, result);
		}

		TEST_METHOD(VisitPreOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			TreeNode::VisitPreOrder(A.get(), f);

			// Assert
			Assert::AreEqual("4 2 1 3 6 5 7 "s, result);
		}

		TEST_METHOD(VisitInOrder_3Nodes_NodesVisited)
		{			
			// Arrange
			auto A = GenerateTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			TreeNode::VisitInOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 2 3 "s, result);
		}

		TEST_METHOD(VisitInOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			TreeNode::VisitInOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 2 3 4 5 6 7 "s, result);
		}

		TEST_METHOD(VisitPostOrder_3Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateTreeWithThreeNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			TreeNode::VisitPostOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 3 2 "s, result);
		}

		TEST_METHOD(VisitPostOrder_7Nodes_NodesVisited)
		{
			// Arrange
			auto A = GenerateTreeWithSevenNode();

			string result;
			auto f = [&result](int i) {result += to_string(i) + " "s; };

			// Act
			TreeNode::VisitPostOrder(A.get(), f);

			// Assert
			Assert::AreEqual("1 3 2 5 7 6 4 "s, result);
		}

		TEST_METHOD(GetHeight_0Node)
		{
			// Act
			auto result = TreeNode::GetHeight(nullptr);

			// Assert
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(GetHeight_1Node)
		{
			// Arrange
			auto A = make_unique<TreeNode>(2);

			// Act
			auto result = TreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(GetHeight_2NodesLeftOnly)
		{
			// Arrange
			auto A = GenerateTreeWithTwoNodeLeftOnly();

			// Act
			auto result = TreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(GetHeight_2Nodes_RightOnly)
		{
			// Arrange
			auto A = GenerateTreeWithTwoNodeRight();

			// Act
			auto result = TreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(GetHeight_3Nodes)
		{
			// Arrange
			auto A = GenerateTreeWithThreeNode();

			// Act
			auto result = TreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(GetHeight_7Nodes)
		{
			// Arrange
			auto A = GenerateTreeWithSevenNode();

			// Act
			auto result = TreeNode::GetHeight(A.get());

			// Assert
			Assert::AreEqual(3, result);
		}

	};
}