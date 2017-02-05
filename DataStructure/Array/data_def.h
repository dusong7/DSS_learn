/*
	数据结构类型定义
*/

#define MAX_ARRAY_DIM 8//变长数组 最大值

typedef int ElemType;

typedef struct{
	ElemType *base;
	int	     dim;//数组长度
	int      *bounds;//数组界基址
	int	     *constans;//数组映像函数常量基址
}Array;

