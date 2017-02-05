/*
	数据结构类型定义
*/

typedef struct{
	char name[20];
	int age;
}ElemType;

typedef struct LNode{
	ElemType data;//链表中的数据
	struct LNode *next;//链表的下一个地址
}LNode,*LinkList;