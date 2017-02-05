// ConsoleApplicaQunee.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

某一行的皇后a[n]不能和之前的皇后a[i]位置有冲突，约束条件为：
a、不在同一列：a[n] != a[i]
b、不在同一行：因为现在是每一行求一个皇后的位置，所以同一行不会有冲突，不需要考虑。
c、不在同一对左角线：a[n]-a[i] != n-i
d、不在同一右对角线：a[n]-a[i] != -(n-i)
条件c和d可以合成：abs(a[n]-a[i]) != abs(n-i)
总结：其实这里用到的就是深度优先搜索的思想，从第一行的皇后一直深入去找第二行、第三行...皇后的位置。其中加上了约束条件Check函数进行“剪枝”。这就是回溯算法的思想：深度优先搜索，遇到不满足的情况就进行回溯。

void Bcktrack(int t) //参数t表示当前递归深度
{
    if(t>n)Output(x); //遍历到解，则将解输出或其他处理
    else
    {
        //f(n,t)和g(n,t)表示当前节点（扩展节点）处未搜索过的子树的起始编号和中指编号
        for(int i=f(n,t);i<=g(n,t);i++)    
        {
            x[t]=h(i);    //h(i)表示当前节点（扩展节点）处x[i]的第i个可选值
            if(Constarint(t)&&Bound(t)) //剪枝函数：约束函数，限界函数
                Bcktrack(t+1);
        }
    }
}
//nºóÎÊÌâ
//°Ë»ÊºóÎÊÌâ

// Queen.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úµã¡£
//

#include "stdafx.h"
#include "stdio.h"

class Queen {    //ÀàQueen¼ÇÂ¼½â¿Õ¼äÖÐµÄ½ÚµãÐÅÏ¢
	friend int nQueen(int);
private:
	bool Place(int k);    //¼ôÖ¦º¯Êý
	void Backtrack(int t);    //µÝ¹éº¯Êý
	int n;    //Queue number
	int *x;    //Cur Solve
	long sum;    //Cur solve resolution number
};

int abs(int ab)//Çó¾ø¶ÔÖµ
{
	return ab>0 ? ab : -ab;
}

bool Queen::Place(int k)    //¼ôÖ¦º¯Êý
{
	//////
	printf("%s k_%d\n", __FUNCTION__, k);

	for (size_t i = 1; i <= n; i++)
	{
		printf("x[%d]_%d\n",i, x[i]);
	}
	/////
	/////
	for (int j = 1; j<k; j++)
	{
		//cut condition , in one line ,/\-| 
		printf("%d_%d_%d_%d\n", abs(k - j), abs(x[j] - x[k]), x[j], x[k]);
		/////
		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
		{
			printf("Hit\n");
			return false;
		}
		/////
	}
	return true;
}

void Queen::Backtrack(int t)    //µÝ¹é»ØËÝºËÐÄ
{
	printf("%s t_%d\n", __FUNCTION__, t);

	if (t > n) //
	{
		printf("Sum _%s_%d\n", __FUNCTION__, sum);
		sum++;    //Get a result.
	}	
	else
	{
		for (int i = 1; i <= n; i++)  // value 8
		{

			printf("t value %d_%d_%d\n", t, n, i);
			x[t] = i;
			for (size_t i = 1; i <= n; i++)
			{
				printf("x[%d]_%d\n", i, x[i]);
			}

			if (Place(t))
			{
				Backtrack(t + 1);  //º¯ÊýPlaceÎª¼ôÖ¦º¯Êý
			}
		}
	}
}

int nQueen(int n)//³õÊ¼»¯Êý¾Ý
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
	printf("%d\n", nQueen(4));//´«Èë²ÎÊý8£¬¼´°Ë»ÊºóÎÊÌâ
	return 0;
}
