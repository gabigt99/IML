#pragma once
#include "pch.h"
#include "Tag.h"

class SRT_REV : public Tag
{
public:
	SRT_REV(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType()
	{
		return 7;
	}
	vector<double> calculate(vector<double> values)
	{
		for (size_t i = 0; i < values.size() / 2; i++)
		{
			double copy = values[i];
			values[i] = values[values.size() - i - 1];
			values[values.size() - i - 1] = copy;
		}
		return values;
	}
};