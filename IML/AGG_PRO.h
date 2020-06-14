#pragma once
#include "pch.h"
#include "Tag.h"

class AGG_PRO : public Tag
{
public:
	AGG_PRO(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType()
	{
		return 3;
	}
	vector<double> calculate(vector<double> values)
	{
		if (values.size() != 0)
		{
			vector<double> product;
			product.push_back(1);
			for (double number : values)
			{
				product[0] *= number;
			}
			return product;
		}
		return values;
	}
};