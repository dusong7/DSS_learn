// ConsoleBD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int array[100];
	int m = 4;
	for (size_t i = 0; i < 4; i++)
	{
		scanf_s("%d", &array[i + 1]);
	}

	for (size_t i = 0; i < 3; i++)
	{
		int b;
		scanf_s("%d", &b);
		int cur = 0;
		for (size_t i = 1; i <= m; i++)
		{
			if (b == array[i])
			{
				cur = i;
			}
		}

		if (cur != 0)
		{
			for (size_t i = cur; i < m; i++)
			{
				array[i] = array[i + 1];
			}
			m--;
		}
		else
		{
			array[++m] = b;
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		printf("%d\t", array[i + 1]);
	}
	return 0;
}

