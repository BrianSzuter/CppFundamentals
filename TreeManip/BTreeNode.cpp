#pragma once

#include "stdafx.h"
#include "BTreeNode.h"
#include <queue>

using std::move;
using std::unique_ptr;
using std::make_unique;
using std::queue;

namespace
{
	using namespace TreeManip;

	void visit_left_side(BTreeNode * root, std::function<void(int)> f)
	{
		if(root == nullptr)
			return;

		visit_left_side(root->GetLeft(), f);
		f(root->GetData());
	}

	void visit_right_side(BTreeNode * root, std::function<void(int)> f)
	{
		if(root == nullptr)
			return;

		f(root->GetData());
		visit_right_side(root->GetRight(), f);
	}

	void InsertBST_Helper(BTreeNode* root, int value)
	{
		// less than or equal to root & left is null, insert as left child
		if((value <= root->GetData()) && (root->GetLeft() == nullptr))
		{
			auto n = make_unique<BTreeNode>(value, nullptr, nullptr);
			root->SetLeft(move(n));
		}
		// greater than root & right is null, insert as right child
		else if((value > root->GetData()) && (root->GetRight() == nullptr))
		{
			auto n = make_unique<BTreeNode>(value, nullptr, nullptr);
			root->SetRight(move(n));
		}
		else if(value <= root->GetData())
		{
			InsertBST_Helper(root->GetLeft(), value);
		}
		else
		{// value > root->data
			InsertBST_Helper(root->GetRight(), value);
		}
	}
}

namespace TreeManip
{
	BTreeNode::BTreeNode(int data, unique_ptr<BTreeNode> left, unique_ptr<BTreeNode> right)
		: m_data(data)
		, m_pLeft(move(left))
		, m_pRight(move(right))
	{

	}

	BTreeNode::BTreeNode(int data)
		: m_data(data)
	{
	}

	void BTreeNode::SetLeft(unique_ptr<BTreeNode> left)
	{
		m_pLeft = move(left);
	}

	void BTreeNode::SetRight(unique_ptr<BTreeNode> right)
	{
		m_pRight = move(right);
	}

	BTreeNode* BTreeNode::GetLeft()
	{
		return m_pLeft.get();
	}

	BTreeNode* BTreeNode::GetRight()
	{
		return m_pRight.get();
	}

	int BTreeNode::GetData()
	{
		return m_data;
	}

	void BTreeNode::VisitPreOrder(BTreeNode* root, std::function<void(int)> f)
	{

		if(root == nullptr)
			return;

		f(root->GetData());

		VisitPreOrder(root->GetLeft(), f);

		VisitPreOrder(root->GetRight(), f);

		return;
	}

	void BTreeNode::VisitInOrder(BTreeNode* root, std::function<void(int)> f)
	{

		if(root == nullptr)
			return;

		VisitInOrder(root->GetLeft(), f);

		f(root->GetData());

		VisitInOrder(root->GetRight(), f);

		return;
	}

	void BTreeNode::VisitPostOrder(BTreeNode* root, std::function<void(int)> f)
	{

		if(root == nullptr)
			return;

		VisitPostOrder(root->GetLeft(), f);

		VisitPostOrder(root->GetRight(), f);

		f(root->GetData());

		return;
	}

	void BTreeNode::VisitLevelOrder(BTreeNode * root, std::function<void(int)> f)
	{
		if(root == nullptr)
			return;

		queue<BTreeNode*> q;
		q.push(root);

		while(!q.empty())
		{
			auto n = q.front();
			q.pop();

			f(n->GetData());

			auto left = n->GetLeft();
			auto right = n->GetRight();
			if(left != nullptr)
				q.push(left);
			if(right != nullptr)
				q.push(right);
		}

		return;
	}

	void BTreeNode::VisitEdgesOnly(BTreeNode * root, std::function<void(int)> f)
	{
		if(root == nullptr)
			return;

		visit_left_side(root->GetLeft(), f);
		f(root->GetData());
		visit_right_side(root->GetRight(), f);
	}

	int BTreeNode::GetHeight(BTreeNode* root)
	{
		if(root == nullptr)
			return 0;

		int left = GetHeight(root->GetLeft());
		int right = GetHeight(root->GetRight());

		int maxheight = std::max(left, right);

		return maxheight + 1;
	}

	std::unique_ptr<BTreeNode> BTreeNode::InsertBST(std::unique_ptr<BTreeNode> root, int value)
	{
		if(root == nullptr)
		{
			return make_unique<BTreeNode>(value, nullptr, nullptr);
		}

		InsertBST_Helper(root.get(), value);

		return root;
	}
}