#include "pch.h"
#include <iostream>
#include <string>
#include "IML.h"


bool compare(istream& out, istream& expected)
{
	string outs;
	string ex;
	getline(out, outs);
	getline(expected, ex);
	return outs == ex;
}

int main()
{
	const int size = 10;
	const char inFiles[size][10] = { "in1.txt", "in2.txt", "in3.txt", "in4.txt", "in5.txt", "in6.txt", "in7.txt", "in8.txt", "in9.txt", "in10.txt" };
	const char outFiles[size][10] = { "out1.txt", "out2.txt", "out3.txt", "out4.txt", "out5.txt", "out6.txt", "out7.txt", "out8.txt", "out9.txt", "out10.txt" };
	const char expectedFiles[size][10] = { "ex1.txt", "ex2.txt", "ex3.txt", "ex4.txt", "ex5.txt", "ex6.txt", "ex7.txt", "ex8.txt", "ex9.txt", "ex10.txt" };

	for (int i = 0; i < 10; i++)
	{
		ifstream in(inFiles[i]);
		ofstream out(outFiles[i]);
		try
		{
			IML k(in, out);
			k.buildTree();
			k.print(k.calculateTree());
		}
		catch (string str)
		{
			out << str;
		}
		out.close();
		ifstream outin(outFiles[i]);
		ifstream expected(expectedFiles[i]);
		if (compare(outin, expected))
		{
			cout << "The check " << i + 1 << " is valid." << endl;
		}
		else cout << "The check " << i + 1 << " is unvalid." << endl;
	}
}