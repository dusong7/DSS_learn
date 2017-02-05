/*
	数据结构类型定义
*/

typedef int ElemType;

typedef struct OLNode{
	int i;//行
	int j;//列
	ElemType e;//数据
	struct OLNode *right;//所在行的后继
	struct OLNode *down;//所在列的后继
}OLNode,*OLink;

typedef struct{
	OLink *rhead;//行头指针
	OLink *chead;//列头指针
	int mu;//稀疏矩阵行数
	int nu;//稀疏矩阵列数
	int tu;//稀疏矩阵非零元素个数
}CrossList;
