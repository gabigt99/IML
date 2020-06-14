#pragma once
#include "pch.h"
#include <vector>

struct TNode
{
	TNode(double data) : data(data) {}
	double data;
	std::vector<TNode*> next;
};

class Tree
{
public:
	Tree() : root(nullptr) {}
	Tree(Tree& t);
	Tree& operator=(Tree&);
	void addNode(TNode* n)
	{
		root->next.push_back(n);
	}
	Tree(double x);
	~Tree();
private:
	TNode* root;
	void copy(Tree&);
	void copyHelper(TNode*& root, TNode*& node);
	void deleteAll(TNode*& root);
};