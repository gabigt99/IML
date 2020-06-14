#pragma once
#include "Tag.h"

class SRT_ORD : public Tag
{
public:
	SRT_ORD(const bool isCloseTag) : Tag (isCloseTag) {}
	virtual const int getType()
	{
		return 8;
	}
	virtual vector<double> calculate(vector<double> values) = 0;
};