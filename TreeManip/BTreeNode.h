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

		int GetData();

		static void VisitPreOrder(BTreeNode* root, std::function<void(int)> f);
		static void VisitInOrder(BTreeNode* root, std::function<void(int)> f);
		static void VisitPostOrder(BTreeNode* root, std::function<void(int)> f);

		static void VisitLevelOrder(BTreeNode* root, std::function<void(int)> f);

		static void VisitEdgesOnly(BTreeNode* root, std::function<void(int)> f);

		static int GetHeight(BTreeNode* root);

		// Insert the specified value into the tree.
		// Pre-Condition: root is a valid Binary Search Tree.
		// Post-Condition: the returned BTreeNode remains a Binary Search Tree
		// and contains a new node for "value".
		// Returns the (potentially) new root of the Binary Search Tree.
		// No attempt is made to keep the tree balanced.
		static std::unique_ptr<BTreeNode> InsertBST(std::unique_ptr<BTreeNode> root, int value);

	private:


		int m_data;
		std::unique_ptr<BTreeNode> m_pLeft = nullptr;
		std::unique_ptr<BTreeNode> m_pRight = nullptr;
	};
}
#pragma warning(pop)