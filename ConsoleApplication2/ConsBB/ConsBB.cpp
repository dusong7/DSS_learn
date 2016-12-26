// ConsBB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

#define NoEdge           1000

struct MinHeapNode
{
	int lcost; //�������õ��½�
	int cc; //��ǰ����
	int rcost; //x[s:n-1]�ж�����С���߷��ú�
	int s; //���ڵ㵽��ǰ�ڵ��·��Ϊx[0:s]
	int *x; //��Ҫ��һ�������Ķ�����//x[s+1:n-1]
	struct MinHeapNode *next;
};

int n; //ͼG�Ķ�����
int **a; //ͼG���ڽӾ���
		 //int   NoEdge;   //ͼG���ޱ߱��
int cc; //��ǰ����
int bestc; //��ǰ��С����
MinHeapNode* head = 0; /*��ͷ*/
MinHeapNode* lq = 0; /*�ѵ�һ��Ԫ��*/
MinHeapNode* fq = 0; /*�����һ��Ԫ��*/

int DeleteMin(MinHeapNode*&E)
{
	MinHeapNode* tmp = NULL;
	tmp = fq;
	// w = fq->weight ;
	E = fq;
	if (E == NULL)
		return 0;
	head->next = fq->next; /*һ�����ܶ�������ͷ*/
	fq = fq->next;
	// free(tmp) ;
	return 0;
}

int Insert(MinHeapNode* hn)
{
	if (head->next == NULL)
	{
		head->next = hn; //��Ԫ�ط���������
		fq = lq = head->next; //һ��ҪʹԪ�طŵ�����
	}
	else
	{
		MinHeapNode *tmp = NULL;
		tmp = fq;
		if (tmp->cc > hn->cc)
		{
			hn->next = tmp;
			head->next = hn;
			fq = head->next; /*����ֻ��һ��Ԫ�ص����*/
		}
		else
		{
			for (; tmp != NULL;)
			{
				if (tmp->next != NULL && tmp->cc > hn->cc)
				{
					hn->next = tmp->next;
					tmp->next = hn;
					break;
				}
				tmp = tmp->next;
			}
		}
		if (tmp == NULL)
		{
			lq->next = hn;
			lq = lq->next;
		}
	}
	return 0;
}

int BBTSP(int v[])
{//�������ۻ�Ա��������ȶ���ʽ��֧�޽編

 /*��ʼ�����Ŷ��е�ͷ���*/
	head = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	head->cc = 0;
	head->x = 0;
	head->lcost = 0;
	head->next = NULL;
	head->rcost = 0;
	head->s = 0;
	int *MinOut = new int[n + 1]; /*���嶨��i����С���߷���*/
								  //����MinOut[i]=����i����С���߷���
	int MinSum = 0;//��С���߷����ܺ�
	for (int i = 1; i <= n; i++)
	{
		int Min = NoEdge; /*���嵱ǰ��Сֵ*/
		for (int j = 1; j <= n; j++)
			if (a[i][j] != NoEdge && /*������i,j֮����ڻ�·ʱ*/
				(a[i][j] < Min || Min == NoEdge)) /*������i,j֮��ľ���С��Min*/
				Min = a[i][j]; /*���µ�ǰ��Сֵ*/
		if (Min == NoEdge)
			return NoEdge;//�޻�·
		MinOut[i] = Min;
		//printf("%d\n",MinOut[i]);/*����i����С���߷���*/
		MinSum += Min;
		// printf("%d\n",MinSum); /*��С���߷��õ��ܺ�*/
	}

	MinHeapNode *E = 0;
	E = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	E->x = new int[n];
	// E.x=new int[n];
	for (int i = 0; i < n; i++)
		E->x[i] = i + 1;
	E->s = 0;
	E->cc = 0;
	E->rcost = MinSum;
	E->next = 0; //��ʼ����ǰ��չ�ڵ�
	int bestc = NoEdge; /*��¼��ǰ��Сֵ*/
						//�������пռ���
	while (E->s < n - 1)
	{//��Ҷ���
		if (E->s == n - 2)
		{//��ǰ��չ�����Ҷ���ĸ����
		 /*
		 ���ȿ���s=n-2�����Σ���ʱ��ǰ��չ�������������ĳ��Ҷ���ĸ���㡣�����Ҷ�����Ӧһ�����л�·
		 �ҷ���С�ڵ�ǰ��С���ã��򽫸�Ҷ�����뵽���ȶ����У�������ȥ��Ҷ���
		 */
			if (a[E->x[n - 2]][E->x[n - 1]] != NoEdge && /*��ǰҪ��չ��Ҷ�ڵ��бߴ���*/
				a[E->x[n - 1]][1] != NoEdge && /*��ǰҳ�ڵ��л�·*/
				(E->cc + a[E->x[n - 2]][E->x[n - 1]] + a[E->x[n - 1]][1] < bestc /*�ýڵ���Ӧ����С����С����*/
					|| bestc == NoEdge))
			{
				bestc = E->cc + a[E->x[n - 2]][E->x[n - 1]] + a[E->x[n - 1]][1]; /*���µ�ǰ���·���*/
				E->cc = bestc;
				E->lcost = bestc;
				E->s++;
				E->next = NULL;
				Insert(E); /*����ҳ�ڵ���뵽���ȶ�����*/
			}
			else
				free(E->x);//��ҳ�ڵ㲻��������������չ��� 
		}
		else
		{/*������ǰ��չ���Ķ��ӽ��
		 ��s<n-2ʱ���㷨���β�����ǰ��չ�������ж��ӽ�㡣���ڵ�ǰ��չ�������Ӧ��·����x[0:s]��
		 ����ж��ӽ���Ǵ�ʣ�ඥ��x[s+1:n-1]��ѡȡ�Ķ���x[i]����(x[s]��x[i])����������ͼG�е�һ���ߡ�
		 ���ڵ�ǰ��չ����ÿһ�����ж��ӽ�㣬�������ǰ׺(x[0:s]��x[i])�ķ���cc����Ӧ���½�lcost��
		 ��lcost<bestcʱ����������ж��ӽ����뵽�������ȶ����С�*/
			for (int i = E->s + 1; i < n; i++)
				if (a[E->x[E->s]][E->x[i]] != NoEdge)
				{ /*��ǰ��չ�ڵ㵽�����ڵ��бߴ���*/
				  //���ж��ӽ��
					int cc = E->cc + a[E->x[E->s]][E->x[i]]; /*���Ͻڵ�i��ǰ�ڵ�·��*/
					int rcost = E->rcost - MinOut[E->x[E->s]]; /*ʣ��ڵ�ĺ�*/
					int b = cc + rcost; //�½�
					if (b < bestc || bestc == NoEdge)
					{//�������ܺ����Ž�,��������С��
						MinHeapNode * N;
						N = (MinHeapNode*)malloc(sizeof(MinHeapNode));
						N->x = new int[n];
						for (int j = 0; j < n; j++)
							N->x[j] = E->x[j];
						N->x[E->s + 1] = E->x[i];
						N->x[i] = E->x[E->s + 1];/*��ӵ�ǰ·��*/
						N->cc = cc; /*���µ�ǰ·������*/
						N->s = E->s + 1; /*���µ�ǰ�ڵ�*/
						N->lcost = b; /*���µ�ǰ�½�*/
						N->rcost = rcost;
						N->next = NULL;
						Insert(N); /*��������ж��ӽ����뵽�������ȶ�����*/
					}
				}
			free(E->x);
		}//��ɽ����չ
		DeleteMin(E);//ȡ��һ��չ���
		if (E == NULL)
			break; //���ѿ�
	}
	if (bestc == NoEdge)
		return NoEdge;//�޻�·
	for (int i = 0; i < n; i++)
		v[i + 1] = E->x[i];//�����Ž⸴�Ƶ�v[1:n]
	while (true)
	{//�ͷ���С�������н��
		free(E->x);
		DeleteMin(E);
		if (E == NULL)
			break;
	}
	return bestc;
}

int main()
{
	n = 0;
	int i = 0;
	//FILE *in, *out;
	//in = fopen("input.txt", "r");
	//out = fopen("output.txt", "w");
	//if(in == NULL || out == NULL)
	//{
	//	printf("û����������ļ�\n");
	//	return 1;
	//}
	//fscanf(in, "%d", &n);
	n = 5;
	a = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 1; i <= n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	// 	for(i = 1; i <= n; i++)
	// 		for(int j = 1; j <= n; j++)
	// 			//fscanf(in, "%d", &a[i][j]);
	// 			a[i][j]=1;
	a[1][1] = 0;
	a[1][2] = 5;
	a[1][3] = 8;
	a[1][4] = 5;
	a[1][5] = 4;

	a[2][1] = 5;
	a[2][2] = 0;
	a[2][3] = 5;
	a[2][4] = 6;
	a[2][5] = 3;

	a[3][1] = 8;
	a[3][2] = 5;
	a[3][3] = 0;
	a[3][4] = 5;
	a[3][5] = 4;

	a[4][1] = 5;
	a[4][2] = 6;
	a[4][3] = 6;
	a[4][4] = 0;
	a[4][5] = 3;

	a[5][1] = 4;
	a[5][2] = 3;
	a[5][3] = 4;
	a[5][4] = 3;
	a[5][5] = 0;

	// prev = (int*)malloc(sizeof(int)*(n+1)) ;
	int*v = (int*)malloc(sizeof(int) * (n + 1));// MaxLoading(w , c , n) ;
	for (i = 1; i <= n; i++)
		v[i] = 0;
	bestc = BBTSP(v);

	printf("\n");
	for (i = 1; i <= n; i++)
		fprintf(stdout, "%d\t", v[i]);
	fprintf(stdout, "\n");
	fprintf(stdout, "%d\n", bestc);
	return 0;
}

//
//#include"stdlib.h"
//#include <iostream>
//using namespace std;
//
////��������֮���·������
//int CityVal[4][4] = {
//	{ 0 ,30,6,4 },
//	{ 30,0 ,5,10 },
//	{ 6,5,0 ,20 },
//	{ 4,10,20 ,0 } };
//
//struct CityNum {
//	int MinVal[2];       //���·������
//	int PastCity[2][4]; //�߹���·��
//}city[4];
//
//int find(int j, int k, int boolnum)
//{
//	int i;
//	for (i = 0; i<4; i++)
//		if (j == city[k].PastCity[boolnum][i])
//			return 1;
//	return 0;
//}
//void copy(int k, int boolnum1, int j, int boolnum2)
//{
//	int i = 0;
//	while (city[k].PastCity[boolnum1][i] != 0)
//	{
//		city[j].PastCity[boolnum2][i] = city[k].PastCity[boolnum1][i];
//		i++;
//	}
//	city[j].PastCity[boolnum2][i] = k;
//}
//
//
//
//int main()
//{
//	int i, j, k;
//	int boolnum = 0;
//	int TempMinVal;
//	int TempCity;
//	int TempVal;
//	for (i = 0; i<2; i++)
//		for (j = 0; j<4; j++)
//			for (k = 0; k<4; k++)
//				city[k].PastCity[i][j] = 0;
//	for (i = 1; i<4; i++)
//		city[i].MinVal[boolnum] = CityVal[i][0];
//	for (i = 0; i<2; i++)
//	{
//		for (j = 1; j<4; j++)
//		{
//			TempMinVal = 32767;
//			for (k = 1; k<4; k++)
//			{
//				if (j != k && !find(j, k, boolnum))
//				{
//					TempVal = CityVal[j][k] + city[k].MinVal[boolnum];
//					if (TempMinVal>TempVal)
//					{
//						TempMinVal = TempVal;
//						TempCity = k;
//					}
//				}
//			}
//			city[j].MinVal[(boolnum + 1) % 2] = TempMinVal;
//			copy(TempCity, boolnum, j, (boolnum + 1) % 2);
//		}
//		boolnum = (boolnum + 1) % 2;
//	}
//	TempMinVal = 32767;
//	for (i = 1; i<4; i++)
//	{
//		TempVal = CityVal[0][i] + city[i].MinVal[boolnum];
//		if (TempMinVal>TempVal)
//		{
//			TempMinVal = TempVal;
//			TempCity = i;
//		}
//	}
//	cout << "��С����Ϊ:" << TempMinVal << endl;
//	cout << "�������·��Ϊ:";
//	cout << 1 << ' ';
//	cout << TempCity + 1 << ' ';
//	for (i = 1; i >= 0; i--)
//		cout << city[TempCity].PastCity[boolnum][i] + 1 << ' ';
//	cout << 1 << endl;
//}