#pragma once
#include "pch.h"
#include "Tag.h"

class NUM : public Tag
{
public:
	NUM(double number, const bool isCloseTag = false);
	virtual const int getType();
	vector<double> calculate(vector<double> values);
private:
	double number;
};