#pragma once
#include "pch.h"
#include "Tag.h"

class AGG_SUM : public Tag
{
public:
	AGG_SUM(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType()
	{
		return 2;
	}
	vector<double> calculate(vector<double> values)
	{
		if (values.size() != 0)
		{
			vector<double> sum;
			sum.push_back(0);
			for (double number : values)
			{
				sum[0] += number;
			}
			return sum;
		}
		return values;
	}
};