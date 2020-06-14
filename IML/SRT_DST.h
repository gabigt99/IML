#pragma once
#include "pch.h"
#include "Tag.h"

class SRT_DST : public Tag
{
public:
	SRT_DST(const bool isCloseTag) : Tag(isCloseTag) {}
	virtual const int getType();
	vector<double> calculate(vector<double> values);
private:
	void removeDublicates(double number, vector<double> &values, size_t index);
};