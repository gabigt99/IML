#pragma once
#include "pch.h"
#include "Tag.h"

class MAP_MLT : public Tag
{
public:
	MAP_MLT(const bool isCloseTag, const double multiplicateValue = 0);
	virtual const int getType();
	vector<double> calculate(vector<double> values);
private:
	double multiplicateValue;
};