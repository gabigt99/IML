#include "pch.h"
#include "SRT_SLC.h"

SRT_SLC::SRT_SLC(const bool isCloseTag, const size_t position) : Tag(isCloseTag)
{
	this->position = position;
}

const int SRT_SLC::getType()
{
	return 9;
}

vector<double> SRT_SLC::calculate(vector<double> values)
{
	if (position < values.size())
	{
		values.erase(values.begin(), values.begin() + position);
	}
	else
	{
		values.clear();
	}
	return values;
}