// ConsoleDFS_path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[51][51], book[51][51];//a数组储存地图，b数组标记有没有走过，防止重复走。
int n, m, p, q, Min = 99999999;
int Next[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

void dfs(int x, int y, int step)
{
	if (x == p&&y == q)//首先判断是否到达目标
	{
		if (step < Min)
			Min = step;
		return;
	}
	for (int k = 0; k <= 3; k++)
	{
		int tx = x + Next[k][0];
		int ty = y + Next[k][1];
		if (tx<1 || tx>n || ty<1 || ty>m)//是否出界
			continue;
		if (a[tx][ty] == 0 && book[tx][ty] == 0)//是否为障碍和重复走过
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}

int main()
{
	int startx, starty;
	memset(book, 0, sizeof(book));
	printf("Please Inout c and l\n");
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			printf("Input %d,%d value\n",i,j);
			scanf_s("%d", &a[i][j]);
		}
	printf("Start Point, and target point\n");
	scanf_s("%d%d%d%d", &startx, &starty, &p, &q);
	book[startx][starty] = 1;//标记开始的点。
	dfs(startx, starty, 0);//注意是从0开始。
	printf("%d\n", Min);

	getchar();
	return 0;
}


