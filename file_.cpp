// ConsoleReadAnd_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string line;

	ifstream in("rand.txt");
	if (in)
	{
		while (getline(in, line))
		{
			//cout << line << endl;
			int num = atoi(line.c_str());
			printf("%d\n", num);
		}
	}
	return 0;
}

