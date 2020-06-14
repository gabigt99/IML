#pragma once
#include "pch.h"
#include <vector>

using namespace std;

struct Token
{
	int type;
	bool closeTag;
	static const int MAP_INC = 0;
	static const int MAP_MLT = 1;
	double Double;
	static const int AGG_SUM = 2;
	static const int AGG_PRO = 3;
	static const int AGG_AVG = 4;
	static const int AGG_FST = 5;
	static const int AGG_LST = 6;
	static const int SRT_REV = 7;
	static const int SRT_ORD_ASC = 8;
	static const int SRT_ORD_DSC = 9;
	static const int SRT_SLC = 10;
	size_t Natural;
	static const int SRT_DST = 11;
	static const int NUM = 12;
	double data;
	vector<double> calculate(vector<double> vec);
	Token(const int type, bool closeTag = false, double Double = 0, size_t Natural = 0, double data = 0);
	vector<Token*> next;
};