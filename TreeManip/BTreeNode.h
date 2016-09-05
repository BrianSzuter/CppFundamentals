#pragma once

#include <memory>
#include <functional>
#include "TreeManipExp.h"

// Ignored - Clients must/will use identical compiler
// See https://support.microsoft.com/en-us/kb/168958
#pragma warning(push)
#pragma warning(disable: 4251)

namespace TreeManip
{

	class TREE_MANIP_DLLEXPORT BTreeNode
	{
	public:
		BTreeNode(int data, std::unique_ptr<BTreeNode> left, std::unique_ptr<BTreeNode> right);
		BTreeNode(int data);

		void SetLeft(std::unique_ptr<BTreeNode> left);

		void SetRight(std::unique_ptr<BTreeNode> right);

		BTreeNode* GetLeft();

		BTreeNode* GetRight();

		BTreeNode* GetParent();

		int GetData();

		void SetData(int value);

		// DFS Visitation
		static void VisitPreOrder(BTreeNode* root, std::function<void(int)> f);
		static void VisitInOrder(BTreeNode* root, std::function<void(int)> f);
		static void VisitPostOrder(BTreeNode* root, std::function<void(int)> f);

		// BFS Visitation
		static void VisitLevelOrder(BTreeNode* root, std::function<void(int)> f);

		static void VisitEdgesOnly(BTreeNode* root, std::function<void(int)> f);

		static int GetHeight(BTreeNode* root);

		// Pre-Condition: node is in a valid Binary Search Tree.
		// the returned BTreeNode node is the next node in "InOrder" visitation.
		static BTreeNode* GetInOrderSuccessor(BTreeNode* node);

		// Insert the specified value into the tree.
		// Pre-Condition: root is a valid Binary Search Tree.
		// Post-Condition: the returned BTreeNode remains a Binary Search Tree
		// and contains a new node for "value".
		// Returns the (potentially) new root of the Binary Search Tree.
		// No attempt is made to keep the tree balanced.
		// No attempt is made to prevent the insertion of duplicates.
		static std::unique_ptr<BTreeNode> InsertBST(std::unique_ptr<BTreeNode> root, int value);

		// Returns whether or not the specified tree structure is a valid Binary Search Tree.
		// To be a valid BST: for all nodes, every node to the left must be strictly less than the 
		// current node and every node to the right must be strictly greater than the current node.
		// No duplicate values are allowed.
		static bool IsValidBST(BTreeNode* root);

		// Returns the Lowest Common Ancestor of value1 and value2.
		// Pre-Condition: root is a valid Binary Search Tree.
		// Pre-Condition: Both value1 and value2 exist as nodes in the tree.
		static BTreeNode* GetLowestCommonAncestor(BTreeNode* root, int value1, int value2);

	private:
		void SetParent(BTreeNode* parent);

		int m_data;
		std::unique_ptr<BTreeNode> m_pLeft = nullptr;
		std::unique_ptr<BTreeNode> m_pRight = nullptr;
		BTreeNode* m_pParent = nullptr;
	};
}
#pragma warning(pop)