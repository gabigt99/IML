#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Tag.h"

using namespace std;

class IML
{
public:
	IML(istream& in, ostream& out);
	Tag* readTag();
	Tag* createTag(string tagName, const bool isCloseTag);
	void buildTree();
	vector<double> calculateTree();
	bool isOpenTag(string tag);
	bool isCloseTag(string tag);
	bool isSpecialTag(string tag);
	bool isNaturalNumber(string number);
	bool isNumber(string number);
	bool isDigits(string digits) const;
	double fromStringToDoubleNumber(const stringstream tag);
	double fromStringToDoubleNumber(string tag);
	size_t fromStringToNaturalNumber(string tag);
	double takeNumber();
	void killSpaces();
	void print(vector<double> values) const;
	~IML();
private:
	istream *in;
	ostream *out;
	//Tree<Token> t;
	Tag* root;
	void buildTreeHelper(Tag*& crrTag);
	vector<double> calculateTreeHelper(Tag*& crrTag);
};