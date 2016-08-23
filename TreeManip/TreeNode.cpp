#pragma once

#include "stdafx.h"
#include "TreeNode.h"

using std::move;
using std::unique_ptr;

namespace TreeManip
{
	TreeNode::TreeNode(int data, unique_ptr<TreeNode> left, unique_ptr<TreeNode> right)
		: m_data(data)
		, m_pLeft(move(left))
		, m_pRight(move(right))
	{

	}

	TreeNode::TreeNode(int data)
		: m_data(data)
	{
	}

	void TreeNode::SetLeft(unique_ptr<TreeNode> left)
	{
		m_pLeft = move(left);
	}

	void TreeNode::SetRight(unique_ptr<TreeNode> right)
	{
		m_pRight = move(right);
	}

	TreeNode* TreeNode::GetLeft()
	{
		return m_pLeft.get();
	}

	TreeNode* TreeNode::GetRight()
	{
		return m_pRight.get();
	}

	int TreeNode::GetData()
	{
		return m_data;
	}

	void TreeNode::VisitPreOrder(TreeNode* root, std::function<void(int)> f)
	{

		if(root == nullptr)
			return;

		f(root->GetData());

		VisitPreOrder(root->GetLeft(), f);

		VisitPreOrder(root->GetRight(), f);

		return;
	}

	void TreeNode::VisitInOrder(TreeNode* root, std::function<void(int)> f)
	{

		if(root == nullptr)
			return;

		VisitInOrder(root->GetLeft(), f);

		f(root->GetData());

		VisitInOrder(root->GetRight(), f);

		return;
	}

	void TreeNode::VisitPostOrder(TreeNode* root, std::function<void(int)> f)
	{

		if(root == nullptr)
			return;

		VisitPostOrder(root->GetLeft(), f);

		VisitPostOrder(root->GetRight(), f);

		f(root->GetData());

		return;
	}

	int TreeNode::GetHeight(TreeNode* root)
	{
		if(root == nullptr)
			return 0;

		int left = GetHeight(root->GetLeft());
		int right = GetHeight(root->GetRight());

		int maxheight = std::max(left, right);

		return maxheight + 1;
	}
}