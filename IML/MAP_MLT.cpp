#include "pch.h"
#include "MAP_MLT.h"

MAP_MLT::MAP_MLT(const bool isCloseTag, const double multiplicateValue) : Tag(isCloseTag)
{
	this->multiplicateValue = multiplicateValue;
}

const int MAP_MLT::getType()
{
	return 1;
}

vector<double> MAP_MLT::calculate(vector<double> values)
{
	for (double &number : values)
	{
		number = multiplicateValue * number;
	}
	return values;
}
