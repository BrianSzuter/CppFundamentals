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

	class TREE_MANIP_DLLEXPORT TreeNode
	{
	public:
		TreeNode(int data, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right);
		TreeNode(int data);

		void SetLeft(std::unique_ptr<TreeNode> left);

		void SetRight(std::unique_ptr<TreeNode> right);

		TreeNode* GetLeft();

		TreeNode* GetRight();

		int GetData();

		static void VisitPreOrder(TreeNode* root, std::function<void(int)> f);
		static void VisitInOrder(TreeNode* root, std::function<void(int)> f);
		static void VisitPostOrder(TreeNode* root, std::function<void(int)> f);

		static int GetHeight(TreeNode* root);
	private:
		int m_data;
		std::unique_ptr<TreeNode> m_pLeft = nullptr;
		std::unique_ptr<TreeNode> m_pRight = nullptr;
	};
}
#pragma warning(pop)