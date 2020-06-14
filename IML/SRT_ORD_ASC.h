#pragma once
#include "pch.h"
#include "Tag.h"
#include "SRT_ORD.h"

class SRT_ORD_ASC : public SRT_ORD
{
public:
	SRT_ORD_ASC(const bool isCloseTag) : SRT_ORD(isCloseTag) {}
	vector<double> calculate(vector<double> values)
	{
		for (size_t i = 0; i < values.size() - 1; i++)
		{
			for (size_t j = 0; j < values.size() - i - 1; j++)
			{
				if (values[j] > values[j + 1])
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