#pragma once
#include "Tag.h"

class MAP_INC : public Tag
{
public:
	MAP_INC(const bool isCloseTag, const double additiveValue = 0);
	virtual const int getType();
	vector<double> calculate(vector<double> values);
private:
	double additiveValue;
};