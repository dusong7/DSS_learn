// ConsoleApplicaQunee.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//n后问题
//八皇后问题

// Queen.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

class Queen {    //类Queen记录解空间中的节点信息
	friend int nQueen(int);
private:
	bool Place(int k);    //剪枝函数
	void Backtrack(int t);    //递归函数
	int n;    //皇后个数
	int *x;    //当前解
	long sum;    //当前可行的方案数
};

int abs(int ab)//求绝对值
{
	return ab>0 ? ab : -ab;
}

bool Queen::Place(int k)    //剪枝函数
{
	printf("%s_%d\n", __FUNCTION__, k);

	for (int j = 1; j<k; j++)
	{
		//剪枝条件：如果在同一行，同一列或者同斜线上
		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
			return false;
	}
	return true;
}

void Queen::Backtrack(int t)    //递归回溯核心
{
	printf("%s_%d\n", __FUNCTION__, t);

	if (t > n)
	{
		printf("Sum_%s_%d\n", __FUNCTION__, sum);
		sum++;    //如果遍历到叶子，说明求出了一个解
	}	
	else
	{
		for (int i = 1; i <= n; i++)
		{
			x[t] = i;
			if (Place(t))
			{
				Backtrack(t + 1); //函数Place为剪枝函数
			}
		}
	}
}


int nQueen(int n)//初始化数据
{
	Queen X;
	X.n = n;
	X.sum = 0;
	int *p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0;
	}
	X.x = p;
	X.Backtrack(1);
	delete[]p;
	return X.sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d", nQueen(4));//传入参数8，即八皇后问题
	return 0;
}
