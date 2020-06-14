#include "pch.h"
#include "NUM.h"

NUM::NUM(double number, const bool isCloseTag) : Tag(isCloseTag)
{
	this->number = number;
}

const int NUM::getType()
{
	return 11;
}

vector<double> NUM::calculate(vector<double> values)
{
	values.push_back(number);
	return values;
}
