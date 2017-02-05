/*
	数据结构类型定义
*/

typedef int ElemType;

#define MAXSIZE 12500 //设置非零元素的最大值
typedef struct{
	int i,j;//非零元素的下标
	ElemType e;
}Trilpe;

typedef struct{
	Trilpe data[MAXSIZE + 1];//非零元三元组表 Data[0]未使用
	int mu;//矩阵行数
	int nu;//矩阵列数
	int tu;//矩阵非零元素个数
}TSMatrix;

#define MAXRC 1000

typedef struct{
	Trilpe data[MAXSIZE+1];//非零元素组
	int rpos[MAXRC+1];//各行第一个非零元的位置表
	int mu;//矩阵行数
	int nu;//矩阵列数
	int tu;//矩阵非零元素个数
}RLSMatrix;


