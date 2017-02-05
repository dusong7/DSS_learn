/*
	数据结构类型定义
*/

#define SIZE 100 //静态表容量
typedef int RcdType;

typedef struct{
	RcdType rc;//记录项
	int next;//指针项
}SLNode;

typedef struct{
	SLNode r[SIZE];//记录值
	int length;//长度
}SLinkListType;
