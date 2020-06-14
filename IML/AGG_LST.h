#pragma once
#include "pch.h"
#include "Tag.h"

class AGG_LST : public Tag
{
public:
	AGG_LST(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType()
	{
		return 6;
	}
	vector<double> calculate(vector<double> values)
	{
		if (values.size() != 0)
		{
			vector<double> last;
			last.push_back(values[values.size() - 1]);
			return last;
		}
		return values;
	}
};