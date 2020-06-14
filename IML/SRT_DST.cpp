#include "pch.h"
#include "SRT_DST.h"

const int SRT_DST::getType()
{
	return 10;
}

vector<double> SRT_DST::calculate(vector<double> values)
{
	for (size_t i = 0; i < values.size(); i++)
	{
		removeDublicates(values[i], values, i);
	}
	return values;
}

void SRT_DST::removeDublicates(double number, vector<double> &values, size_t index)
{
	for (size_t i = index + 1; i < values.size(); i++)
	{
		if (values[i] == number)
		{
			values.erase(values.begin() + i, values.begin() + i + 1);
			i--;
		}
	}
}