#pragma once
#include "pch.h"
#include "Tag.h"

class AGG_FST : public Tag
{
public:
	AGG_FST(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType()
	{
		return 5;
	}
	vector<double> calculate(vector<double> values)
	{
		if (values.size() != 0)
		{
			vector<double> first;
			first.push_back(values[0]);
			return first;
		}
		return values;
	}
};