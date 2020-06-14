#include "pch.h"
#include "Token.h"

//using namespace std;

vector<double> funcMAP_INC(double n, vector<double> vec)
{
	for (double &x : vec)
	{
		x = n + x;
	}
	return vec;
}
vector<double> funcMAP_MLT(double n, vector<double> vec)
{
	for (double &x : vec)
	{
		x = n * x;
	}
	return vec;
}

vector<double> funcAGG_SUM(vector<double> vec)
{
	if (vec.size() != 0)
	{
		vector<double> newv;
		double sum = 0;
		for (double x : vec)
		{
			sum += x;
		}
		newv.push_back(sum);
		return newv;
	}
	return vec;//връщам празния вектор
}

vector<double> funcAGG_PRO(vector<double> vec)
{
	if (vec.size() != 0)
	{
		vector<double> newv;
		double pro = 1;
		for (double x : vec)
		{
			pro *= x;
		}
		newv.push_back(pro);
		return newv;
	}
	return vec;//връщам празния вектор
}

vector<double> funcAGG_AVG(vector<double> vec)
{
	if (vec.size() != 0)
	{
		vector<double> sum = funcAGG_SUM(vec);
		sum[0] = sum[0] / vec.size();
		return sum;
	}
	return vec;//връщам празния вектор
}

vector<double> funcAGG_FST(vector<double> vec)
{
	if (vec.size() != 0)
	{
		vector<double> newv;
		newv.push_back(vec[0]);
		return newv;
	}
	return vec;//връщам празния вектор
}

vector<double> funcAGG_LST(vector<double> vec)
{
	if (vec.size() != 0)
	{
		vector<double> newv;
		newv.push_back(vec[vec.size() - 1]);
		return newv;
	}
	return vec;//връщам празния вектор
}

vector<double> funcSRT_REV(vector<double> vec)
{
	for (size_t i = 0; i < vec.size() / 2; i++)
	{
		double d = vec[i];
		vec[i] = vec[vec.size() - i - 1];
		vec[vec.size() - i - 1] = d;
	}
	return vec;
}

vector<double> funcSRT_ORD_ASC(vector<double> vec)
{
	for (size_t i = 0; i < vec.size() - 1; i++)
	{
		for (size_t j = 0; j < vec.size() - i - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				double d = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = d;
			}
		}
	}
	return vec;
}

vector<double> funcSRT_ORD_DSC(vector<double> vec)
{
	for (size_t i = 0; i < vec.size() - 1; i++)
	{
		for (size_t j = 0; j < vec.size() - i - 1; j++)
		{
			if (vec[j] < vec[j + 1])
			{
				double d = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = d;
			}
		}
	}
	return vec;
}

vector<double> funcSRT_SLC(size_t Natural, vector<double> vec)
{
	if (Natural < vec.size())
	{
		vec.erase(vec.begin(), vec.begin() + Natural);
	}
	return vec;
}

void remove(double x, vector<double> &vec, size_t index)
{
	for (size_t i = index + 1; i < vec.size(); i++)
	{
		if (vec[i] == x)
		{
			vec.erase(vec.begin() + i, vec.begin() + i + 1);
			i--;
		}
	}
}

vector<double> funcSRT_DST(vector<double> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		remove(vec[i], vec, i);
	}
	return vec;
}

vector<double> Token::calculate(vector<double> vec)
{
	if (type == MAP_INC)
	{
		return funcMAP_INC(Double, vec);
	}
	if (type == MAP_MLT)
	{
		return funcMAP_MLT(Double, vec);
	}
	if (type == AGG_SUM)
	{
		return funcAGG_SUM(vec);
	}
	if (type == AGG_PRO)
	{
		return funcAGG_PRO(vec);
	}
	if (type == AGG_AVG)
	{
		return funcAGG_AVG(vec);
	}
	if (type == AGG_FST)
	{
		return funcAGG_FST(vec);
	}
	if (type == AGG_LST)
	{
		return funcAGG_LST(vec);
	}
	if (type == SRT_REV)
	{
		return funcSRT_REV(vec);
	}
	if (type == SRT_ORD_ASC)
	{
		return funcSRT_ORD_ASC(vec);
	}
	if (type == SRT_ORD_DSC)
	{
		return funcSRT_ORD_DSC(vec);
	}
	if (type == SRT_SLC)
	{
		return funcSRT_SLC(Natural ,vec);
	}
	return funcSRT_DST(vec);
}

Token::Token(const int type, bool closeTag, double Double, size_t Natural, double data)
{
	this->type = type;
	this->closeTag = closeTag;
	this->Double = Double;
	this->Natural = Natural;
	this->data = data;
}
