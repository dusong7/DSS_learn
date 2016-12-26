// ConsoleDFS_path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[51][51], book[51][51];//a���鴢���ͼ��b��������û���߹�����ֹ�ظ��ߡ�
int n, m, p, q, Min = 99999999;
int Next[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

void dfs(int x, int y, int step)
{
	if (x == p&&y == q)//�����ж��Ƿ񵽴�Ŀ��
	{
		if (step < Min)
			Min = step;
		return;
	}
	for (int k = 0; k <= 3; k++)
	{
		int tx = x + Next[k][0];
		int ty = y + Next[k][1];
		if (tx<1 || tx>n || ty<1 || ty>m)//�Ƿ����
			continue;
		if (a[tx][ty] == 0 && book[tx][ty] == 0)//�Ƿ�Ϊ�ϰ����ظ��߹�
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
	book[startx][starty] = 1;//��ǿ�ʼ�ĵ㡣
	dfs(startx, starty, 0);//ע���Ǵ�0��ʼ��
	printf("%d\n", Min);

	getchar();
	return 0;
}


