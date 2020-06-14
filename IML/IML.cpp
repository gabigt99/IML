#pragma once
#include "pch.h"
#include <iostream>
#include <sstream>
#include "IML.h"
#include "MAP_INC.h"
#include "MAP_MLT.h"
#include "AGG_SUM.h"
#include "AGG_PRO.h"
#include "AGG_AVG.h"
#include "AGG_FST.h"
#include "AGG_LST.h"
#include "SRT_REV.h"
#include "SRT_ORD_ASC.h"
#include "SRT_ORD_DSC.h"
#include "SRT_SLC.h"
#include "SRT_DST.h"
#include "NUM.h"

IML::IML(istream & in, ostream & out)
{
	this->in = &in;
	this->out = &out;
	root = nullptr;
}

Tag* IML::readTag()
{
	killSpaces();
	string tag;
	while (in->peek() != '>' && in->peek() != EOF)
	{
		tag.push_back(in->get());
		killSpaces();
	}
	tag.push_back(in->get());
	if (tag[1] == '/')
	{
		if (isCloseTag(tag))
		{
			return createTag((tag.substr(0, 1) + tag.substr(2, 7)), 1);
		}
		throw ("Unvalid close tag is: " + tag);
	}
	else
	{
		if (isOpenTag(tag))
		{
			return createTag(tag, 0);
		}
		throw ("Unvalid open tag is: " + tag);
	}
}

Tag * IML::createTag(string tag, const bool isCloseTag)
{
	string tagName = tag.substr(0, 8);
	if (tagName == "<MAP-INC")
	{
		if (isCloseTag)
		{
			return new MAP_INC(isCloseTag);
		}
		return new MAP_INC(isCloseTag, fromStringToDoubleNumber(tag));
	}
	if (tagName == "<MAP-MLT")
	{
		if (isCloseTag)
		{
			return new MAP_MLT(isCloseTag);
		}
		return new MAP_MLT(isCloseTag, fromStringToDoubleNumber(tag));
	}
	if (tagName == "<AGG-SUM")
	{
		return new AGG_SUM(isCloseTag);
	}
	if (tagName == "<AGG-PRO")
	{
		return new AGG_PRO(isCloseTag);
	}
	if (tagName == "<AGG-AVG")
	{
		return new AGG_AVG(isCloseTag);
	}
	if (tagName == "<AGG-FST")
	{
		return new AGG_FST(isCloseTag);
	}
	if (tagName == "<AGG-LST")
	{
		return new AGG_LST(isCloseTag);
	}
	if (tagName == "<SRT-REV")
	{
		return new SRT_REV(isCloseTag);
	}
	if (tagName == "<SRT-ORD")
	{
		if (isCloseTag)
		{
			return new SRT_ORD_ASC(isCloseTag);
		}
		if (tag[9] == 'A')
		{
			return new SRT_ORD_ASC(isCloseTag);
		}
		return new SRT_ORD_DSC(isCloseTag);
	}
	if (tagName == "<SRT-SLC")
	{
		if (isCloseTag)
		{
			return new SRT_SLC(isCloseTag);
		}
		return new SRT_SLC(isCloseTag, fromStringToNaturalNumber(tag));
	}
	return new SRT_DST(isCloseTag);
}

void IML::buildTree()
{
	root = readTag();
	if (root->getIsCloseTag() == 1)
	{
		throw (string)"An opening tag is expected, but it is a closing tag.";
	}
	buildTreeHelper(root);
	killSpaces();
	if (in->peek() != EOF)
	{
		throw (string)"After the last closing tag there are more characters.";
	}
}

vector<double> IML::calculateTree()
{
	return calculateTreeHelper(root);
}

bool IML::isOpenTag(const string tag)
{
	if (tag != "<AGG-SUM>"
		&& tag != "<AGG-PRO>"
		&& tag != "<AGG-AVG>"
		&& tag != "<AGG-FST>"
		&& tag != "<AGG-LST>"
		&& tag != "<SRT-REV>"
		&& tag != "<SRT-ORD\"ASC\">"
		&& tag != "<SRT-ORD\"DSC\">"
		&& tag != "<SRT-DST>" && !isSpecialTag(tag))
	{
		return false;
	}
	return true;
}

bool IML::isCloseTag(string tag)
{
	if (tag != "</MAP-INC>"
		&& tag != "</MAP-MLT>"
		&& tag != "</AGG-SUM>"
		&& tag != "</AGG-PRO>"
		&& tag != "</AGG-AVG>"
		&& tag != "</AGG-FST>"
		&& tag != "</AGG-LST>"
		&& tag != "</SRT-REV>"
		&& tag != "</SRT-ORD>"
		&& tag != "</SRT-SLC>"
		&& tag != "</SRT-DST>")
	{
		return false;
	}
	return true;
}

bool IML::isSpecialTag(string tag)
{
	string tagName = tag.substr(0, 9);
	string number = tag.substr(9, tag.size() - 9 - 2);

	string endOfTag = tag.substr(tag.size() - 2);
	if (tagName == "<SRT-SLC\"")
	{
		return isNaturalNumber(number) && endOfTag == "\">";
	}
	if (tagName == "<MAP-INC\"" || tagName == "<MAP-MLT\"")
	{
		return isNumber(number) && endOfTag == "\">";
	}
	return false;
}

bool IML::isNaturalNumber(string number)
{
	return (number[0] != '-' && number.find('.') >= number.length() && isNumber(number));;
}

bool IML::isNumber(string number)
{
	if (number.find('.') < number.size())
	{
		string first = number.substr(0, number.find('.'));
		string second = number.substr(number.find('.') + 1);
		if (first[0] == '-' || first[0] >= '0' && first[0] <= '9')
		{
			return isDigits(first.substr(1)) && isDigits(second);
		}
	}
	else
	{
		if (number[0] == '-' || number[0] >= '0' && number[0] <= '9')
		{
			return isDigits(number.substr(1));
		}
	}
	return false;
}

bool IML::isDigits(string digits) const
{
	for (char digit : digits)
	{
		if (digit < '0' || digit > '9')
		{
			return false;
		}
	}
	return true;
}

double IML::fromStringToDoubleNumber(string tag)
{
	double number;
	stringstream (tag.substr(9, tag.size() - 9 - 2)) >> number;
	return number;
}

size_t IML::fromStringToNaturalNumber(string tag)
{
	size_t number;
	stringstream (tag.substr(9, tag.size() - 9 - 2)) >> number;
	return number;
}

double IML::takeNumber()
{
	string number;
	while (in->peek() != '<' && in->peek() != ' ' && in->peek() != EOF)
	{
		number.push_back(in->get());
	}
	if (!isNumber(number))
	{
		throw "Unvalid number is " + number;
	}
	double value;
	stringstream(number) >> value;
	return value;
}

void IML::killSpaces()
{
	while (in->peek() == ' ' || in->peek() == '\n')
	{
		in->get();
	}
}

void IML::print(vector<double> values) const
{
	for (double number : values)
	{
		*out << number << " ";
	}
}

IML::~IML()
{
	delete root;
}

void IML::buildTreeHelper(Tag*& crrTag)
{
	if (in->peek() == EOF)
	{
		return;
	}
	killSpaces();
	while (in->peek() != '<' && in->peek() != EOF)
	{
		crrTag->addNextTag(new NUM(takeNumber()));
		killSpaces();
	}
	if (in->peek() == EOF)
	{
		throw (string)"There is no closing tag";
	}
	Tag * nextTag = readTag();
	if (nextTag->getIsCloseTag() && nextTag->getType() == crrTag->getType())
	{//край на валидния таг
		return;
	}
	if (nextTag->getIsCloseTag() == 1)
	{
		throw (string)"A foreign closing tag.";
	}
	crrTag->addNextTag(nextTag);
	buildTreeHelper(nextTag);
	buildTreeHelper(crrTag);
}

vector<double> IML::calculateTreeHelper(Tag *& crrTag)
{
	vector<double> values;
	for (size_t i = 0; i < crrTag->getNextTagsSize(); i++)
	{
		vector<double> calculated = calculateTreeHelper((*crrTag)[i]);
		values.insert(values.end(), calculated.begin(), calculated.end());
	}
	return crrTag->calculate(values);
}