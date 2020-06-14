#pragma once
#include "pch.h"
#include "Tag.h"

class SRT_ORD_DSC : public SRT_ORD
{
public:
	SRT_ORD_DSC(const bool isCloseTag) : SRT_ORD(isCloseTag) {}
	vector<double> calculate(vector<double> values)
	{
		for (size_t i = 0; i < values.size() - 1; i++)
		{
			for (size_t j = 0; j < values.size() - i - 1; j++)
			{
				if (values[j] < values[j + 1])
				{
					double copy = values[j];
					values[j] = values[j + 1];
					values[j + 1] = copy;
				}
			}
		}
		return values;
	}
};