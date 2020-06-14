#include "pch.h"
#include "MAP_INC.h"

MAP_INC::MAP_INC(const bool isCloseTag, const double additiveValue) : Tag(isCloseTag)
{
	this->additiveValue = additiveValue;
}

const int MAP_INC::getType()
{
	return 0;
}

vector<double> MAP_INC::calculate(vector<double> values)
{
	for (double &number : values)
	{
		number = additiveValue + number;
	}
	return values;
}
