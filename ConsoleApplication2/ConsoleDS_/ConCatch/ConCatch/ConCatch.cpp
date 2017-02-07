// ConCatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	int nNum = 0;
	int Value = 100;
	try
	{

		Value = Value / nNum;
	}
	catch (...)
	{
		printf("Error");
	}

    return 0;
}

