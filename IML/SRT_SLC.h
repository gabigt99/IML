#pragma once
#include "pch.h"
#include "Tag.h"

class SRT_SLC : public Tag
{
public:
	SRT_SLC(const bool isCloseTag, const size_t position = 0);
	virtual const int getType();
	vector<double> calculate(vector<double> values);
private:
	size_t position;
};