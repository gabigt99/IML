#pragma once
#include "pch.h"
#include "Tag.h"

class AGG_AVG : public Tag
{
public:
	AGG_AVG(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType()
	{
		return 4;
	}
	vector<double> calculate(vector<double> values)
	{
		if (values.size() != 0)
		{
			vector<double> average;
			double sum = 0;
			if (values.size() != 0)
			{
				for (double number : values)
				{
					sum += number;
				}
			}
			average.push_back(sum / values.size());
			return average;
		}
		return values;
	}
};