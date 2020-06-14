#include "pch.h"
#include "Tree.h"


Tree::Tree(Tree & t)
{
	copy(t);
}

Tree & Tree::operator=(Tree & t)
{
	if (this != &t)
	{
		deleteAll(root);
		copy(t);
	}
	return *this;
}

Tree::Tree(double x)
{
	root = new TNode(x);
}

Tree::~Tree()
{
	deleteAll(root);
}

void Tree::copy(Tree& t)
{
	if (t.root == nullptr)
	{
		return;
	}
	else
	{
		root = new TNode(t.root->data);
		copyHelper(root, t.root);
	}
}

void Tree::copyHelper(TNode*& root, TNode*& node)
{
	if (node->next.size() == 0)
	{
		return;
	}
	for (size_t i = 0; i < node->next.size(); ++i)
	{
		TNode* nextN = new TNode(node->next[i]->data);
		root->next.push_back(nextN);
		copyHelper(root->next[i], node->next[i]);
	}
}

void Tree::deleteAll(TNode*& root)
{
	if (root == nullptr)
	{
		//delete root;
		return;
	}
	while (root->next.size() != 0)
	{
		deleteAll(root->next[root->next.size() - 1]);
		root->next.pop_back();
	}
	delete root;
}


